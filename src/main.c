/*
DSA Group Assignment
Kavindu -->
Sasmi -->
Hasindu -->
Wathsalya -->
Gimhana -->
Parichitha -->
Nimsara -->

<--NOTE-->

    while (getchar() != '\n'); is used to clear the "\n" in the buffer after using scanf.

    i added support for MAKEFILE. you can download make and simply run make run in the terminal.

    on windows:
        1)download winget: https://winget.run
        2)Open powershell as admin
        3)run this command--> winget install GnuWin32.Make
        4)C:\Program Files (x86)\GnuWin32\bin Add this path as an enviormental variable
        5)you are good to goo.open the terminal and navigate to the project root folder and run following command
                --> make run

    on mac:
        1)open terminal and run the following code
            --> xcode-select --install
        2)Navigate to the project root folder
        3)then enter this command
        --> make

    if you dont want to use make you can simply use
    --> gcc src.c -I include -o gamestore
    --> .\gamestore

    **Priority queue implementation is not finished.but the logic is there.**

*/
// implement download duplicate logic ( )

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

// MODULE header files
#include "common.h"
#include "navigation.h"
#include "catalog.h"
#include "cart.h"
#include "download.h"
#include "library.h"
#include "wishlist.h"
#include "support.h"

// helper functions for menus
void show_main_menu(); // to display the main menu

// wishlist
void handle_wishlist_menu(Wishlist *wishList, Cart *cart, Library *lib, NavStack *nav, Catalog *catalog);
void display_wishlsit(Wishlist *wishlist);

// downloads
void display_downloads(DownloadQueue *dq);
void handle_downloads_menu(DownloadQueue *dq, NavStack *nav);

// library
void handle_library_menu(Library *lib, DownloadQueue *dq, NavStack *nav);
void display_library(Library *lib);

// catalog
void handle_catalog_menu(Catalog *catalog, Cart *cart, NavStack *nav, Wishlist *wishlist);
void display_catalog(Catalog *catalog);

// cart
void handle_cart_menu(Cart *cart, Catalog *catalog, Library *lib, NavStack *nav);
void display_cart_menu(Cart *cart);

// support
void handle_support_menu(priorityQueue *q, NavStack *nav);
void display_support(priorityQueue *q);

int main()
{
    // initialize all sub systems
    NavStack nav;
    nav_init(&nav);
    nav_push(&nav, PAGE_MAIN_MENU);

    Catalog catalog;
    catalog_init(&catalog);

    Cart cart;
    cart_init(&cart);

    DownloadQueue dQueue;
    download_init_queue(&dQueue);

    Library library;
    lib_init(&library);

    Wishlist wishList;
    wishlist_init(&wishList);

    priorityQueue pQueue;
    support_queue_initialize(&pQueue);

    int running = 1;   // when exiting the program, running is set to 0 so the loop ends.
    int userInput = 7; // enum of the PAGE_MAIN_MENU is 7.that is why we use 7 here,so the program starts with the main menu.

    // main loop
    while (running && !nav_is_empty(&nav))
    {
        Page currentPage = nav_peek(&nav);
        switch (currentPage)
        {
        case PAGE_MAIN_MENU:
            system("cls");
            show_main_menu();
            if (scanf("%d", &userInput) != 1)
            {
                while (getchar() != '\n')
                    ;
                userInput = -1;
            }

            // push new pages to the stack
            switch (userInput)
            {
            case 1:
                nav_push(&nav, PAGE_CATALOG);
                break;
            case 2:
                nav_push(&nav, PAGE_CART);
                break;
            case 3:
                nav_push(&nav, PAGE_LIBRARY);
                break;
            case 4:
                nav_push(&nav, PAGE_DOWNLOAD);
                break;
            case 5:
                nav_push(&nav, PAGE_WISHLIST);
                break;
            case 6:
                nav_push(&nav, PAGE_SUPPORT);
                break;
            case 0:
                running = 0;
                break;
            default:
                printf("\nInvalid choice!\n");
                Sleep(1000);
                break;
            }

            break;
        case PAGE_CATALOG:
            handle_catalog_menu(&catalog, &cart, &nav, &wishList);
            break;
        case PAGE_CART:
            handle_cart_menu(&cart, &catalog, &library, &nav);
            break;
        case PAGE_LIBRARY:
            handle_library_menu(&library, &dQueue, &nav);
            break;
        case PAGE_DOWNLOAD:
            handle_downloads_menu(&dQueue, &nav);
            break;
        case PAGE_WISHLIST:
            handle_wishlist_menu(&wishList, &cart, &library, &nav, &catalog);
            break;
        case PAGE_SUPPORT:
            handle_support_menu(&pQueue, &nav);
            break;
        case PAGE_EXIT:
            running = 0;
            break;
        default:
            printf("\nInvalid choice! Try again.\n");
            Sleep(1500);
            break;
        }
    }

    // free memory
    catalog_destroy(&catalog);
    cart_destroy(&cart);
    lib_destroy(&library);
    download_queue_destroy(&dQueue);
    wishlist_destroy(&wishList);
    support_queue_destroy(&pQueue);
    nav_destroy(&nav);

    return 0;
}
void show_main_menu()
{

    printf("==================================================\n");
    printf("                 GAME STORE\n");
    printf("==================================================\n");
    printf("Welcome, Player!\n\n");
    printf("[1] Browse Catalog\n");
    printf("[2] View Cart\n");
    printf("[3] Library\n");
    printf("[4] Downloads\n");
    printf("[5] Wishlist\n");
    printf("[6] Support\n");
    printf("[0] Exit\n\n");
    printf("--------------------------------------------------\n");
    printf("Enter your choice: ");
}

void handle_catalog_menu(Catalog *catalog, Cart *cart, NavStack *nav, Wishlist *wishlist)
{
    int option = 0;

    system("cls");
    printf("\n=== CATALOG ===\n");
    printf("1. Display Catalog\n");
    printf("2. Sort Catalog By Rating\n");
    printf("3. Sort Catalog By Price\n");
    printf("4. Add Game to Library\n");
    printf("5. Add Game to WishList\n");
    printf("0. Return to Main Menu\n\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1)
    {
        while (getchar() != '\n')
            ;
        option = -1;
    }

    switch (option)
    {
    case 1:
        display_catalog(catalog); // Display catalog games
        system("pause");
        break;
    case 2: // sort by rating
        catalog_sort_by_rating(catalog);
        display_catalog(catalog);
        system("pause");
        break;

    case 3: // sort by price
        catalog_sort_by_price(catalog);
        display_catalog(catalog);
        system("pause");
        break;

    case 4: // Add a game from Catalog to cart
    {
        display_catalog(catalog);
        printf("\nEnter Game ID to Add to Cart: ");
        int gameID;
        scanf("%d", &gameID);
        Game *game = catalog_search_by_id(catalog, gameID);

        if (game == NULL)
        {
            printf("\nGame not found in Catalog!\n");
        }
        else
        {
            cart_add_game(cart, game);
            printf("\nGame added to Cart successfully!\n");
        }
        system("pause");
        break;
    }
    case 5:
    {
        int gameID = 0;
        display_catalog(catalog);
        printf("\nEnter Game ID to Add to The WishList: ");
        scanf("%d", &gameID);
        while (getchar() != '\n')
            ;
        option = -1;
        Game *game = catalog_search_by_id(catalog, gameID);
        if (game != NULL)
            if (wishlist_search_game_by_id(wishlist, gameID) != NULL)
            {
                printf("\n%s is already in your Wishlist!\n", game->title);
            }
            else
            {
                wishlist_insert_new_item(wishlist, game);
                printf("\n%s Added to the Wishlist.\n", game->title);
            }
        else
        {
            printf("Invalid Game ID(%d)", gameID);
        }
        break;
    }
    case 0:
        nav_pop(nav);
        return; // Back to main menu

    default:
        printf("\nInvalid choice! Try again.\n");
        Sleep(1500);
        break;
    }
}

void display_catalog(Catalog *catalog)
{
    printf("\n=== CATALOG ===\n");
    printf("Total games available: %d\n", catalog->gameCount);

    printf("%-5s | %-25s | %-10s | %-5s\n", "ID", "Game Title", "Price ($)", "Rating");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < catalog->gameCount; i++)
    {
        printf("%-5d | %-25s | %-10.2f | %.1f/5.0\n",
               catalog->games[i].gameID,
               catalog->games[i].title,
               catalog->games[i].price,
               catalog->games[i].rating);
    }
}

void display_downloads(DownloadQueue *dq)
{
    printf("\n==================================================\n");
    printf("                 DOWNLOAD MANAGER\n");
    printf("==================================================\n");

    if (download_is_empty(dq))
    {
        printf("\nNo games are currently in the download queue.\n\n");
        return;
    }

    DownloadNode *current = dq->front;
    int position = 1;

    printf("%-3s | %-25s | %-10s | %-12s\n", "No.", "Game Title", "Size (GB)", "Status");
    printf("------------------------------------------------------------\n");

    while (current != NULL)
    {
        const char *statusStr = (current->status == PENDING) ? "PENDING" : (current->status == DOWNLOADING) ? "DOWNLOADING"
                                                                                                            : "COMPLETED";

        printf("%-3d | %-25s | %-10.2f | %-12s\n",
               position, current->game.title, current->game.size, statusStr);

        current = current->next;
        position++;
    }
    printf("\n");
}

void handle_downloads_menu(DownloadQueue *dq, NavStack *nav)
{
    int option;
    system("cls");
    printf("\n=== Downloads ===\n");
    printf("1. View Queue\n");
    printf("2. Remove Game from Downloads (by ID)\n");
    printf("3. Download Games\n");
    printf("0. Return to Main Menu\n\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1)
    {
        while (getchar() != '\n')
            ;
        option = -1;
    }

    switch (option)
    {
    case 1:
        display_downloads(dq);
        system("pause");
        break;
    case 2:
        if (download_is_empty(dq))
        {
            printf("Download queue is empty.");
            break;
        }
        else
        {
            printf("Game removed from downloads queue.(%s)", dq->front->game.title);
            download_dequeue(dq);
        }
        system("pause");
        break;
    case 3:
        if (!download_is_empty(dq))
        {
            Game *currentGame = &dq->front->game;
            printf("Downloading: %s (%.1f GB)\n", currentGame->title, currentGame->size);

            printf("[");
            for (int i = 0; i < 20; i++)
            {
                printf("=");
                Sleep(100);
            }
            printf("] 100%% \n");
            printf("--> %s Installed Successfully.\n\n", currentGame->title);
            download_dequeue(dq);
            Sleep(300);
        }
        else
        {
            printf("\nThe Download queue is empty\n");
        }
        system("pause");
        break;
    case 0:
        nav_pop(nav);
        break;

    default:
        printf("\nInvalid choice! Try again.\n");
        Sleep(1000);
        break;
    }
}

void display_library(Library *lib)
{
    printf("\n==================================================\n");
    printf("                 YOUR LIBRARY\n");
    printf("==================================================\n");

    if (lib->gameCount == 0)
    {
        printf("\nYour library is empty. Go buy some games!\n\n");
        return;
    }

    printf("Games Owned: %d / %d (Capacity)\n\n", lib->gameCount, lib->libCapacity);
    printf("%-5s | %-25s | %-10s | %-5s\n", "ID", "Game Title", "Size (GB)", "Rating");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < lib->gameCount; i++)
    {
        printf("%-5d | %-25s | %-10.2f | %.1f/5.0\n",
               lib->game[i].gameID,
               lib->game[i].title,
               lib->game[i].size,
               lib->game[i].rating);
    }
    printf("\n");
}

void handle_library_menu(Library *lib, DownloadQueue *dq, NavStack *nav)
{
    int option = 0;
    int gameID = 0;
    system("cls");
    printf("\n=== YOUR LIBRARY ===\n");
    printf("1. View Library\n");
    printf("2. Download a Game (Add to Queue)\n");
    printf("3. Remove Game from Library\n");
    printf("0. Return to Main Menu\n\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1)
    {
        while (getchar() != '\n')
            ;
        option = -1;
    }

    switch (option)
    {
    case 1:
        display_library(lib);
        system("pause");
        break;
    case 2:
        display_library(lib);
        if (lib_get_count(lib) > 0)
        {
            printf("Enter the Game ID to Download: ");
            scanf("%d", &gameID);

            if (lib_is_id_contains(lib, gameID))
            {
                Game *downloadGame = lib_get_game_data(lib, gameID);
                if (downloadGame != NULL)
                {
                    download_enqueue(dq, downloadGame);
                    printf("\n %s added to Download Queue.", downloadGame->title);
                }
            }
            else
            {
                printf("\nInvalid Game ID.(%d)\n", gameID);
            }
        }
        system("pause");
        break;
    case 3:
        display_library(lib);
        if (lib_get_count(lib) > 0)
        {
            printf("Enter Game ID to Remove from Library: ");
            scanf("%d", &gameID);

            if (lib_is_id_contains(lib, gameID))
            {
                lib_remove_game_by_id(lib, gameID);
                printf("\nGame removed from the library.\n");
            }
            else
            {
                printf("\nGame not found in your library.\n");
            }
        }
        system("pause");
        break;
    case 0:
        nav_pop(nav);
        break;
    default:
        printf("\nInvalid choice! Try again.\n");
        Sleep(1500);
        break;
    }
}

void display_wishlsit(Wishlist *wishlist)
{
    printf("\n==================================================\n");
    printf("                 YOUR WISHLIST\n");
    printf("==================================================\n");

    if (wishlist == NULL || wishlist->head == NULL)
    {
        printf("\nYour wishlist is currently empty. Go explore the catalog!\n\n");
        return;
    }

    printf("Saved Games: %d\n\n", wishlist->count);
    printf("%-5s | %-25s | %-10s | %-5s\n", "ID", "Game Title", "Price ($)", "Rating");
    printf("------------------------------------------------------------\n");

    WishlistNode *current = wishlist->head;

    while (current != NULL)
    {
        printf("%-5d | %-25s | %-10.2f | %.1f/5.0\n",
               current->game.gameID,
               current->game.title,
               current->game.price,
               current->game.rating);

        current = current->next;
    }
    printf("------------------------------------------------------------\n\n");
}

void handle_wishlist_menu(Wishlist *wishList, Cart *cart, Library *lib, NavStack *nav, Catalog *catalog)
{
    int option = 0;
    int gameID = 0;
    system("cls");

    printf("\n=== CART MENU ===\n");
    printf("1. View Wishlist\n");
    printf("2. Remove Game From Wishlist\n");
    printf("3. Add Game To Cart\n");
    printf("4. Add Game To WishList\n");
    printf("0. Return to Main Menu\n\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1)
    {
        while (getchar() != '\n')
            ;
        option = -1;
    }
    switch (option)
    {
    case 1:
        display_wishlsit(wishList);
        system("pause");
        break;
    case 2:
        display_wishlsit(wishList);
        if (!wishlist_isEmpty(wishList))
        {
            printf("Enter the game ID to remove: ");
            scanf("%d", &gameID);
            // future dev update: check if the id is valid or not before passing it to the function.
            wishlist_remove_item_by_id(wishList, gameID);
            printf("\ngame removed\n");
        }
        system("pause");
        break;
    case 3:
        display_wishlsit(wishList);
        printf("Enter the game ID to Add to The Cart: ");
        scanf("%d", &gameID);

        // Fetch the game from the wishlist
        Game *gameToBuy = wishlist_search_game_by_id(wishList, gameID);

        if (gameToBuy != NULL)
        {
            cart_add_game(cart, gameToBuy);
            printf("\nGame added to cart!\n");
        }
        else
        {
            printf("\nInvalid ID (%d) or game not in wishlist.\n", gameID);
        }
        system("pause");
        break;
    case 4:
    {
        int gameID = 0;
        display_catalog(catalog);
        printf("\nEnter Game ID to Add to The WishList: ");
        scanf("%d", &gameID);
        while (getchar() != '\n')
            ;
        option = -1;
        Game *game = catalog_search_by_id(catalog, gameID);
        if (game != NULL)
            if (wishlist_search_game_by_id(wishList, gameID) != NULL)
            {
                printf("\n%s is already in your Wishlist!\n", game->title);
            }
            else
            {
                wishlist_insert_new_item(wishList, game);
                printf("\n%s Added to the Wishlist.\n", game->title);
            }
        else
        {
            printf("Invalid Game ID(%d)", gameID);
        }
        break;
    }
    case 0:
        nav_pop(nav);
        break;

    default:
        printf("\nInvalid input\n");
        Sleep(1500);
        break;
    }
}

void display_cart_menu(Cart *cart)
{
    printf("\n=== YOUR CART ===\n");
    int count = cart_get_count(cart);

    if (count == 0)
    {
        printf("Your cart is empty.\n\n");
        return;
    }

    printf("Items in cart: %d\n", count);
    printf("%-5s | %-25s | %-10s\n", "ID", "Game Title", "Price ($)");
    printf("------------------------------------------------------------\n");

    CartNode *current = cart_get_items(cart);
    while (current != NULL)
    {
        printf("%-5d | %-25s | %-10.2f\n",
               current->game.gameID,
               current->game.title,
               current->game.price);
        current = current->next;
    }
    printf("------------------------------------------------------------\n");
    printf("Total Price: $%.2f\n\n", cart_get_total_price(cart));
}

void handle_cart_menu(Cart *cart, Catalog *catalog, Library *lib, NavStack *nav)
{
    int option = 0;
    int gameID = 0;

    system("cls");
    printf("\n=== CART MENU ===\n");
    printf("1. View Cart\n");
    printf("2. Add Game to Cart (by ID)\n");
    printf("3. Remove Game from Cart (by ID)\n");
    printf("4. Clear Cart\n");
    printf("5. Checkout\n");
    printf("0. Return to Main Menu\n\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1)
    {
        while (getchar() != '\n')
            ;
        option = -1;
    }

    switch (option)
    {
    case 1:
        display_cart_menu(cart);
        system("pause");
        break;
    case 2:
        display_catalog(catalog);
        printf("\nEnter the game id you want to add: ");
        scanf("%d", &gameID);

        Game *gameToAdd = catalog_search_by_id(catalog, gameID);
        if (gameToAdd != NULL)
        {
            cart_add_game(cart, gameToAdd);
            printf("\nGame added to cart!\n");
        }
        else
        {
            printf("\nInvalid Game ID.\n");
        }
        system("pause");
        break;
    case 3:
        display_cart_menu(cart);
        if (cart_get_count(cart) > 0)
        {
            printf("Enter Game ID to Remove: ");
            scanf("%d", &gameID);
            cart_remove_by_id(cart, gameID);
            printf("\nGame Removed From The Cart.");
        }
        system("pause");
        break;

    case 4:
        cart_clear(cart);
        printf("\nCart cleared successfully!\n");
        system("pause");
        break;

    case 5:

        if (cart_get_count(cart) > 0)
        {
            printf("\nChecking out %d items...\n", cart_get_count(cart));
            printf("Total charged: $%.2f\n", cart_get_total_price(cart));
            CartNode *current = cart_get_items(cart);

            while (current != NULL)
            {
                lib_add_game(lib, &current->game);
                current = current->next;
            }

            cart_clear(cart);
            printf("\nPurchase successful! Thank you.\n");
        }
        else
        {
            printf("\nYour cart is empty. Nothing to checkout!\n");
        }
        system("pause");
        break;

    case 0:
        nav_pop(nav);
        return; // Back to main menu

    default:
        printf("\nInvalid choice! Try again.\n");
        Sleep(1500);
        break;
    }
}

void display_support(priorityQueue *q)
{
    printf("\n==================================================\n");
    printf("                 SUPPORT TICKETS\n");
    printf("==================================================\n");

    if (q == NULL || q->front == NULL)
    {
        printf("\nNo pending support tickets.\n\n");
        return;
    }

    printf("Pending Tickets: %d\n\n", q->count);
    printf("%-10s | %-10s | %-25s\n", "Ticket ID", "Priority", "Issue Title");
    printf("------------------------------------------------------------\n");

    supportNode *current = q->front;

    while (current != NULL)
    {
        printf("%-10d | %-10d | %-25s\n",
               current->ticketId,
               current->priority,
               current->supportTitle);

        current = current->next;
    }
    printf("------------------------------------------------------------\n\n");
}

void handle_support_menu(priorityQueue *q, NavStack *nav)
{
    int option = 0;
    int ticketID = 0;
    int priority = 0;

    char title[MAX_TITLE_LENGHTH];

    system("cls");
    printf("\n=== CUSTOMER SUPPORT ===\n");
    printf("1. View Pending Tickets\n");
    printf("2. Submit a New Ticket\n");
    printf("3. Resolve Highest Priority Ticket (Admin)\n");
    printf("0. Return to Main Menu\n\n");
    printf("Enter your choice: ");

    if (scanf("%d", &option) != 1)
    {
        while (getchar() != '\n')
            ;
        option = -1;
    }

    switch (option)
    {
    case 1:
        display_support(q);
        system("pause");
        break;

    case 2:
        printf("\n--- Submit a Ticket ---\n");

        printf("Enter Ticket ID (Numbers only): ");
        scanf("%d", &ticketID);

        while (getchar() != '\n')
            ;

        printf("Enter Issue Description: ");
        fgets(title, MAX_TITLE_LENGHTH, stdin);

        title[strcspn(title, "\n")] = 0;

        printf("Enter Priority (1 = Critical Bug, 5 = General Question): ");
        scanf("%d", &priority);

        support_queue_submit_ticket(q, ticketID, title, priority);
        printf("\nTicket submitted successfully! It has been placed in the priority queue.\n");

        system("pause");
        break;

    case 3:
        if (q->front == NULL)
        {
            printf("\nNo tickets to resolve\n");
        }
        else
        {
            printf("%-10s | %-10s | %-25s\n", "Ticket ID", "Priority", "Issue Title");
            printf("------------------------------------------------------------\n");
            printf("%-10d | %-10d | %-25s\n",
                   q->front->ticketId,
                   q->front->priority,
                   q->front->supportTitle);
            printf("------------------------------------------------------------\n\n");
            support_queue_resolve_next(q);
        }
        system("pause");
        break;

    case 0:
        nav_pop(nav);
        break;

    default:
        printf("\nInvalid choice! Try again.\n");
        Sleep(1500);
        break;
    }
}
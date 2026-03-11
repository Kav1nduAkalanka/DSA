#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TITLE_LENGTH 100
#define MAX_WISHLIST_SIZE 20

typedef struct Game
{
    int gameID;
    char title[MAX_TITLE_LENGTH];
    float price;
    float rating; // 0.0 to 5.0
    struct Game *next;
} Game;

Game *createNode(int gameID, char title[], float price, float rating)
{
    Game *newGame = (Game *)malloc(sizeof(Game));

    newGame->gameID = gameID;
    strcpy(newGame->title, title);
    newGame->price = price;
    newGame->rating = rating;
    newGame->next = NULL;

    return newGame;
}

// Main Menu
void wishlist_display_main_menu()
{
    printf("\n====WISTLISH MENU====\n");
    printf("1.Display Wishlist\n");
    printf("2.Add Games\n");
    printf("3.Search Wishlist Items\n");
    printf("4.Delete Items\n");
    printf("5.Sort Item\n");
    printf("6.Exit");
}

// Wishlist
void wishlist_display_wislist(struct Game *first)
{
    struct Game *temp;
    temp = first;
    while (temp)
    {
        printf("%d,%s,%.2f,%.1f \n", temp->gameID, temp->title, temp->price, temp->rating);
        temp = temp->next;
    }
}

// Empty or not
bool isEmpty(struct Game *first)
{
    if (first == NULL)
    {
        printf("\nIt is empty list\n");
        return true;
    }
    else
    {
        printf("\nIt is not empty list\n");
        return false;
    }
}

// Insert New Game
void wishlist_insert_new_game(struct Game *first, int gameID, char title[], float price, float rating)
{
    bool list_state = isEmpty(first);
    if (list_state == true)
    {
        printf("\nIt is an empty linked list\n");
        struct Game *newNode = createNode(gameID, title, price, rating);
        first = newNode;
        newNode->gameID = gameID;
        strcpy(newNode->title, title);
        newNode->price = price;
        newNode->rating = rating;
        printf("\nAdded successfully!\n");
    }
    else
    {
        struct Game *temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        struct Game *newNode = createNode(gameID, title, price, rating);
        temp->next = newNode;
        newNode->gameID = gameID;
        strcpy(newNode->title, title);
        newNode->price = price;
        newNode->rating = rating;
        printf("\nAdded successfully!\n");
    }
}

// Search Game from wishlist by using GameID
int wishlist_search_game(struct Game *first, int GameID)
{
    bool list_state = isEmpty(first);
    if (list_state == true)
    {
        printf("It is an empty list");
        return -1;
    }
    else
    {
        struct Game *temp = first;
        while (temp)
        {
            if (temp->gameID == GameID)
            {
                printf("It is in wishlist!");
                return 1;
            }
            else
            {
                printf("It is not in wishlist");
                return -1;
            }
            temp = temp->next;
        }
    }
}

// Delete Game from wishlist by using GameID
int wishlist_delete_game(struct Game *first, int GameID)
{
    if (first == NULL)
    {
        printf("It is an empty list\n");
        return -1;
    }

    struct Game *temp = first;

    while (temp->next != NULL && temp->next->gameID != GameID)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Game not found\n");
        return -1;
    }

    struct Game *deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);

    printf("Delete successfully!\n");
    return 1;
}

// Sort by rating in descending order
void wishlist_sort_by_rating(struct Game *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Game *i, *j;

    for (i = first; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->rating < j->rating) // descending order
            {
                int tempID = i->gameID;
                char tempTitle[100];
                float tempPrice = i->price;
                float tempRating = i->rating;

                strcpy(tempTitle, i->title);

                i->gameID = j->gameID;
                strcpy(i->title, j->title);
                i->price = j->price;
                i->rating = j->rating;

                j->gameID = tempID;
                strcpy(j->title, tempTitle);
                j->price = tempPrice;
                j->rating = tempRating;
            }
        }
    }

    printf("Sorted by rating successfully\n");
}

int main()
{
    char choice;
    Game *first = createNode(1, "Temple Run", 2400.00, 4.5);
    first->next = createNode(2, "Candy Crush", 3508.00, 4);
    first->next->next = createNode(3, "Swiss girl", 1200.00, 4.8);

    wishlist_display_main_menu();
    printf("Enter your choice:(from 1,2,3,4,5");
    scanf("%c", &choice);
    switch (choice)
    {
    case '1':
        wishlist_display_wislist(first);
        break;
    case ('2'):
        wishlist_insert_new_game(first, 4, "COC", 2345.00, 4.9);
        break;
    case ('3'):
        wishlist_search_game(first, 5);
        break;
    case ('4'):
        wishlist_delete_game(first, 2);
        break;
    case ('5'):
        wishlist_sort_by_rating(first);
        break;
    }
}
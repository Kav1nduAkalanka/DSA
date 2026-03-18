#include <stdio.h>
#include "common.h"
#include "catalog.h"
#include "cart.h"
#include "download.h"
#include <stdbool.h>
int main()
{

    Catalog catalog = {0};
    Catalog *ptrCatalog = &catalog;
    catalog_init(ptrCatalog);
    Game *gameArray = catalog_get_game(ptrCatalog);
    catalog_sort_by_rating(ptrCatalog);

    for (int i = 0; i < ptrCatalog->gameCount; i++)
    {
        {
            printf("%s , %.2f\n", gameArray[i].title, gameArray[i].price);
        }
    }

    Game *game1 = catalog_get_game(&catalog);
    Game *game2 = catalog_search_by_id(&catalog, 103);

    Cart playerCart;
    cart_init(&playerCart);
    cart_add_game(&playerCart, game1);
    cart_add_game(&playerCart, game2);

    float price = cart_get_total_price(&playerCart);
    printf("price: %.2f", price);

    DownloadQueue queue = {0};

    download_init_queue(&queue);

    if (download_is_empty(&queue))
    {
        printf("\nqueue is empty\n");
    }

    Game *game3 = catalog_search_by_id(&catalog, 102);
    download_enqueue(&queue, game3);

    if (!download_is_empty(&queue))
    {
        printf("queue is not empty");
    }

    download_peek(&queue);

    return 0;
}
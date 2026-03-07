#include <stdio.h>
#include "common.h"
#include "catalog.h"

int main()
{
    
    Catalog catalog ={0};
    Catalog *ptrCatalog = &catalog;
    catalog_init(ptrCatalog);
    Game *gameArray = catalog_get_game(ptrCatalog);
    catalog_sort_by_rating(ptrCatalog);

    for (int i = 0; i < ptrCatalog->gameCount; i++)
    {
        {
            printf("%s , %.2f\n", gameArray[i].title, gameArray[i].rating);
        }
    }

        return 0;
}
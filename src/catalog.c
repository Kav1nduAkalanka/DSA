#include <stdio.h>
#include "catalog.h"

Game storeCatalog[3];

void catalog_init()
{
    storeCatalog[0] = (Game){1, "abc", 10, 5};
    storeCatalog[1] = (Game){2, "def", 11, 7};
    storeCatalog[2] = (Game){3, "ghi", 12, 3};
}

void catalog_print_games()
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d | %s | %f | %f \n", storeCatalog[i].game_id, storeCatalog[i].title, storeCatalog[i].price, storeCatalog[i].rating);
    }
}

// implement the sorting algorithms
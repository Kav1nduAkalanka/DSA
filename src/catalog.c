#include <stdio.h>
#include "catalog.h"
#include "common.h"

void catalog_add_game(Catalog *catalog, int id, const char *title, float price, float rating, float size)
{
    if (catalog->gameCount >= MAX_CATALOG_SIZE)
    {
        return;
    }

    int index = catalog->gameCount;
    catalog->games[index].gameID = id;
    strcpy(catalog->games[index].title, title);
    catalog->games[index].price = price;
    catalog->games[index].rating = rating;
    catalog->games[index].size = size;
    catalog->gameCount++;
    printf("game added(%d)\n", catalog->gameCount);
}

// initialization of the catalog
void catalog_init(Catalog *catalog)
{
    catalog->gameCount = 0;
    catalog_add_game(catalog, 101, "Red Dead Redemption 2", 59.99, 4.9, 10);
    catalog_add_game(catalog, 102, "Elden Ring", 59.99, 4.8, 11);
    catalog_add_game(catalog, 103, "Metal Gear Solid V: The Phantom Pain", 19.99, 4.7, 5);
    catalog_add_game(catalog, 104, "God of War", 49.99, 4.9, 6);
    catalog_add_game(catalog, 105, "Ghost of Tsushima", 59.99, 4.8, 11.5);
    catalog_add_game(catalog, 106, "Mafia: Definitive Edition", 39.99, 4.5, 9.8);
    catalog_add_game(catalog, 107, "Hollow Knight: Silksong", 29.99, 5.0, 6.5);
    catalog_add_game(catalog, 108, "Arma 3", 29.99, 4.6, 12.5);
    catalog_add_game(catalog, 109, "Call of Duty: Modern Warfare", 59.99, 4.4, 50);
    catalog_add_game(catalog, 110, "Sniper Elite 5", 49.99, 4.3, 60);
    catalog_add_game(catalog, 111, "Insurgency: Sandstorm", 29.99, 4.5, 20);
    catalog_add_game(catalog, 112, "Battlefield 1", 39.99, 4.7, 26.6);
    catalog_add_game(catalog, 113, "Spec Ops: The Line", 29.99, 4.6, 5.5);
    catalog_add_game(catalog, 114, "Tom Clancy's Ghost Recon Wildlands", 49.99, 4.4, 8.6);
    catalog_add_game(catalog, 115, "Hitman 3", 59.99, 4.8, 6.9);
    catalog_add_game(catalog, 116, "Grand Theft Auto V", 29.99, 4.8, 100);
    catalog_add_game(catalog, 117, "Company of Heroes 3", 59.99, 4.2, 12);
    catalog_add_game(catalog, 118, "Sleeping Dogs: Definitive Edition", 19.99, 4.6, 40);
    catalog_add_game(catalog, 119, "Max Payne 3", 19.99, 4.5, 96);
    catalog_add_game(catalog, 120, "Ready or Not", 49.99, 4.7, 50);
}

// returns the memory address of the first game in the array
Game *catalog_get_game(Catalog *catalog)
{
    return catalog->games;
}

void catalog_sort_by_price(Catalog *catalog)
{
    if (catalog == NULL || catalog->games == NULL)
    {
        printf("empty catalog or games");
        return;
    }

    Game *games = catalog->games;
    int count = catalog->gameCount;

    for (int i = 1; i < count; i++)
    {
        Game key = games[i];
        int j = i - 1;

        while (j >= 0 && games[j].price > key.price)
        {
            games[j + 1] = games[j];
            j = j - 1;
        }
        games[j + 1] = key;
    }
}

void catalog_sort_by_rating(Catalog *catalog)
{
    if (catalog == NULL || catalog->games == NULL)
    {
        return;
    }

    Game *games = catalog->games;
    int count = catalog->gameCount;

    for (int i = 1; i < count; i++)
    {
        Game key = games[i];
        int j = i - 1;

        while (j >= 0 && games[j].rating > key.rating)
        {
            games[j + 1] = games[j];
            j = j - 1;
        }
        games[j + 1] = key;
    }
}

Game *catalog_search_by_id(Catalog *catalog, int id)
{
    for (int i = 0; i < catalog->gameCount; i++)
    {
        if (id == catalog->games[i].gameID)
        {
            return &catalog->games[i];
        }
    }
    return NULL;
}

int catalog_get_count(Catalog *catalog)
{
    return catalog->gameCount;
}

void catalog_destroy(Catalog *catalog) {
   
    catalog->gameCount = 0; 
}
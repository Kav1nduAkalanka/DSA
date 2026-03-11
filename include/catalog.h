#ifndef CATALOG_H
#define CATALOG_H
#include "common.h"

typedef struct
{
    Game games[20];
    int gameCount;
} Catalog;

void catalog_init(Catalog *catalog);
Game *catalog_get_game(Catalog *catalog);
void catalog_sort_by_price(Catalog *catalog);
void catalog_sort_by_rating(Catalog *catalog);
Game *catalog_search_by_id(Catalog *catalog,int id);
int catalog_get_count(Catalog *catalog);
void catalog_destroy(Catalog *catalog);
#endif

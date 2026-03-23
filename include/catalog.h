#ifndef CATALOG_H
#define CATALOG_H
#include "common.h"

typedef struct
{
    Game games[20];
    int gameCount;
} Catalog;

void catalog_init(Catalog *catalog); // init db
Game *catalog_get_game(Catalog *catalog); // get node
void catalog_sort_by_price(Catalog *catalog); // auto-sort price
void catalog_sort_by_rating(Catalog *catalog); // auto-sort score
Game *catalog_search_by_id(Catalog *catalog,int id); // fetch query
int catalog_get_count(Catalog *catalog); // get size
void catalog_destroy(Catalog *catalog); // free stack

#endif

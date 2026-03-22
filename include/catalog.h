#ifndef CATALOG_H
#define CATALOG_H
#include "common.h"

typedef struct
{
    Game games[20];
    int gameCount;
} Catalog;

void catalog_init(Catalog *catalog); //initialize the catalog
Game *catalog_get_game(Catalog *catalog); //returns the first game's memory address 
void catalog_sort_by_price(Catalog *catalog); //sorts the catalog by price using insertion sort
void catalog_sort_by_rating(Catalog *catalog); //sorts the catalog by rating using insertion sort
Game *catalog_search_by_id(Catalog *catalog,int id); //searches the catalog by the gameID .if game found returns a pointer to the game if not returns null
int catalog_get_count(Catalog *catalog); // returns the number of games in the  catalog
void catalog_destroy(Catalog *catalog); //free the memory allocated for catalog

#endif

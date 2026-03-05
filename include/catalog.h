#ifndef CATALOG_H
#define CATALOG_H
#include "common.h"

extern Game storeCatalog[3]; // Tell the program there is a catalog array somewhere

void catalog_init();        // initialize the catalog
void catalog_print_games(); // displays the whole catalog
void sort_by_price_low();   // sort the catalog from price low to high
void sort_by_rating_low();  // sort the catalog from ratings low to high

#endif

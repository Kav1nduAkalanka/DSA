#ifndef WISHLIST_H
#define WISHLIST_H
#include <stdio.h>
#include <stdbool.h>
#include "common.h"

typedef struct WishlistNode
{
    Game game;
    struct WishlistNode *next;
} WishlistNode;

typedef struct Wishlist
{
    WishlistNode *head;
    WishlistNode *tail;
    int count;
} Wishlist;

WishlistNode *createNode(Game *game);

void wishlsit_init(Wishlist *wishlist);

void wishlist_display_main_menu();

void wishlist_display_contains(Wishlist *wishlist);

int wishlist_isEmpty(Wishlist *wishlist);

void wishlist_insert_new_item(Wishlist *wishlist, Game *game);

WishlistNode *wishlist_search_game_by_id(Wishlist *wishlist, int ID);

void wishlist_remove_item_by_id(Wishlist *wishlist, int removeID);

void wishlist_destroy(Wishlist *wishlist);

#endif

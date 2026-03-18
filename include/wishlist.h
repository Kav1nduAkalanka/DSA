#ifndef WISHLIST_H
#define WISHLIST_H
#include<stdio.h>
#include<stdbool.h>
#include "common.h"

typedef struct wishlistNode
{
    Game game;
    struct wishlistNode *next;
}wishlistNode;

typedef struct wishlist
{
    wishlistNode *head;
    wishlistNode *tail;
    int count;
}wishlist;

wishlistNode* createNode(Game *game);
void wishlist_display_main_menu();
void wishlist_display_contains(wishlist *wishlist);
int wishlist_isEmpty(wishlist *wishlist);
void wishlist_insert_new_item( wishlist *wishlist,  Game *game);
wishlistNode* wishlist_search_game_by_id(wishlist *wishlist,int ID);
void wishlist_remove_itemb_by_id(wishlist *wishlist, int removeID);


#endif



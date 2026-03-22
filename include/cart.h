#ifndef CART_H
#define CART_H
#include <stdio.h>
#include "common.h"

typedef struct CartNode CartNode;

struct CartNode
{
    Game game;
    CartNode *next;
    CartNode *prev;
};

typedef struct Cart
{
    CartNode *head;
    CartNode *tail;
    int count;
    float totalPrice;
} Cart;



void cart_init(Cart *cart);
void cart_add_game(Cart *cart,Game *game);
void cart_remove_by_id(Cart *cart, int removeID);
float cart_get_total_price(Cart *cart);
int cart_get_count(Cart *cart);
CartNode *cart_get_items(Cart *cart);
void cart_clear(Cart *cart);
void cart_destroy(Cart *cart);

#endif 
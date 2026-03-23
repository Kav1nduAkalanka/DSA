#ifndef CART_H
#define CART_H
#include <stdio.h>
#include "common.h"

typedef struct CartNode CartNode;


// node struct
struct CartNode
{
    Game game;
    CartNode *next;
    CartNode *prev;
};

// dll struct
typedef struct Cart
{
    CartNode *head;
    CartNode *tail;
    int count;
    float totalPrice;
} Cart;



void cart_init(Cart *cart); // init cart
void cart_add_game(Cart *cart,Game *game); // push game
void cart_remove_by_id(Cart *cart, int removeID); // pop by id
float cart_get_total_price(Cart *cart); // get final cost
int cart_get_count(Cart *cart); // get item count
CartNode *cart_get_items(Cart *cart); // iter head
void cart_clear(Cart *cart); // clear cart items
void cart_destroy(Cart *cart); // free array mem

#endif 
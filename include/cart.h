#ifndef CART_H
#define CART_H
#include <stdio.h>
#include "common.h"

typedef struct CartNode CartNode;


//structure of a node
struct CartNode
{
    Game game;
    CartNode *next;
    CartNode *prev;
};

//structure of the cart doubly linked list
typedef struct Cart
{
    CartNode *head;
    CartNode *tail;
    int count;
    float totalPrice;
} Cart;



void cart_init(Cart *cart); //initialize the cart
void cart_add_game(Cart *cart,Game *game); //add a game to a cart
void cart_remove_by_id(Cart *cart, int removeID); //remove a game from cart by id
float cart_get_total_price(Cart *cart); // total price of the games in the cart
int cart_get_count(Cart *cart); //total number of games in the cart
CartNode *cart_get_items(Cart *cart); //returns a pointer to the cart.head
void cart_clear(Cart *cart); // clear all the games in the cart
void cart_destroy(Cart *cart); //free the memory allocated for the cart

#endif 
#include <stdio.h>
#include "cart.h"
#include "common.h"
#include <stdlib.h>

void cart_init(Cart *cart)
{
    cart->head = NULL;
    cart->tail = NULL;
    cart->count = 0;
    cart->totalPrice = 0.0f;
}

void cart_add_game(Cart *cart, Game *game)
{
    CartNode *newNode = (CartNode *)malloc(sizeof(CartNode));

    if (newNode == NULL)
    {
        return;
    }
    newNode->game = *game;
    newNode->next = NULL;
    cart->count++;

    if (cart->head == NULL)
    {
        newNode->prev = NULL;
        cart->head = newNode;
        cart->tail = newNode;
    }

    else
    {
        cart->tail->next = newNode;
        newNode->prev = cart->tail;
        cart->tail = newNode;
    }
}

CartNode *cart_search_by_id(Cart *cart, int ID)
{
    if (cart == NULL || cart->head == NULL)
    {
        return NULL;
    }

    CartNode *current = cart->head;
    if (current == NULL)
    {
        return NULL;
    }

    while (current != NULL && current->game.gameID != ID)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("invalid id(%d)", ID);
        return NULL;
    }

    return current;
}

void cart_remove_by_id(Cart *cart, int removeID)
{
    if (cart->head == NULL)
        return;

    CartNode *current = cart->head;
    CartNode *prev = NULL;


    while (current != NULL && current->game.gameID != removeID)
    {
        prev = current;
        current = current->next;
    }


    if (current == NULL)
    {
        return;
    }


    if (prev == NULL)
    {

        cart->head = current->next;
    }
    else
    {

        prev->next = current->next;
    }


    if (current == cart->tail)
    {
        cart->tail = prev;
    }


    cart->count--;

    free(current);
}

int cart_get_count(Cart *cart)
{
    return cart->count;
}

float cart_get_total_price(Cart *cart)
{
    float total = 0;
    CartNode *current = cart->head;
    if (current == NULL)
    {
        printf("memory allocation failed");
        return -1;
    }

    while (current != NULL)
    {
        total += current->game.price;
        current = current->next;
    }
    cart->totalPrice = total;
    free(current);
    return total;
}

CartNode *cart_get_items(Cart *cart)
{
    return cart->head;
}

void cart_clear(Cart *cart)
{
    CartNode *current = cart->head;
    CartNode *nextNode;

    while (current != NULL)
    {

        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    cart->head = NULL;
    cart->tail = NULL;
    cart->count = 0;
    cart->totalPrice = 0;
}

void cart_destroy(Cart *cart)
{
    if (cart == NULL)
    {
        return;
    }
    cart_clear(cart);
    free(cart);
}
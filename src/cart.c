#include <stdio.h>
#include "cart.h"
#include "common.h"

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
    CartNode *current = cart_search_by_id(cart, removeID);
    if (current == NULL)
    {
        return;
    }

    // if the node to remove is head
    if (current == cart->head)
    {
        cart->head = current->next;

        // if there is a another node
        if (cart->head != NULL)
        {
            cart->head->prev = NULL;
        }
        else
        {
            cart->tail = NULL;
        }
    }

    // remove from tail
    else if (current == cart->tail)
    {
        cart->tail = current->prev;

        if (cart->tail != NULL)
        {
            cart->tail->next = NULL;
        }
    }

    // remove from the middle
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

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
        current->next = nextNode;
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
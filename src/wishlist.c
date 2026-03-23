#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "common.h"
#include "wishlist.h"

// setup wishlist
void wishlist_init(Wishlist *wishlist)
{
    wishlist->head = NULL;
    wishlist->tail = NULL;
    wishlist->count = 0;
}

// create a new node
WishlistNode *createNode(Game *game)
{
    WishlistNode *newNode = (WishlistNode *)malloc(sizeof(WishlistNode));
    newNode->game = *game;
    newNode->next = NULL;
    return newNode;
}

// is empty check
int wishlist_isEmpty(Wishlist *wishlist)
{

    if (wishlist == NULL || wishlist->head == NULL)
    {
        printf("\nIt is empty list\n");
        return 1;
    }
    else
    {
        printf("\nIt is not empty list\n");
        return 0;
    }
}

// add game to list
void wishlist_insert_new_item(Wishlist *wishlist, Game *game)
{
    WishlistNode *newNode = createNode(game);
    if (wishlist->head == NULL)
    {
        printf("\nIt is an empty linked list\n");
        wishlist->head = newNode;
        wishlist->tail = newNode;
        newNode->next = NULL;
    }
    else
    {
        wishlist->tail->next = newNode;
        wishlist->tail = newNode;
        newNode->next = NULL;
    }
    wishlist->count++;
    printf("Added Successfully\n");
}

// find game by id
Game *wishlist_search_game_by_id(Wishlist *wishlist, int ID)
{
    WishlistNode *curr = wishlist->head;
    while (curr != NULL)
    {
        if (curr->game.gameID == ID)
        {
            return &curr->game;
        }
        curr = curr->next;
    }
    return NULL;
}

void wishlist_remove_item_by_id(Wishlist *wishlist, int removeID)
{
    WishlistNode *temp = wishlist->head;
    WishlistNode *prev = NULL;

    while (temp != NULL && temp->game.gameID != removeID)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Game not found\n");
        return;
    }

    // remove first element
    if (temp == wishlist->head)
    {
        wishlist->head = temp->next;
    }
    else
    {
        prev->next = temp->next; // In middle
    }

    // fix tail pointer
    if (temp == wishlist->tail)
    {
        wishlist->tail = prev;
    }

    wishlist->count--;
    free(temp);

    printf("Game removed successfully\n");
}

// show all items
void wishlist_display_contains(Wishlist *wishlist)
{
    WishlistNode *temp = wishlist->head;
    if (temp == NULL)
    {
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("{%d,        %s,         %f,         %f      }\n", temp->game.gameID, temp->game.title, temp->game.price, temp->game.rating);
            temp = temp->next;
        }
    }
}

// get list size
int wishlist_count(Wishlist *wishlist)
{
    return wishlist->count;
}

void wishlist_clear(Wishlist *wishlist)
{
    WishlistNode *curr = wishlist->head;
    WishlistNode *nextNode;

    while (curr != NULL)
    {

        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }

    wishlist->head = NULL;
    wishlist->tail = NULL;
    wishlist->count = 0;
}

// free wishlist mem
void wishlist_destroy(Wishlist *wishlist)
{
    if (wishlist == NULL)
    {
        return;
    }
    wishlist_clear(wishlist);
}

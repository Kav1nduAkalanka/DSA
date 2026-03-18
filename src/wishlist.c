#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "common.h"
#include "wishlist.h"


//Initialize the wishlist
void init_wishlist(wishlist *wishlist)
{
    wishlist->head=NULL;
    wishlist->tail=NULL;
    wishlist->count=0;
}


//Create New Node
wishlistNode* createNode(Game *game)
{
    wishlistNode *newNode=(wishlistNode*)malloc(sizeof(wishlistNode));
    newNode->game=*game;
    newNode->next=NULL;
    return newNode;
}


//Main Menu
void wishlist_display_main_menu()
{
    printf("\n====WISTLISH MENU====\n");
    printf("1.Display Wishlist\n");
    printf("2.Add Games\n");
    printf("3.Search Wishlist Items\n");
    printf("4.Delete Items\n");
    printf("5.Sort Item\n");
    printf("6.Exit");
}
//Check Empty of the wishlist
int wishlist_isEmpty(wishlist *wishlist)
{
    
    if( wishlist->head==NULL || wishlist==NULL)
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


//Add New items to wishlist
void wishlist_insert_new_item( wishlist *wishlist,Game *game)
{
    wishlistNode *newNode=createNode(game);
    if(wishlist->head==NULL)
    {
        printf("\nIt is an empty linked list\n");
        wishlist->head=newNode;
        wishlist->tail=newNode;
        newNode->next=NULL;
    }
    else
    {
        wishlist->tail->next=newNode;
        wishlist->tail=newNode;
        newNode->next=NULL;
    }
    wishlist->count++;
    printf("Added Successfully\n");
}

//Search Items in Wishlist
wishlistNode *wishlist_search_game_by_id(wishlist *wishlist,int ID)
{
    wishlistNode *curr=wishlist->head;
    if(curr==NULL)
    {
        return NULL;
    }
    else
    {
        if(curr !=NULL && curr->game.gameID !=ID)
        {
            printf("Invalid ID(%d)",ID);//check validiation of ID
        }
        else
        {
            return curr;
        }
        curr=curr->next;
    }


}


void wishlist_remove_item_by_id(wishlist *wishlist,int removeID)
{
    wishlistNode *temp = wishlist->head;
    wishlistNode *prev = NULL;

    while(temp != NULL && temp->game.gameID != removeID)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Game not found\n");
        return;
    }

    // delete first node
    if(temp == wishlist->head)
    {
        wishlist->head = temp->next;
    }
    else
    {
        prev->next = temp->next;//In middle 
    }

    // update tail if last node deleted
    if(temp == wishlist->tail)
    {
        wishlist->tail = prev;
    }

    wishlist->count--;
    free(temp);

    printf("Game removed successfully\n");
}

//Display the wishlist
void wishlist_display_contains(wishlist *wishlist)
{
    wishlistNode *temp=wishlist->head;
    if(temp==NULL)
    {
        return;
    }
    else
    {
        while(temp !=NULL)
        {
            printf("{%d,        %s,         %f,         %f      }\n",temp->game.gameID,temp->game.title,temp->game.price,temp->game.rating);
            temp=temp->next;
        }


    }

}

//No.of items in wishlist
int wishlist_count(wishlist *wishlist)
{
    return wishlist->count;
}

void wishlist_clear(wishlist *wishlist)
{
    wishlistNode *curr= wishlist->head;
    wishlistNode *nextNode;

    while (curr != NULL)
    {

        nextNode = curr->next;
        free(curr);
    }

    wishlist->head = NULL;
    wishlist->tail = NULL;
    wishlist->count = 0;

}


//destroy the wishlist
void wishlist_destroy(wishlist *wishlist)
{
    if (wishlist == NULL)
    {
        return;
    }
    wishlist_clear(wishlist);
    free(wishlist);
}


int main()
{
    wishlist wishlist;
    init_wishlist(&wishlist);

    Game game1={1,"AAA",234.55,2.3};
    Game game4={2,"BBB",234.55,2.3};
    Game game3={3,"Ajj",234.55,2.3};
    Game game5={4,"Ajj",2344.55,2.3};

    wishlist_insert_new_item(&wishlist,&game1);
    wishlist_insert_new_item(&wishlist,&game4);
    wishlist_insert_new_item(&wishlist,&game3);
    wishlist_insert_new_item(&wishlist,&game5);

    wishlist_display_contains(&wishlist);

    wishlist_remove_item_by_id(&wishlist,2);
    wishlist_remove_item_by_id(&wishlist,4);
     wishlist_remove_item_by_id(&wishlist,1);


    wishlist_display_contains(&wishlist);

    int c = wishlist_count(&wishlist);
    printf("\nCount = %d\n",c);
}
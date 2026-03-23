#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "navigation.h"


// init stack
void nav_init(NavStack *nav)
{
    nav->top = NULL;
    nav->stackCount = 0;
}
// is empty check
int nav_is_empty(NavStack *nav)
{
    if (nav == NULL || nav->top == NULL)
    {
        return 1;
    }
    return 0;
}
// push route
void nav_push(NavStack *nav, Page currentPage)
{
    NavStackNode *newNode = (NavStackNode *)malloc(sizeof(NavStackNode));
    if (newNode == NULL){
        return;
    }
    newNode->page = currentPage;    

    newNode->next = nav->top;
    nav->top = newNode;
    nav->stackCount++;
}

// pop route
void nav_pop(NavStack *nav)
{
    if (nav_is_empty(nav))
    {
        return;
    }

    NavStackNode *temp = nav->top;
    nav->top = nav->top->next;
    free(temp);
    nav->stackCount--;
}

// peek top page
Page nav_peek(NavStack *nav)
{
    if(nav_is_empty(nav)){
        return PAGE_MAIN_MENU;
    }
    return nav->top->page;
}

// free nav
void nav_destroy(NavStack *nav)
{

    while(!nav_is_empty(nav)){
        nav_pop(nav);
    }
}
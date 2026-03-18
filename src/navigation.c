#include <stdio.h>
#include <stdbool.h>
#include "navigation.h"

NavStackNode *nav_create_node(Page currentPage)
{
    NavStackNode *newNode;
}
void nav_init(NavStack *nav)
{
    nav->top = NULL;
    nav->stackCount = 0;
}
int nav_is_empty(NavStack *nav)
{
    if (nav == NULL)
    {
        return 1;
    }
    return 0;
}
void nav_push(NavStack *nav, Page currentPage)
{
    NavStackNode *newNode = (NavStackNode *)malloc(sizeof(NavStackNode));
    if (nav_is_empty(nav))
    {
        return;
    }

    if (nav->top == NULL)
    {
        nav->top = newNode;
    }

    newNode->next = nav->top;
    nav->top = newNode;
    nav->stackCount++;
}

void nav_pop(NavStack *nav)
{
    if (nav_is_empty(nav))
    {
        return;
    }

    NavStackNode *temp = nav->top;
    nav->top = nav->top->next;
    free(temp);
}

Page nav_peek(NavStack *nav)
{
    return nav->top->page;
}

void nav_destroy(NavStack *nav)
{

    if (nav_is_empty(nav))
    {
        return;
    }
    NavStackNode *current = nav->top;
    while (current != NULL)
    {
        NavStackNode *temp = current->next;
        free(current);
        current = temp;
    }
}
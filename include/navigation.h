#ifndef NAVIGATION_H
#define NAVIGATION_H
#include "common.h"
typedef struct NavStackNode
{
    Page page;
    struct NavStackNode *next;
} NavStackNode;

// stack struct
typedef struct NavStack
{
    NavStackNode *top;
    int stackCount;

} NavStack;

void nav_init(NavStack *nav); // setup
void nav_push(NavStack *nav,Page page); // nav forward
void nav_pop(NavStack *nav); // nav back
Page nav_peek(NavStack *nav); // curr page
int nav_is_empty(NavStack *nav); // is top level
void nav_destroy(NavStack *nav); // cleanup
 
#endif
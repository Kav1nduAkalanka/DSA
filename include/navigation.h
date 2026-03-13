#ifndef NAVIGATION_H
#define NAVIGATION_H
#include "common.h"
typedef struct NavStackNode
{
    Page page;
    struct NavStackNode *next;
} NavStackNode;

typedef struct NavStack
{
    NavStackNode *top;
    int stackCount;

} NavStack;

void nav_init(NavStack *nav);
void nav_push(NavStack *nav,Page page);
void nav_pop(NavStack *nav);
Page nav_peek(NavStack *nav);
int nav_is_empty(NavStack *nav);
void nav_destroy(NavStack *nav);
 
#endif
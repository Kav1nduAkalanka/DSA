#ifndef SUPPORT_H
#define SUPPORT_H
#include<stdio.h>

#define MAX_TITLE_LENGHTH 100 // max string len
#define MAX_SUPPORT_LIST 10  // max elements

typedef struct supportNode
{
    int ticketId;
    char supportTitle[MAX_TITLE_LENGHTH];
    int priority; // 1 = highest tier
    struct supportNode *next;

} supportNode;


typedef struct priorityQueue
{
    struct supportNode *front;
    int count;
    
} priorityQueue;


void support_queue_submit_ticket(priorityQueue *q,int ticketID,char ticketTitle[],int priority);
void support_queue_resolve_next(priorityQueue *q);
void support_queue_peek_next(priorityQueue *q);
int support_queue_get_count(priorityQueue *q);
void support_queue_destroy(priorityQueue *q);
void support_queue_initialize(priorityQueue *q);

#endif
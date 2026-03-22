#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"


//Initialize the support queue
void support_queue_initialize(priorityQueue *q)
{
    q->front = NULL;
    q->count = 0;
}


//Add a ticket and sorting them according to the priority 
void support_queue_submit_ticket(priorityQueue *q, int ticketID, char ticketTitle[], int priority)
{
    supportNode *newNode = (supportNode *)malloc(sizeof(supportNode));
    newNode->ticketId = ticketID;
    strcpy(newNode->supportTitle, ticketTitle);
    newNode->priority = priority;
    newNode->next = NULL;

    if(q->front == NULL || priority < q->front->priority)//The lowest value represent the highest priority
    {
        newNode->next = q->front;
        q->front = newNode;
    }
    else
    {
        supportNode *temp = q->front;
        while(temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    q->count++;  //Increase the count 

    printf("\nAdded and sorted successfully\n");
    printf("Total Tickets: %d\n", q->count);
}



//Create the support queue
void support_queue_demo(priorityQueue *q)
{
    support_queue_submit_ticket(q, 1, "Help to add", 2);
    support_queue_submit_ticket(q, 2, "Help to remove", 1);
    support_queue_submit_ticket(q, 3, "Help to pop", 5);
    support_queue_submit_ticket(q, 4, "Help to search", 4);
    support_queue_submit_ticket(q, 5, "Help to add to cart", 66);
    support_queue_submit_ticket(q, 6, "Help to add", 34);
    support_queue_submit_ticket(q, 7, "Help to show wishlist", 3);
    support_queue_submit_ticket(q, 8, "Help to blaa blaa", 8);
    support_queue_submit_ticket(q, 9, "Hhee hee", 9);
}


//Remove the highest priority ticket first
void support_queue_resolve_next(priorityQueue *q)
{
    if(q->front == NULL)
    {
        printf("\nNo Tickets\n");
    }
    else
    {
        supportNode *temp = q->front;
        q->front = temp->next;
        free(temp);
        q->count--;  // only decrement if a ticket is removed
    }
}


//Display the details of next ticket
void support_queue_peek_next(priorityQueue *q)
{
    if(q->front == NULL)
    {
        printf("\nNo Tickets\n");
    }
    else
    {
        supportNode *temp = q->front;
        printf("Next Ticket ID: %d\n", temp->ticketId);
        printf("Next Ticket's Title: %s\n", temp->supportTitle);
        printf("Priority of the Next Ticket: %d\n", temp->priority);
    }
}


//Get the count od queue
int support_queue_get_count(priorityQueue *q)
{
    return q->count;
}


//Destory the 
void support_queue_destroy(priorityQueue *q)
{
    supportNode *temp;
    while(q->front != NULL)
    {
        temp = q->front;
        q->front = temp->next;
        free(temp);
    }
    q->count = 0;
}

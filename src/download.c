#include "download.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>



// Initializes the download queue by setting pointers to NULL
void download_init_queue(DownloadQueue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Checks if the download queue is empty
int download_is_empty(DownloadQueue *queue)
{
    if (queue->front == NULL)
    {
        return 1;
    }

    return 0;
}

// Adds a new game to the end of the download queue (FIFO Logic)
void download_enqueue(DownloadQueue *queue, Game *Inputgame)
{

    // Defining pace to allocate memory properly
    DownloadNode *newNode = (DownloadNode *)malloc(sizeof(DownloadNode));

    // Safety check for memory allocation failure
    if (newNode == NULL)
    {
        return;
    }

    // Assigning values to the newly created node
    strcpy(newNode->game.title, Inputgame->title);
    newNode->game.gameID = Inputgame->gameID;
    newNode->game.size = Inputgame->size;
    newNode->status = PENDING;
    newNode->next = NULL;

    // If queue is empty, the new game is both the front and rear
    if (download_is_empty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        // Link the current last node to the new node, then update rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

}

// Removes the completed game from the front of the queue
void download_dequeue(DownloadQueue *queue)
{

    if (download_is_empty(queue))
    {
        return;
    }

    // Temporarily hold the node to be removed
    DownloadNode *tempNode = queue->front;

    // Move the front pointer to the next game in line
    queue->front = queue->front->next;

    // free the memory after using malloc to prevent memory leaks
    free(tempNode);

    // If the queue becomes completely empty, reset rear pointer to NULL
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
}

// Displays the game currently downloading (at the front of the queue)
Game *download_peek(DownloadQueue *queue)
{
    if (download_is_empty(queue))
    {
        return NULL;
    }
    return &queue->front->game;
}

void download_queue_destroy(DownloadQueue *queue){
    if (queue->front == NULL){
        return;
    }

    DownloadNode *current = queue->front;
    while (current != NULL)
    {
        DownloadNode *temp = current->next;
        free(current);
        current = temp;
    }

    queue->front = NULL;
    queue->rear = NULL;

}

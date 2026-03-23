// includes
#include "download.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>


// setup queue
void download_init_queue(DownloadQueue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// is queue empty?
int download_is_empty(DownloadQueue *queue)
{
    if (queue->front == NULL)
    {
        return 1;
    }

    return 0;
}

// push game to queue (fifo)
void download_enqueue(DownloadQueue *queue, Game *Inputgame)
{

    // alloc node mem
    DownloadNode *newNode = (DownloadNode *)malloc(sizeof(DownloadNode));

    // null check
    if (newNode == NULL)
    {
        return;
    }

    // copy game details
    strcpy(newNode->game.title, Inputgame->title);
    newNode->game.gameID = Inputgame->gameID;
    newNode->game.size = Inputgame->size;
    newNode->status = PENDING;
    newNode->next = NULL;

    // handle empty queue edge case
    if (download_is_empty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        // push to back
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

}

// pop front game
void download_dequeue(DownloadQueue *queue)
{

    if (download_is_empty(queue))
    {
        return;
    }

    // save node to free later
    DownloadNode *tempNode = queue->front;

    // shift front
    queue->front = queue->front->next;

    // free node mem
    free(tempNode);

    // reset rear if empty
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
}

// peek front game
Game *download_peek(DownloadQueue *queue)
{
    if (download_is_empty(queue))
    {
        return NULL;
    }
    return &queue->front->game;
}

void download_remove_by_id(DownloadQueue *queue, int id) {
    if (download_is_empty(queue)) {
        printf("\nQueue is empty.\n");
        return;
    }
    DownloadNode *current = queue->front;
    DownloadNode *prev = NULL;
    while (current != NULL && current->game.gameID != id) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("\nInvalid ID (%d).\n", id);
        return;
    }
    if (prev == NULL) {
        queue->front = current->next;
    } else {
        prev->next = current->next;
    }
    if (current == queue->rear) {
        queue->rear = prev;
    }
    printf("\nGame removed from downloads queue (%s).\n", current->game.title);
    free(current);
}

int download_is_duplicate(DownloadQueue *queue, int id) {
    DownloadNode *curr = queue->front;
    while (curr != NULL) {
        if (curr->game.gameID == id) return 1;
        curr = curr->next;
    }
    return 0;
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
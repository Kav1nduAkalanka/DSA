#ifndef DOWNLOAD_H  
#define DOWNLOAD_H  

#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  
#include "common.h"




typedef enum {
    PENDING,      // queued
    DOWNLOADING,  // active
    COMPLETED     // done
} DownloadStatus;


typedef struct DownloadNode {
    Game game;
    DownloadStatus status;          // state
    struct DownloadNode* next;      // next node ptr
} DownloadNode;


typedef struct DownloadQueue {
    DownloadNode* front; // head
    DownloadNode* rear;  // tail
} DownloadQueue;



// init queue
void download_init_queue(DownloadQueue* queue);

// is empty?
int download_is_empty(DownloadQueue* queue);

// push game
void download_enqueue(DownloadQueue* queue, Game *game);

// pop game
void download_dequeue(DownloadQueue* queue);

// peek game
Game *download_peek(DownloadQueue* queue);

void download_remove_by_id(DownloadQueue *queue, int id);
int download_is_duplicate(DownloadQueue *queue, int id);

// free queue mem
void download_queue_destroy(DownloadQueue* queue);

#endif // End of DOWNLOAD_H
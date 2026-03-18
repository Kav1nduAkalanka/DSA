#ifndef DOWNLOAD_H  
#define DOWNLOAD_H  

#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  
#include "common.h"




typedef enum {
    PENDING,      // Download is in the queue but hasn't started
    DOWNLOADING,  // Data is currently being transferred
    COMPLETED     // Download is finished
} DownloadStatus;


typedef struct DownloadNode {
    Game game;
    DownloadStatus status;          // Current state from the enum above
    struct DownloadNode* next;      // Pointer to the next node in the sequence
} DownloadNode;


typedef struct DownloadQueue {
    DownloadNode* front; // Points to the next item to be processed (the oldest)
    DownloadNode* rear;  // Points to the last item added (the newest)
} DownloadQueue;



// Initializes a new queue by setting front and rear pointers to NULL
void download_init_queue(DownloadQueue* queue);

// Checks if the queue has any items; returns 1 (true) if empty, 0 (false) if not
int download_is_empty(DownloadQueue* queue);

// Adds a new game to the back (rear) of the queue
void download_enqueue(DownloadQueue* queue, Game *game);

// Removes the item at the front of the queue and frees its memory
void download_dequeue(DownloadQueue* queue);

// Displays or retrieves the data of the item at the front without removing it
Game *download_peek(DownloadQueue* queue);

//free all the memory used
void download_queue_destroy(DownloadQueue* queue);

#endif // End of DOWNLOAD_H
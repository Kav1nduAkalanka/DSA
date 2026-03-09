#include "download.h"  // The header file defined for the donwload manager

// Initializes the download queue by setting pointers to NULL
void download_init_queue(DownloadQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Checks if the download queue is empty
int download_is_empty(DownloadQueue* queue) {
    return queue->front == NULL;
}

// Adds a new game to the end of the download queue (FIFO Logic)
void download_enqueue(DownloadQueue* queue, const char* gameName, float gameSize) {
    
    // Defining pace to allocate memory properly 
    DownloadNode* newNode = (DownloadNode*)malloc(sizeof(DownloadNode));
    
    // Safety check for memory allocation failure
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    
    // Assigning values to the newly created node
    strcpy(newNode->gameName, gameName);
    newNode->gameSize = gameSize;
    newNode->status = PENDING;
    newNode->next = NULL; 
    
    // If queue is empty, the new game is both the front and rear
    if (download_is_empty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Link the current last node to the new node, then update rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Added to downloads: %s (%.2f GB)\n", gameName, gameSize);
}

// Removes the completed game from the front of the queue
void download_dequeue(DownloadQueue* queue) {
    
    if (download_is_empty(queue)) {
        printf("Download queue is empty! Nothing to dequeue.\n");
        return;
    }
    
    // Temporarily hold the node to be removed
    DownloadNode* tempNode = queue->front;
    
    // Move the front pointer to the next game in line
    queue->front = queue->front->next;
    
    printf("Download completed & removed: %s\n", tempNode->gameName);
    
    // free the memory after using malloc to prevent memory leaks
    free(tempNode); 
    
    // If the queue becomes completely empty, reset rear pointer to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
}

// Displays the game currently downloading (at the front of the queue)
void download_peek(DownloadQueue* queue) {
    if (download_is_empty(queue)) {
        printf("No active downloads.\n");
        return;
    }
    printf("Currently downloading: %s (%.2f GB)\n", queue->front->gameName, queue->front->gameSize);
}
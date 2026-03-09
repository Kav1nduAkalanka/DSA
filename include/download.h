#ifndef DOWNLOAD_H  //Prevents multiple inclusions of this file
#define DOWNLOAD_H  //Definition of the header guard

#include <stdio.h>   // For standard I/O (printf)
#include <stdlib.h>  // For memory management (malloc, free)
#include <string.h>  // For string operations (strcpy)

#define MAX_NAME_LENGTH 50  // Maximum characters allowed for a game's name

/* 
  * Defines the possible states of a download.
  * Enums make the code readable by replacing numbers with meaningful names.
*/
typedef enum {
    PENDING,      // Download is in the queue but hasn't started
    DOWNLOADING,  // Data is currently being transferred
    COMPLETED     // Download is finished
} DownloadStatus;

/* 
  * Represents a single item (node) in the linked list.
  * Each node contains the game data and a link to the next item.
 */
typedef struct DownloadNode {
    char gameName[MAX_NAME_LENGTH]; // Storage for the game's title
    float gameSize;                 // Size of the game (e.g., in GB)
    DownloadStatus status;          // Current state from the enum above
    struct DownloadNode* next;      // Pointer to the next node in the sequence
} DownloadNode;

/* 
  * The Manager structure for the Queue.
  * It tracks the start (front) and the end (rear) of the list.
*/
typedef struct DownloadQueue {
    DownloadNode* front; // Points to the next item to be processed (the oldest)
    DownloadNode* rear;  // Points to the last item added (the newest)
} DownloadQueue;

/* --- Function Prototypes --- */

// Initializes a new queue by setting front and rear pointers to NULL
void download_init_queue(DownloadQueue* queue);

// Checks if the queue has any items; returns 1 (true) if empty, 0 (false) if not
int download_is_empty(DownloadQueue* queue);

// Adds a new game to the back (rear) of the queue
void download_enqueue(DownloadQueue* queue, const char* gameName, float gameSize);

// Removes the item at the front of the queue and frees its memory
void download_dequeue(DownloadQueue* queue);

// Displays or retrieves the data of the item at the front without removing it
void download_peek(DownloadQueue* queue);

#endif // End of DOWNLOAD_H
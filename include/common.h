#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100     // max length of a game title
#define MAX_CATALOG_SIZE 20   // max game catalog size
#define  INITIAL_LIBRARY_CAP 5 // library size at the initialization

// page logic IDs
typedef enum
{
    PAGE_EXIT,      //0
    PAGE_CATALOG,   //1
    PAGE_CART,      //2
    PAGE_LIBRARY,   //3
    PAGE_DOWNLOAD,  //4
    PAGE_WISHLIST,  //5
    PAGE_SUPPORT,   //6    
    PAGE_MAIN_MENU  //7    
} Page;

// priorities
typedef enum
{
    PRIORITY_LOW, //0
    PRIORITY_MEDIUM, //1
    PRIORITY_HIGH //2
} Priority;


typedef enum{
    KEYWORD_MONEY,
    KEYWORD_LOGIN,
    KEYWORD_CRASH,
    KEYWORD_GENERAL
}KeyWord;

// base game node
typedef struct 
{
    int gameID;
    char title[MAX_TITLE_LEN];
    float price;
    float rating; // out of 5.0
    float size; // gb sizes
} Game;

#endif
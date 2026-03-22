#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100     // max length of a game title
#define MAX_CATALOG_SIZE 20   // max game catalog size
#define  INITIAL_LIBRARY_CAP 5 // library size at the initialization

typedef enum
{
    PAGE_EXIT,
    PAGE_CATALOG,
    PAGE_CART,
    PAGE_LIBRARY,
    PAGE_DOWNLOAD,
    PAGE_WISHLIST,
    PAGE_SUPPORT,
    PAGE_MAIN_MENU
} Page;

typedef enum
{
    PRIORITY_LOW,
    PRIORITY_MEDIUM,
    PRIORITY_HIGH
} Priority;

typedef enum{
    KEYWORD_MONEY,
    KEYWORD_LOGIN,
    KEYWORD_CRASH,
    KEYWORD_GENERAL
}KeyWord;

typedef struct 
{
    int gameID;
    char title[MAX_TITLE_LEN];
    float price;
    float rating; // 0.0 to 5.0
    float size; //game size in GB
} Game;

#endif
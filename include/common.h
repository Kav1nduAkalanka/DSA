#ifndef COMMON_H
#define COMMON_H

#define MAX_STR_LEN 100 
#define STORE_NAME "test" //change the store name later

typedef struct{
    int game_id;
    char title[MAX_STR_LEN];
    float price;
    float rating;
}Game;

#endif
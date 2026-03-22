#ifndef LIBRARY_H
#define LIBRARY_H
#include "common.h"

typedef struct Library
{
    Game *game;
    int gameCount;
    int libCapacity;
} Library;

void lib_init(); //initialize the library
void lib_add_game(Library *library, Game *game); //add a game to the library
int lib_is_id_contains(Library *library, int gameID); //check whethere a given gameID is in the library or not. is available return 1 if not return 0
void lib_remove_game_by_id(Library *library, int gameID); // remove a game using gameID
Game *lib_get_game_data(Library *library, int gameID); //returns the struct Game of a selected game 
int lib_get_count(Library *library); // total number of games 
void lib_destroy(Library *library); //deallocate memory

#endif 
#ifndef LIBRARY_H
#define LIBRARY_H
#include "common.h"

typedef struct Library
{
    Game *game;
    int gameCount;
    int libCapacity;
} Library;

void lib_init();
void lib_add_game(Library *library, Game *game);
int lib_is_id_contains(Library *library, int gameID);
void lib_remove_game_by_id(Library *library, int gameID);
Game *lib_get_game_data(Library *library, int gameID);
int lib_get_count(Library *library);
void lib_destroy(Library *library);

#endif
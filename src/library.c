#include <stdio.h>
#include "library.h"
#include "common.h"

void lib_init(Library *library)
{
    library->game = (Library *)malloc(sizeof(Game) * INITIAL_LIBRARY_CAP);
    if (&library->game == NULL)
    {
        printf("\nmemory allocation failed");
        return;
    }
    library->gameCount = 0;
    library->libCapacity = INITIAL_LIBRARY_CAP;
}

void lib_add_game(Library *library, Game *inputGame)
{
    if (library->gameCount >= library->libCapacity)
    {
        Game *temp = library->game;
        temp = realloc(library->game, sizeof(Game) * INITIAL_LIBRARY_CAP * 2);
        if (temp == NULL)
        {
            printf("realloc failed");
            return;
        }
        INITIAL_LIBRARY_CAP *= 2;
        library->game = temp;
    }
    library->gameCount += 1;
    int index = library->gameCount - 1;
    library->game[index].gameID = inputGame->gameID;
    library->game[index].price = inputGame->price;
    library->game[index].rating = inputGame->rating;
    library->game[index].size = inputGame->size;
    strcpy(library->game[index].title, inputGame->title);

    printf("game added to lib.(%s)\n", library->game->title);
}

// returns the index of the game
int lib_is_id_contains(Library *library, int id)
{
    for (int index = 0; index < library->gameCount; index++)
    {
        if (id == library->game[index].gameID)
        {
            return index;
        }
    }
    printf("Game is not the the library");
    return -1;
}

void lib_remove_game_by_id(Library *library, int id)
{
    int index = lib_is_id_contains(library, id);
    if (index == -1){
        return;
    }
    for (int i = index; i < library->gameCount - 1; i++)
    {
    library->game[i].gameID = library->game[i+1].gameID;
    library->game[i].price = library->game[i+1].price;
    library->game[i].rating = library->game[i+1].rating;
    library->game[i].size = library->game[i+1].size;
    strcpy(library->game[i].title, library->game[i+1].title);
    }
}

Game *library_get_game_data(Library *library , int id){
    int index = lib_is_id_contains(library,id);
    if(index == -1){
        printf("invalid ID(%d)",id);
        return;
    }

    return &library->game[index];
}

int lib_get_count(Library *library){
    return library->gameCount;
}


void lib_destroy(Library *library){
    if(!library->gameCount){
        return;
    }
    free(library->game);
    
}
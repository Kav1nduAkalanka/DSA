#include <stdio.h>
/*#include "common.h"
#include "catalog.h"
#include "cart.h"
#include "download.h"*/
#include <stdbool.h>
#include <stdlib.h> //system("cls") on windows
#include <windows.h> //Sleep(time in seconds)

void show_main_menu();

int main()
{
    int running = 1;
    int userInput = 0;

    while(running){
        show_main_menu();
        if(scanf("%d",&userInput) != 1){
            userInput = -1;
        }
    }

    return 0;
}

void show_main_menu(){
    printf("==================================================\n");
    printf("                 GAME STORE\n");
    printf("==================================================\n");
    printf("Welcome, Player!\n\n");
    printf("[1] Browse Catalog\n");
    printf("[2] View Cart\n");
    printf("[3] Downloads(Downloading: %d )\n", 10);
    printf("[4] Library\n");
    printf("[5] Wishlist\n");
    printf("[6] Support\n\n");
    printf("--------------------------------------------------\n");
    printf("Enter your choice: ");
}


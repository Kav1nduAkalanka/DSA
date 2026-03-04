# DSA
This repo contains the source files of the DSA assignment 2

To ensure compatibility of each module please follow these naming conventions:

*Structs & Typedef -> PascaleCase
    ex: 
    typedef struct StudentRecord{
        //values
    } StudentRecord;

*Functions -> module_snake_case()  ;Start every function with the module name.
    ex:
        catalog_sort_games()
        cart_add_item()

*Constants -> UPPER_SNAKE_CASE
    ex:
        #define MAX 100

!!ALWAYS free the memory after using malloc or calloc!!
!!ALWAYS write good comments!!
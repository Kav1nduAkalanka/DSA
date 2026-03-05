#include <stdio.h>
#include "common.h"
#include "catalog.h"

int main()
{

    catalog_init();
    printf("hello\n");
    catalog_print_games();

    printf("hello\n");
    return 0;
}
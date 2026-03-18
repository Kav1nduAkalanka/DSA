#ifndef HELP_H
#define HELP_H
#include "common.h"

typedef struct Queue
{
    char problem[1000];
    KeyWord keyWord;
    Priority priority;

}Queue;




void help_queue_init();

#endif
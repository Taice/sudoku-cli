#include "help.h"
#include <stdio.h>

void help(char *run)
{
    printf("usage:\n");
    printf("%s [<flag> <value>]\n\n", run);
    printf("flags:\n");
    printf("-i >> shows index numbers next to sudoku grid\n");
    printf("-l <lives> >> specify how many lives you want to have\n");
}

#include "game.h"
#include "help.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    bool index = false;
    int lives = 3;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-i"))
        {
            index = true;
        }
        else if (strcmp(argv[i], "-l"))
        {
            lives = atoi(argv[i + 1]);
            i++;
        }
        else
        {
            printf("unknown option %s", argv[i]);
            help(argv[0]);
            return 1;
        }
    }
	game(index, lives);
}

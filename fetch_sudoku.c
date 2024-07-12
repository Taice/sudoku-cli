#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 9

int get_sudoku(const char *filename, int sudoku[SIZE][SIZE])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (fscanf(file, "%1d", &sudoku[i][j]) != 1)
            {
                fprintf(stderr, "Invalid input format in file\n");
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);
    return 0;
}

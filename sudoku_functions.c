#include <stdbool.h>
#include <unistd.h>

#include "sudoku_functions.h"
bool find_empty_space(int sudoku[SIZE][SIZE], int *row, int *col);

short is_winnable(int sudoku[SIZE][SIZE])
{
    int clone[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            clone[i][j] = sudoku[i][j];
        }
    }

    int row, col;

    if (is_valid(clone))
    {
        if (!find_empty_space(clone, &row, &col))
        {
            return 0;
        }
        if (backtrack(clone))
        {
            return 1;
        }
    }

    return -1;
}

bool is_valid(int sudoku[SIZE][SIZE])
{
    bool rows[SIZE][SIZE] = {false};
    bool cols[SIZE][SIZE] = {false};
    bool boxes[SIZE][SIZE] = {false};

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (sudoku[i][j] != 0)
            {
                int num = sudoku[i][j] - 1;
                int box_index =
                    (i / SUBGRID_SIZE) * SUBGRID_SIZE + j / SUBGRID_SIZE;

                if (rows[i][num] || cols[j][num] || boxes[box_index][num])
                {
                    return false;
                }

                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box_index][num] = true;
            }
        }
    }
    return true;
}

bool find_empty_space(int sudoku[SIZE][SIZE], int *row, int *col)
{
    for (*row = 0; *row < SIZE; (*row)++)
    {
        for (*col = 0; *col < SIZE; (*col)++)
        {
            if (sudoku[*row][*col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool backtrack(int sudoku[SIZE][SIZE])
{
    int row, col;

    if (!find_empty_space(sudoku, &row, &col))
    {
        return true;
    }

    for (int num = 1; num <= SIZE; num++)
    {
        sudoku[row][col] = num;

        if (is_valid(sudoku))
        {
            if (backtrack(sudoku))
            {
                return true;
            }
        }

        sudoku[row][col] = 0;
    }
    return false;
}

void clear_notes(char notes[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        notes[i] = ' ';
    }
}

#include "interface.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define SIZE 9
void clear_screen(void) { printf("\e[1;1H\e[2J"); }

void print_sudoku(int sudoku[SIZE][SIZE], int index, int high, int light)
{
    if (index)
    {

        printf("  ╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        for (int i = 0; i < SIZE; i++)
        {
            if (i != 0)
            {
                if (i % 3 == 0)
                {
                    printf("  ╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
                }
                else
                {
                    printf("  ╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                }
            }
            for (int j = 0; j < SIZE; j++)
            {
                if (i == high && j == light)
                {
                    switch (j)
                    {
                    case 0:
                        printf("%d ║ ▊ ", i + 1);
                        break;
                    case 3:
                        printf("║ ▊ ");
                        break;
                    case 6:
                        printf("║ ▊ ");
                        break;
                    case SIZE - 1:
                        printf("│ ▊ ║\n");
                        break;
                    default:
                        printf("│ ▊ ");
                    }
                }
                else if (sudoku[i][j] == 0)
                {
                    switch (j)
                    {
                    case 0:
                        printf("%d ║   ", i + 1);
                        break;
                    case 3:
                        printf("║   ");
                        break;
                    case 6:
                        printf("║   ");
                        break;
                    case SIZE - 1:
                        printf("│   ║\n");
                        break;
                    default:
                        printf("│   ");
                    }
                }
                else
                {
                    switch (j)
                    {
                    case 0:
                        printf("%d ║ %d ", i + 1, sudoku[i][j]);
                        break;
                    case 3:
                        printf("║ %d ", sudoku[i][j]);
                        break;
                    case 6:
                        printf("║ %d ", sudoku[i][j]);
                        break;
                    case SIZE - 1:
                        printf("│ %d ║\n", sudoku[i][j]);
                        break;
                    default:
                        printf("│ %d ", sudoku[i][j]);
                    }
                }
            }
        }
        printf("  ╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n");
    }
    else
    {
        printf("╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        for (int i = 0; i < SIZE; i++)
        {
            if (i != 0)
            {
                if (i % 3 == 0)
                {
                    printf("╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
                }
                else
                {
                    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                }
            }
            for (int j = 0; j < SIZE; j++)
            {
                if (i == high && j == light)
                {
                    switch (j)
                    {
                    case 0:
                        printf("║ ▊ ");
                        break;
                    case 3:
                        printf("║ ▊ ");
                        break;
                    case 6:
                        printf("║ ▊ ");
                        break;
                    case SIZE - 1:
                        printf("│ ▊ ║\n");
                        break;
                    default:
                        printf("│ ▊ ");
                    }
                }
                else if (sudoku[i][j] == 0)
                {
                    switch (j)
                    {
                    case 0:
                        printf("║   ");
                        break;
                    case 3:
                        printf("║   ");
                        break;
                    case 6:
                        printf("║   ");
                        break;
                    case SIZE - 1:
                        printf("│   ║\n");
                        break;
                    default:
                        printf("│   ");
                    }
                }
                else
                {
                    switch (j)
                    {
                    case 0:
                        printf("║ %d ", sudoku[i][j]);
                        break;
                    case 3:
                        printf("║ %d ", sudoku[i][j]);
                        break;
                    case 6:
                        printf("║ %d ", sudoku[i][j]);
                        break;
                    case SIZE - 1:
                        printf("│ %d ║\n", sudoku[i][j]);
                        break;
                    default:
                        printf("│ %d ", sudoku[i][j]);
                    }
                }
            }
        }
        printf("╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n");
    }
}

void print_notes(char notes[SIZE])
{
    printf("╭───────╮\n");
    for (int i = 0; i < SIZE / 3; i++)
    {
        printf(
            "│ %c %c %c │\n", notes[(i * 3)] == '0' ? ' ' : notes[(i * 3)],
            notes[1 + (i * 3)] == '0' ? ' ' : notes[1 + (i * 3)],
            notes[2 + (i * 3)] == '0' ? ' ' : notes[2 + (i * 3)]);
    }
    printf("╰───────╯\n");
}

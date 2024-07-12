#pragma once

#define SIZE 9

#include <stdbool.h>
int getch(void);
void clear_screen(void);
void print_sudoku(int sudoku[SIZE][SIZE], int high, int light, int index);
void print_notes(char notes[SIZE]);

#pragma once

#include <stdbool.h>

#define SIZE 9
#define SUBGRID_SIZE 3

bool is_valid(int sudoku[SIZE][SIZE]);
bool backtrack(int sudoku[SIZE][SIZE]);
short is_winnable(int sudoku[SIZE][SIZE]);
void clear_notes(char notes[SIZE]);

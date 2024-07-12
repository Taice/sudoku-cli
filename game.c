#include "game.h"
#include "fetch_sudoku.h"
#include "input.h"
#include "interface.h"
#include "sudoku_functions.h"
#include <stdio.h>
#include <threads.h>
#include <unistd.h>

void game(bool index, int lives)
{

    int sudoku[SIZE][SIZE];
	get_sudoku("sudoku.txt", sudoku);
			/*  for (int i = 0; i < SIZE; i++) */
			/*  { */
			/*      for (int j = 0; j < SIZE; j++) */
			/*      { */
			/* sudoku[i][j] = 0; */
			/*      } */
			/*  } */

    char notes[SIZE][SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                notes[i][j][k] = '0';
            }
        }
    }
    int deaths = 0;
    int high = 0, light = 0;
    while (1)
    {
        bool did = false;
        clear_screen();
        printf("%i/%i lives\n", lives - deaths, lives);
        print_notes(notes[high][light]);
        print_sudoku(sudoku, index, high, light);
        int num = get_input(&high, &light);

        if (num < 10)
        {
            sudoku[high][light] = num == -1 ? sudoku[high][light] : num;
            did = num == -1 ? false : true;
        }
        else if (num > 10 && num != -1)
        {
            num -= 10;
            notes[high][light][num - 1] =
                notes[high][light][num - 1] == num + '0' ? ' ' : num + '0';
        }

        if (did)
        {
            int thing = is_winnable(sudoku);
            if (thing == -1)
            {
                deaths++;
                sudoku[high][light] = 0;
                if (lives - deaths == 0)
                {
                    return;
                }
            }
            else if (thing == 0)
            {
                printf("wow you won grats i dont care anymore;");
                break;
            }
            else
            {

                clear_notes(notes[high][light]);
            }
        }
    }
}

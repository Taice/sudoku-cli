#include "input.h"
#include <stdio.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

int getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int get_input(int *row, int *col)
{
    char ch = getch();

    if (ch == 'h')
    {
        if (*col > 0)
        {
            (*col)--;
            return -1;
        }
        return -1;
    }
    if (ch == 'l')
    {
        if (*col < 8)
        {
            (*col)++;
            return -1;
        }
        return -1;
    }
    if (ch == 'j')
    {
        if (*row < 8)
        {
            (*row)++;
            return -1;
        }
        return -1;
    }
    if (ch == 'k')
    {
        if (*row > 0)
        {
            (*row)--;
            return -1;
        }
        return -1;
    }
    if (ch > '0' && ch <= '9')
    {
        return ch - '0';
    }

    if (ch == 'n')
    {
        char number = getch();
        if (number > '0' && number <= '9')
        {
            return number - '0' + 10;
        }
    }

    return -1;
}
double get_time(int *row, int *col)
{
    clock_t start_timer = clock();

    char ch = getch();

    if (ch == 'h')
    {
        if (*col > 0)
        {
            (*col)--;
        }
        clock_t end_time = clock(); // End timing
        double time_spent = (double)(end_time - start_timer) / CLOCKS_PER_SEC;
        return time_spent;
    }
    if (ch == 'l')
    {
        if (*col < 8)
        {
            (*col)++;
            clock_t end_time = clock(); // End timing
            double time_spent =
                (double)(end_time - start_timer) / CLOCKS_PER_SEC;
            return time_spent;
        }
        clock_t end_time = clock(); // End timing
        double time_spent = (double)(end_time - start_timer) / CLOCKS_PER_SEC;
        return time_spent;
    }
    if (ch == 'j')
    {
        if (*row < 8)
        {
            (*row)++;
            clock_t end_time = clock(); // End timing
            double time_spent =
                (double)(end_time - start_timer) / CLOCKS_PER_SEC;
            return time_spent;
        }
        clock_t end_time = clock(); // End timing
        double time_spent = (double)(end_time - start_timer) / CLOCKS_PER_SEC;
        return time_spent;
    }
    if (ch == 'k')
    {
        if (*row > 0)
        {
            (*row)--;
            clock_t end_time = clock(); // End timing
            double time_spent =
                (double)(end_time - start_timer) / CLOCKS_PER_SEC;
            return time_spent;
        }
        clock_t end_time = clock(); // End timing
        double time_spent = (double)(end_time - start_timer) / CLOCKS_PER_SEC;
        return time_spent;
    }
    if (ch > '0' && ch <= '9')
    {
        clock_t end_time = clock(); // End timing
        double time_spent = (double)(end_time - start_timer) / CLOCKS_PER_SEC;
        return time_spent;
    }

    if (ch == 'n')
    {
        char number = getch();
        if (number > '0' && number <= '9')
        {
            clock_t end_time = clock(); // End timing
            double time_spent =
                (double)(end_time - start_timer) / CLOCKS_PER_SEC;
            return time_spent;
        }
    }

    clock_t end_time = clock(); // End timing
    double time_spent = (double)(end_time - start_timer) / CLOCKS_PER_SEC;
    return time_spent;
}

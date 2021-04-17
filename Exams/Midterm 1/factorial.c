/*
===============================================================================

Description: Finds the factorial of an integer

Usage      : ./factorial integer

===============================================================================
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int num, i;
    unsigned long long factorial = 1;

    sscanf (argv[1], "%d", &num);

    // Display error if invalid input is provided
    if (num < 0)
        printf("Error: Invalid number entered\n");
    else
    {
        for (i = 1; i <= num; ++i)
            factorial = factorial * i;

        printf("%llu\n", factorial);
    }

    return 0;
}

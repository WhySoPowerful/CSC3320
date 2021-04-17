/*
===============================================================================

Description: Finds the new integer value of an integer bit shifted left by 3
             bits and added to it's complement

Usage      : ./shift integer

===============================================================================
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int num, lshift3, onescomp;

    sscanf (argv[1], "%d", &num);

    // Shift by 3 bitwise left
    lshift3=num<<3;
    onescomp=~num;

    //printf("Original number       = %d\n", num);
    //printf("Bit-shifted left by 3 = %d\n", lshift3);
    //printf("One's complement      = %d\n", onescomp);
    //printf("\n");
    printf("%d\n", lshift3 + onescomp);

    return 0;
}

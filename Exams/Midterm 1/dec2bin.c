/***********************************************************************************
 *
 * Description: Converts Decimal to binary
 *
 * Usage      : ./dec2bin integer
 *
************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int binarr[10], num, i;

    sscanf(argv[1], "%d", &num);

    // #1 : Get the remainder by dividing the number by 2 and store it in an array
    // #2 : Divide the number by 2
    // #3 : Keep doing #2 till number is greater than 0
    for(i = 0; num > 0; i++)
    {
        binarr[i] = num % 2;
        num = num / 2;
    }


    // Display the result
    for(i = i - 1; i >= 0; i--)
        printf("%d", binarr[i]);

    printf("\n");

    return 0;
}

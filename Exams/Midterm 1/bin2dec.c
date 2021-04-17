/***********************************************************************************
 *
 * Description: Converts Binary to decimal
 *
 * Usage      : ./dec2bin integer (in binary 10 format)
 *
************************************************************************************/

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int binnum, dnum = 0, temp = 0, remainder;

    sscanf(argv[1], "%d", &binnum);

    while (binnum!=0)
    {
        remainder = binnum % 10;
        binnum = binnum / 10;
        dnum = dnum + remainder*pow(2,temp);
        temp++;
    }

    printf("%d\n", dnum);

    return 0;
}

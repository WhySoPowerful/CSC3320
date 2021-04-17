#include<stdio.h>
#include<stdlib.h>

char* strcpy(char* strDest, const char* strSrc)
{
    unsigned i;

    //copying the src string into the dest string
    for (i=0; strSrc[i] != '\0'; ++i)
        strDest[i] = strSrc[i];

    strDest[i]='\0';//appending null to end

    return strDest;//returning pointer to dest string
}

int main()
{
    //declaring necessary variables
    char src[] ="Running Program...";//source string
    char dest[100];//destination string

    printf("Source string: %s\n",src);
    printf("After copying the source string in destination\nDestination string: %s\n",strcpy(dest,src));
    return 0;
}

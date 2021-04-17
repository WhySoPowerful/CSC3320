#include <stdio.h>
void main(int argc, char *argv[])
{ 
        FILE *fp;
        char ch;
        char s[30]="abcdefghijklmnopqrstuvwxyz";
        int count[30],i,max=0,maxp=0; 
        for(i=0;i<30;i++)
        count[i]=0; 
        fp=fopen(argv[1],"r");
        while((ch=getc(fp))!=EOF)
        {
                putchar(ch);
                for(i=0;s[i]!='\0';i++)
                {
                        if(ch==s[i] || ch==(s[i]-32))
                        count[i]++;
                }
        }    
        fclose(fp); 
        for(i=0;s[i]!='\0';i++)   
        if(max<count[i])
        {
                max=count[i];      
                maxp=i;
        }
        printf("\nThe most frequent letter is '%c'. It appeared %d times.\n",s[maxp],max);
}

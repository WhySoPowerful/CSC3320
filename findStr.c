#include <string.h>
#include <stdio.h>

int main(void)
{
    char smallest_word[20];
    char largest_word[20];
    char input_word[20];
    int words_count = 0;
	
    while(1)
    {
        printf("Enter word: ");
    	scanf("%s", input_word);
    	if(words_count == 0)
    	{
            strcpy(smallest_word, input_word);
            strcpy(largest_word, input_word);
    	}

    	else
    	{
            if(strcmp(smallest_word, input_word) > 0)
            {
                strcpy(smallest_word, input_word);
            }
            if(strcmp(largest_word, input_word) < 0)
            {
            	strcpy(largest_word, input_word);
   	    }
    	}

    	words_count += 1;
        if(strlen(input_word) == 4)
    	{
           break;
 	}
    }

    printf("\nSmallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);
    
    return 0;
}

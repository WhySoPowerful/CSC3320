#include <stdlib.h>
#include <stdio.h>

/*
reads all the character of the given file file_name and counts lines, words and character.
*/
void read_file(char* file_name, int* words, int* character, int* lines);

int main(int argc, char** argv){
    int words, character, lines;
    read_file("text.txt", &words, &character, &lines);
    printf("Lines: %i\nWords: %i\nCharacter: %i\n", lines, words, character);
}

void read_file(char* file_name, int* words, int* character, int* lines){
    //open the file
    FILE* fp = fopen(file_name, "r");

    //file does not exist
    if(fp == NULL){
        perror("Error: ");
        return;
    }

    //flag if the current set of character is a word
    int is_word = 0;
    //current character read
    char current;
    //init all the lines, words and character to 0
    *words = *character = *lines = 0;
    //read until the end of the file
    while((current = fgetc(fp)) != EOF){
        //if a space appeares and the prev character was not a character a new word has ended
        if(current == ' '){
            is_word = 0;
        }else if(!is_word){
            *words += 1;
            is_word = 1;
        }
        *character += 1;
        //add new lines if the line ends
        if(current == '\n'){
            *lines += 1;
            is_word = 0;
        }
    }
    //close the file
    fclose(fp);
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
sorts the string array arr
ascending when 1
descending when 0
*/
void sort_alphabetic(char** arr, int length, int ascending);

/*
prints the string array to the console
*/
void print_array(char** arr, int length);

int main(){

    char* arr[] = {"Systems", "Programming", "Deep", "Learning", "Internet", "Things", "Robotics", "Course"};
    int length = 8;

    printf("Array to be sorted: ");
    print_array(arr, length);
    
    char input = 0;
    do {
        //only print the message if the user typed something else than enter
        if(input != '\n')
            printf("Enther a to sort Ascending or d for Descending\n");
        scanf("%c", &input);
        //when a lower case is typed we want to convert it to upper
        if(input >= 'a')
            input -= 'a' - 'A';
        //keep requesting the order until a valid input
    }while(input != 'A' && input != 'D');

    //sort the array with the given input
    //because ascending is 1 (or true) we can just compare if the input is 'A'
    sort_alphabetic(arr, length, input == 'A');

    //print the sorted array
    printf("Sorted Array: ");
    print_array(arr, length);
    return 0;
}

void print_array(char** arr, int length){
    //go through every element and print it
    for(int i = 0; i < length; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

void sort_alphabetic(char** arr, int length, int ascending) {

    /*
    go through every element and find the highest or lowest in the array
    append that element to the start of the array
    repeat until you are at the end of the array
    */
    for(int i = 0; i < length; i++){
        int index = i;
        for(int k = i; k < length; k++){
            //finding the highest or the lowest element
            if(ascending) {
                //NOTE: strcmp returns whether the first argument is befor the second one in alphabetic order
                if(strcmp(arr[index], arr[k]) > 0)
                    index = k;
            }else{
                if(strcmp(arr[index], arr[k]) < 0)
                    index = k;
            }
        }
        //swap the two elements
        char* buffer = arr[i];
        arr[i] = arr[index];
        arr[index] = buffer;
    }
}

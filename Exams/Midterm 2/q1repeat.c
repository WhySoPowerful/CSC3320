#include <stdlib.h>
#include <stdio.h>

/*
sorts the array arr
ascending when 1
descending when 0
*/
void sort_numeric(double* arr, int length, int ascending);

/*
prints the array to the console
*/
void print_array(double* arr, int length);

int main(){
    int length;
    double* arr;

    printf("Enter the length of the array\n");
    scanf("%i", &length);

    //creates a new array with the given length
    arr = (double*)malloc(sizeof(double) * length);

    for(int i = 0; i < length; i++){
        //sets the element to a random number between 50 and -50
        arr[i] = (rand() / (float)RAND_MAX) * 100 - 50;
    }

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
    sort_numeric(arr, length, input == 'A');

    //print the sorted array
    printf("Sorted Array: ");
    print_array(arr, length);

    free(arr);
    return 0;
}

void print_array(double* arr, int length){
    //go through every element and print it
    for(int i = 0; i < length; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

void sort_numeric(double* arr, int length, int ascending) {

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
                if(arr[index] > arr[k])
                    index = k;
            }else{
                if(arr[index] < arr[k])
                    index = k;
            }
        }
        //swap the two elements
        double buffer = arr[i];
        arr[i] = arr[index];
        arr[index] = buffer;
    }
}
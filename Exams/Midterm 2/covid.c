#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*
stores all relevant information about the user
is a linked list and has a pointer to the next element in the list
next is NULL when its the end
*/
typedef struct User{
    char* first_name;
    char* last_name;
    char* birth;
    char* sex;
    int dose;
    int age;
    char* prev_dose;
    char* vaccine;
    char* zipcode;
    struct User* next;
}User;

/*
displays every person
*/
void retrieve(User* users);
/*
displays the information of a person
*/
void print_user(User* user);
/*
returns a new user and init the user
*/
User* registerPerson();
/*
appends a user to the linked list
*/
void appendUser(User* users);
/*
returns 1 if the string is a valid date
and sets the year to the year of the date
*/
int is_date(char* string, int* year);
/*
returns if a string is in an array of strings
return 1 if true 0 when false
*/
int contains(char* string, char** list, int length);
/*
generates the code of the specific user
*/
void generate_code(User* user);

/*
frees all allocated memory of the linkes list
*/
void free_user(User* users);

/*
appends the user to the linked list
returns the new start of the linked list
*/
User* append_user(User* users, User* user);

int main(){
    User* users = NULL;
    int input = 0;
    do {
        if(input != '\n')
            printf("Enter \t1 to register a new User\n\t2 to show all registered users\n\t3 to exit the program\n");
        input = getchar();
        User* new;
        switch(input){
            case '1':
                new = registerPerson();
                users = append_user(users, new);
                break;
            case '2':
                retrieve(users);
                break;
        }
    }while(input != '3');
    free_user(users);
    return 0;
}

User* append_user(User* users, User* user){
    if(users == NULL)
        return user;
    //goes to the end of the list and addes the user
    while(users->next != NULL)
        users = users->next;
    users->next = user;
    return users;
}

void free_user(User* users){
    while(users != NULL){
        //first free every other allocalted memory then the element
        User* tmp = users->next;
        free(users->birth);
        free(users->first_name);
        free(users->last_name);
        free(users->prev_dose);
        free(users->vaccine);
        free(users->sex);
        free(users->zipcode);
        free(users);
        users = tmp;
    }
}

void generate_code(User* user){
    //9 elements for \0
    user->zipcode = (char*)malloc(sizeof(char) * 8 + 1);
    //generate the code according to the format
    user->zipcode[0] = user->first_name[0];
    user->zipcode[1] = user->last_name[0];

    //append the age to the zip code at position 2
    sprintf(user->zipcode + 2, "%i", user->age); 
    user->zipcode[4] = user->vaccine[0];
    //append the number of the zipcode at position 5
    int zipcode;
    do{
        printf("Please enter the last 3 numbers of your zipcode.\n");
        scanf("%i", &zipcode);
        sprintf(user->zipcode + 5, "%i", zipcode);
    }while(zipcode < 100 || zipcode > 999);
    user->zipcode[8] = '\0';
}

int contains(char* string, char** list, int length){
    for(int i = 0; i < length; i++)
        if(strcmp(string, list[i]) == 0) //if strcmp == 0 the strings are equal
            return 1;
    return 0;
}

User* registerPerson(){
    User* new = (User*)malloc(sizeof(User));
    new->next = NULL;
    new->zipcode = NULL;
    new->prev_dose = NULL;
    char input[1024];

    printf("Please enter your first name\n");
    scanf("%1024s", input);
    //allocate new string with length + 1 for \0
    new->first_name = (char*)malloc(sizeof(char) * strlen(input) + 1);
    //we need to copy the string because we only use one string as an input
    //otherwise it would be changed
    strcpy(new->first_name, input);

    printf("Please enter your last name\n");
    scanf("%1024s", input);
    new->last_name = (char*)malloc(sizeof(char) * strlen(input) + 1);
    strcpy(new->last_name, input);

    //request until its valid
    int valid;
    do {
        printf("Please enter your Date of Birth (mm/dd/yyyy)\n");
        scanf("%1024s", input);
        new->birth = (char*)malloc(sizeof(char) * strlen(input) + 1);
        strcpy(new->birth, input);
        valid = is_date(input, &new->age);
        new->age = 2021 - new->age;
        if(!valid){
            printf("Invalid date!\n");
            free(new->birth);
        }
    }while(!valid);

    char* types[] = {"Male", "Female", "Do not wish to identify"};
    do {
        printf("Please enter your sex (Male, Female, Do not wish to identify)\n");
        scanf("%1024s", input);
        new->sex = (char*)malloc(sizeof(char) * strlen(input) + 1);
        strcpy(new->sex, input);
        //if the input is a sex
        valid = contains(input, types, 3);
        if(!valid)
        {
            printf("Invalid sex!\n");
            free(new->sex);
        }
    }while(!valid);

    do{
        printf("Please enter your Dose number (1 or 2)\n");
        scanf("%i", &new->dose);
    }while(new->dose != 1 && new->dose != 2);

    //only ask if the for the prev date if dose number is 2
    if(new->dose == 2)
        do {
            printf("Please enter your Date of previous dose (mm/dd/yyyy)\n");
            scanf("%1024s", input);
            new->prev_dose = (char*)malloc(sizeof(char) * strlen(input) + 1);
            strcpy(new->prev_dose, input);
            valid = is_date(input, NULL);
            if(!valid){
                printf("Invalid date!\n");
                free(new->prev_dose);
            }            
        }while(!valid);

    char* vacTypes[] = {"Pfizer", "Moderna", "Johnson&Johnson"};
    do {
        printf("Please enter your Type of vaccine (Pfizer, Moderna, Johnson&Johnson)\n");
        scanf("%1024s", input);
        new->vaccine = (char*)malloc(sizeof(char) * strlen(input) + 1);
        strcpy(new->vaccine, input);
        //if the input is a vaccine
        valid = contains(input, vacTypes, 3);
        if(!valid){
            printf("Invalid Type of vaccine!\n");
            free(new->vaccine);
        }
    }while(!valid);

    generate_code(new);

    return new;
}

void retrieve(User* users){
    //print every user in the linked list
    printf("Registered Users: \n");
    printf("-------------------\n");
    while(users != NULL){
        print_user(users);
        users = users->next;
        printf("-------------------\n");
    }
}

void print_user(User* user){
    printf("Name: %s %s\nBirth: %s (Age: %i)\nSex: %s \nDose number: %i \nDate of previous dose: %s \nType of vaccine: %s \nZipcode: %s \n",
     user->first_name, user->last_name, user->birth, user->age, user->sex, user->dose, user->prev_dose, user->vaccine, user->zipcode);
}

int is_date(char* string, int* year)
{
    char *endptr;
    int base = 10;
    int month, day;
    //converts the string to the seperate int values
    month = strtol(string, &endptr, base);
    //invalid month
    if(month < 1 || month > 12)
        return 0;
    if (endptr[0] == '/') {
        day = strtol(endptr + 1, &endptr, base);
        //invalid day
        if(day <= 0 || day > 31)
            return 0;
    } else {
        return 0;
    }
    if (endptr[0] == '/') {
        if(year != NULL)
            *year = strtol(endptr + 1, &endptr, base);
    } else {
        return 0;
    }
    return 1;
}

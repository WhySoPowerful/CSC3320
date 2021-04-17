#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char* string, int strLength);
void removeSpaces(char* string);
void toLowercase(char* string, int strLength);

int main(void) {
  printf("Enter a message:\n");
  // Allocating plenty of space for the message
  size_t messageLength = 100;
  char* message = (char*)malloc(messageLength * sizeof(char));
  getline(&message, &messageLength, stdin);

  // Get original copy of the string for printing purposes
  char* original;
  strcpy(original, message);
  // Remove the newline character from the string copy
  original[strlen(original) - 1] = '\0';
  removeSpaces(message);

  if (isPalindrome(message, strlen(message)))
    printf("%s is a palindrome\n", original);
  else
    printf("%s is not a palindrome\n", original);
  free(message);
  return 0;
}

int isPalindrome(char* string, int strLength) {
  // Convert all characters in the string to lowercase
  toLowercase(string, strLength);
  // Pointer at the beginning and the end of the string
  int i = 0;
  int j = strLength - 1;
  // Iterate until the pointers pass each other
  while (j > i) {
    // Ignore any special characters in the string by shifting the pointer
    // until the next alphabetical character
    while (!isalpha(string[i])) ++i;
    while (!isalpha(string[j])) --j;
    printf("string[i] = %c string[j] = %c\n", string[i], string[j]);
    // Compare if the beginning and end characters are equivalent
    if (string[i] != string[j])
      return 0;
    // Move the pointers inward
    ++i;
    --j;
  }
  return 1;
}

void removeSpaces(char* string) {
  int i, j = 0;
  for (i = 0; string[i]; ++i) {
    // Shift elements to the right of any whitespace/tabs/newlines
    // to one position left
    string[i] = string[i + j];
    if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
      ++j;
      --i;
    }
  }
}

void toLowercase(char* string, int strLength) {
  for (int i = 0; i < strlen(string); ++i) {
    if (string[i] >= 65 && string[i] <= 90) {
      // ASCII table reference uppercase -> lowercase difference is 32
      string[i] = (char)(string[i] + 32);
    }
  }
}

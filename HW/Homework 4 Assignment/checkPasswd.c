// File: checkPasswd.c
// For Part 1: Questions 1 & 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Steps: get password input, check password for appropriate flags, display message
char* getPassword();
void checkCriteriaFlags(char* string);
int calcDeductions(int strLength, int lowercaseFlag, int uppercaseFlag, int numberFlag, int charFlag);
void displayPasswordSafety(int deductions);

int main(void) {
  char* userPassword = getPassword();

  // Deallocate the memory location that was assigned
  free(userPassword);
  return 0;
}

char* getPassword() {
  printf("Enter a password: ");
  // Init a pointer to be of at least 10 characters
  char* password = (char*)malloc(10 * sizeof(char));
  scanf("%s", password);
  checkCriteriaFlags(password);
  return password;
}

void checkCriteriaFlags(char* string) {
  // Criteria flags: password should contain a lowercase, uppercase, number,
  // and no consecutive characters
  int missingLowercase = 1;
  int missingUppercase = 1;
  int missingNumber = 1;
  int hasConsecutiveChars = 0;

  int stringLength = strlen(string);
  for (int i = 0; i < stringLength; ++i) {
    // follows the ascii table when comparing
    // numbers range: 48 - 57
    // uppercase range: 65 - 90
    // lowercase range: 97 - 122
    char current = string[i];

    // Can only check for consecutive chars if there are at least 3 chars
    // AKA the pointer must be greater than index 1
    if (i > 1) {
      char prev = string[i - 1];
      char prev2 = string[i - 2];
      // difference b/w last char and middle char = 1,  EX: (C - B = 1)
      // difference b/w last char and first char = 2, EX: (C - A = 2)
      // flip flag on if the two statements above are true
      if ((current - prev) == 1 && (current - prev2) == 2) {
        hasConsecutiveChars = 1;
      }
    }
    // Check for number in string, switch flag off if exists
    if (current >= 48 && current <= 57) {
      missingNumber = 0;
    }
    // Check for uppercase letter in string, switch flag off if exists
    else if (current >= 65 && current <= 90) {
      missingUppercase = 0;
    }
    // Check for lowercase letter in string, switch flag off if exists
    else if (current >= 97 && current <= 122) {
      missingLowercase = 0;
    }
  }
  // Calculate the number of deductions based on active flags
  int totalDeductions = calcDeductions(stringLength, missingLowercase,
      missingUppercase, missingNumber, hasConsecutiveChars);
  displayPasswordSafety(totalDeductions);
}

int calcDeductions(int strLength, int lowercaseFlag, int uppercaseFlag, int numberFlag, int charFlag) {
  const int MIN_REQ_LENGTH = 10;
  const int MISSING_CHAR_POINT_DEDUCTION = 5;

  int deductions = 0;
  if (strLength < MIN_REQ_LENGTH) {
    deductions += MISSING_CHAR_POINT_DEDUCTION * (MIN_REQ_LENGTH - strLength);
  }
  deductions += (20 * charFlag) +\
                (20 * lowercaseFlag) +\
                (20 * uppercaseFlag) +\
                (20 * numberFlag);
  return deductions;
}

void displayPasswordSafety(int deductions) {
  // Max deductions allowed are 30 points
  const int MAX_POINT_DEDUCTIONS = 30;
  if (deductions > MAX_POINT_DEDUCTIONS) {
    printf("Total deductions: %d\nThis password is unsafe! Please reset.\n",
        deductions);
  }
  else {
    printf("This password is safe.\n");
  }
}

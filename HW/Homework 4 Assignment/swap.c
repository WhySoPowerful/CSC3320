#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* s1, char* s2);

int main() {
  size_t defaultSize = 100;
  // Prompt and get the two sentences needed
  printf("Enter one sentence:\n");
  char* sentence1 = (char*)malloc(defaultSize * sizeof(char));
  getline(&sentence1, &defaultSize, stdin);
  printf("Enter another sentence of equal length:\n");
  char* sentence2 = (char*)malloc(defaultSize * sizeof(char));
  getline(&sentence2, &defaultSize, stdin);

  // Strip newline characters from both sentences
  sentence1[strlen(sentence1) - 1] = 0;
  sentence2[strlen(sentence2) - 1] = 0;

  // Messages before swap
  printf("Sentence 1 after: %s\n", sentence1);
  printf("Sentence 2 after: %s\n", sentence2);

  swap(sentence1, sentence2);

  // Messages after swap
  printf("Sentence 1 after: %s\n", sentence1);
  printf("Sentence 2 after: %s\n", sentence2);
  return 0;
}

void swap(char* s1, char* s2) {
  // Don't swap unless the strings given are of equal length
  if (strlen(s1) != strlen(s2)) {
    printf("Sentences are not of equal length. Cannot swap.\n");
    return;
  }
  int length = strlen(s1);
  for (int i = 0; i < length; ++i) {
    s1[i] = s1[i] ^ s2[i]; // turns s1[i] into a bitmask
    s2[i] = s1[i] ^ s2[i]; // swap variable between s1 and s2
    s1[i] = s1[i] ^ s2[i]; // complete final swap
  }
}

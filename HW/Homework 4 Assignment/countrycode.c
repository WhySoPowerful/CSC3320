#include <stdio.h>

struct DialingCode {
  char* country;
  int code;
};

// Predefining a global struct array of DialingCode's
const struct DialingCode countryCodes[] = {
  {"Argentina",            54}, {"Bangladesh",      880}, 
  {"Brazil",               55}, {"Burma (Myanmar)",  95},
  {"China",                86}, {"Colombia",         57},
  {"Congo, Dem. Rep. of", 243}, {"Egypt",            20},
  {"Ethiopia",            251}, {"France",           33},
  {"Germany",              49}, {"India",            91},
  {"Indonesia",            62}, {"Iran",             98},
  {"Italy",                39}, {"Japan",            81},
  {"Mexico",               52}, {"Nigeria",         234},
  {"Pakistan",             92}, {"Phillippines",     63},
  {"Poland",               48}, {"Russia",            7},
  {"South Africa",         27}, {"South Korea",      82},
  {"Spain",                34}, {"Sudan",           249},
  {"Thailand",             66}, {"Turkey",           90},
  {"Ukraine",             380}, {"United Kingdom",   44},
  {"United States",         1}, {"Vietnam",          84}
};

// Displays all the country and country codes within the existing list of codes
void printCountryCodes();

int main() {
  // Gets the total number of elements in the array
  int structSize = sizeof(countryCodes) / sizeof(countryCodes[0]);
  int code;
  printf("Enter a country code from the following list:\n");
  printCountryCodes(structSize);
  scanf(" %d", &code);
  int found = 0;
  int indexFound = 0;
  for (int i = 0; i < structSize && !found; ++i) {
    if (code == countryCodes[i].code) {
      found = 1;
      indexFound = i;
    }
  }
  if (found) {
      printf("You have selected %s with code #%d\n", 
          countryCodes[indexFound].country, countryCodes[indexFound].code);
  }
  else {
    printf("Could not find country with code #%d\n", code);
  }
  return 0;
}

void printCountryCodes(int size) {
  for (int i = 0; i < size; ++i) {
    printf("%s %d\n", countryCodes[i].country, countryCodes[i].code);
  }
  printf("\n");
}

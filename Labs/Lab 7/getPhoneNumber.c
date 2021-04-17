#include <stdio.h>

int main (void)
{
  int a1, b1, c1;
  printf("Enter phone number [(999)999-9999]: ");
  scanf("(%d)%d-%d", &a1, &b1, &c1);
  printf("You entered %d-%d-%d\n", a1, b1, c1);

  return 0;
}

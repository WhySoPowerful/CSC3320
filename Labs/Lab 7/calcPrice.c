#include <stdio.h>

int main ()
{
  int item_number;
  double unit_price;
  int quantity;
  char purchase_date[12];

  printf("Enter item number:");
  scanf("%d", &item_number);

  printf("Enter unit price:");
  scanf("%lf", &unit_price);

  printf("Enter quantity:");
  scanf("%d", &quantity);

  printf("Enter purchase date (mm/dd/yyyy):");
  scanf("%s", &purchase_date);


  printf("Item\tUnit Price\tQTY\tPurchase Date\tTotal Amount\n");
  printf("%d\t$%9.2lf\t%d\t%s\t$%9.2lf\n\n", item_number, unit_price, quantity,purchase_date, unit_price * quantity);

  return 0;
}

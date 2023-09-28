#include "complex.h"
#include <stdio.h>

int main(void) {
  Complex num1, num2;
  printf("Enter the first real num : ");
  scanf("%d", &num1.real);
  printf("Enter the first imaginary num : ");
  scanf("%d", &num1.imaginary);

  printf("Enter the second real number:");
  scanf("%d", &num2.real);
  printf("Enter the second imaginary number:");
  scanf("%d", &num2.imaginary);

  Complex add = addComplex(num1, num2);
  printComplex(add);
  return 0;
}

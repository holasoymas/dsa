#include <stdio.h>

typedef struct {
  int whole;
  int frac;
} Real;

void printReal(Real n) { printf("Real = %d.%d\n", n.whole, n.frac); }

int main(void) {
  Real num1, num2;
  num1.whole = 12;
  num1.frac = 32;
  printReal(num1);
  return 0;
}

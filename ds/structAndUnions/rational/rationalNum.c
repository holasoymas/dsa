#include "rational.h"
#include <stdio.h>

int main(void) {

  Rational num1 = (Rational){1032, 1976};
  Rational num2 = (Rational){122, 248};

  Rational reduced = reduceRational(num1);
  Rational red2 = reduceRational(num2);
  // Rational ref = reduceRationalbyRef(&num1);
  printf("Reudced num are %d and %d\n", reduced.numenator, reduced.denomenator);
  // printf("Reudced num are %d and %d\n", ref.numenator, ref.denomenator);
  printf("Reudced num are %d and %d\n", red2.numenator, red2.denomenator);
  int eql = areEqual(&num1, &num2);
  printf("Are eql = %d\n", eql);
  Rational multiply = multiplyRational(num1, num2);
  printRational(multiply);
  return 0;
}

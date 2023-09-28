#include "rational.h"
#include <stdio.h>
#define TRUE 1
#define FALSE 0

// NOTE: Using Euclid's algorithm to find the simplest version of Rational num

Rational reduceRational(Rational rational) {
  int a, b, rem;
  Rational tmp;

  if (rational.numenator >
      rational.denomenator) { // let "a"" be a larger among 2 numbers
    a = rational.numenator;
    b = rational.denomenator;
  } else {
    a = rational.denomenator;
    b = rational.numenator;
  }
  while (b != 0) {
    rem = a % b;
    a = b;
    b = rem;
  }
  tmp.numenator = rational.numenator / a;
  tmp.denomenator = rational.denomenator / a;
  return tmp;
}

// NOTE: (*rational).numenator === rational->numenator

Rational reduceRationalByRef(Rational *rational) {
  int a, b, rem;
  Rational tmp;

  if (rational->numenator >
      rational->denomenator) { // let "a"" be a larger among 2 numbers
    a = (*rational).numenator;
    b = rational->denomenator;
  } else {
    a = rational->denomenator;
    b = rational->numenator;
  }
  while (b != 0) {
    rem = a % b;
    a = b;
    b = rem;
  }
  tmp.numenator = rational->numenator / a;
  tmp.denomenator = rational->denomenator / a;
  return tmp;
}

int areEqual(Rational *rational1, Rational *rational2) {
  Rational r1 = reduceRational(*rational1);
  Rational r2 = reduceRational(*rational2);
  if (r1.numenator == r2.numenator && r1.denomenator == r2.denomenator) {
    return (TRUE);
  }
  return (FALSE);
}

int areEqualWithoutReduce(Rational r1, Rational r2) {
  Rational tmp1, tmp2;
  tmp1.numenator = r1.numenator * r2.numenator;
  tmp1.denomenator = r1.denomenator * r2.numenator;

  tmp2.numenator = r2.numenator * r1.numenator;
  tmp2.denomenator = r2.denomenator * r1.numenator;

  if (tmp1.numenator == tmp2.numenator &&
      tmp1.denomenator == tmp2.denomenator) {
    return (TRUE);
  }
  return (FALSE);
}

Rational multiplyRational(Rational r1, Rational r2) {
  Rational tmp;
  tmp.numenator = (r1.numenator * r2.numenator);
  tmp.denomenator = (r1.denomenator * r2.denomenator);
  reduceRational(tmp);
  return tmp;
}

Rational divideRational(Rational r1, Rational r2) {
  Rational tmp;
  tmp.numenator = (r1.numenator * r2.denomenator);
  tmp.denomenator = (r1.denomenator * r2.numenator);
  reduceRational(tmp);
  return tmp;
}

Rational addRational(Rational r1, Rational r2) {
  Rational tmp;
  Rational n1 = reduceRational(r1);
  Rational n2 = reduceRational(r2);
  tmp.numenator =
      (r1.numenator * r2.denomenator) + (r2.numenator * r1.denomenator);
  tmp.denomenator = r1.denomenator * r2.denomenator;
  return tmp;
}

void printRational(Rational r) {
  printf("Rational = %d // %d\n", r.numenator, r.denomenator);
}

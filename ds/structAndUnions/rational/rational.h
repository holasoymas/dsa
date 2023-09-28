// rational.h
#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct {
  int numenator;
  int denomenator;
} Rational;

Rational reduceRational(Rational input);
Rational reduceRationalbyRef(Rational *input);
int areEqual(Rational *rational1, Rational *rational2);
Rational addRational(Rational r1, Rational r2);
Rational multiplyRational(Rational r1, Rational r2);
Rational divideRational(Rational r1, Rational r2);
void printRational(Rational r);
#endif // RATIONAL_H

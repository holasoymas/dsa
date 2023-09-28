#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
  int real;
  int imaginary;
} Complex;

Complex addComplex(Complex c1, Complex c2);
void printComplex(Complex c1);

#endif // COMPLEX_H

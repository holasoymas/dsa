#include "complex.h"
#include <stdio.h>

Complex addComplex(Complex c1, Complex c2) {
  Complex tmp;

  int addReal = c1.real + c2.real;
  int addImaginary = c1.imaginary + c2.imaginary;

  tmp.real = addReal;
  tmp.imaginary = addImaginary;
  return tmp;
}

void printComplex(Complex n) {
  printf("Complex = %d + %di\n", n.real, n.imaginary);
}

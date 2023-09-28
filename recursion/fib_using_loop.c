#include <stdio.h>

int get_fib_num(int n) {

  int lofib, hifib, x;

  if (n <= 1) {
    return n;
  }
  lofib = 0;
  hifib = 1;
  for (int i = 2; i <= n; i++) {
    x = lofib;     // store the value of (n -2) in x
    lofib = hifib; // store the value of hifib in lofib so that next time it is
                   // lofib
    hifib = x + lofib; // add the lofib and highfib to get the fibonacchi
  }
  return hifib;
}

int main(void) {
  int n = 6;
  int fib = get_fib_num(n);
  printf("The fib of %d is %d\n", n, fib);
  return 0;
}

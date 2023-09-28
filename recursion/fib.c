#include <stdio.h>

int fib(int n) {
  if (n <= 1) {
    return 1;
  }
  return fib(n - 1) + fib(n - 2);
}

int main(void) {
  int f;
  printf("Enter the fib number of :");
  scanf("%d", &f);
  int fibo = fib(f);
  printf("The fib of %d is %d\n", f, fibo);
  return 0;
}

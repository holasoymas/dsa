#include <stdio.h>

int factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main(void) {
  int n;
  printf("Enter the num upto factorial of :\n");
  scanf("%d", &n);
  int fact = factorial(n);
  printf("the factorial of %d is %d\n", n, fact);
  return 0;
}

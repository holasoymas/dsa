#include <stdio.h>

int multiply(int n, int y) {
  if (y <= 1) {
    return n;
  }
  return multiply(n, y - 1) + n;
}

int add(int a, int b) {
  if (b <= 1) {
    return a++;
  }
  return a + add(a, b - 1);
}

int main(void) {
  int a, b;
  printf("Enter the value of a and b : \n");
  scanf("%d %d", &a, &b);
  int total = multiply(a, b);
  printf("Total = %d\n", total);
  return 0;
}

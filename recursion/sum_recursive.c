#include <stdio.h>

int recursiveSum(int num) {

  if ((num / 10) == 0) {
    return num;
  }
  return num % 10 + recursiveSum(num / 10);
}

int main() {
  int num;
  printf("Enter the number : \n");
  scanf("%d", &num);
  int sum = recursiveSum(num);
  printf("THE SUM IS %d\n", sum);
  return 0;
}

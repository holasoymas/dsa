#include <stdio.h>

int reverse(int num) {
  int rev = 0, rem;
  int nums = num;
  while (nums != 0) {
    rem = nums % 10;
    nums = nums / 10;
    rev = (rev * 10) + rem;
  }

  return rev;
}

int recursiveReverse(int n, int rev) {
  int num = n;
  if (num == 0) {
    return rev;
  }
  return recursiveReverse(num / 10, rev * 10 + (num % 10));
}

int main() {
  int num;
  int sumup = 0;
  printf("Enter the num : \n");
  scanf("%d", &num);
  int rev = recursiveReverse(num, 0);
  printf("THe reverse is %d\n", rev);
  return 0;
}

#include <stdio.h>

void towers(int, char, char, char);

int main() {
  int n;
  printf("Enter the number of tower : \n");
  scanf("%d", &n);
  towers(n, 'A', 'C', 'B');
  return 0;
}

void towers(int n, char from, char to, char aux) {
  if (n == 1) {
    printf("Move disk %d from ring %c to ring %c\n", n, from, to);
    return;
  }
  towers(n - 1, from, aux, to);
  printf("Move disk %d from ring %c to ring %c\n", n, from, to);
  towers(n - 1, aux, to, from);
}

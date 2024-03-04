#include <stdio.h>
#define MAX 40
#define UNKNOWN -1

// NOTE: Binomial Cofficient using recurrence formulat
//  (n k) = (n -1, k - 1) + (n -1 , k)

// Row 0 :           1
// Row 1 :         1   1
// Row 2 :       1   2   1
// Row 3 :      1   3   3   1
// Row 4 :    1   4   6   4   1
// Row 5 :  1   5  10  10   5   1

int binomial_cofficient(int n, int k) {
  int bc[MAX + 1][MAX + 1]; // table of binomial cofficients
  int i, j;                 // counters

  for (int i = 0; i <= n; i++) // choosing the first item as 1
    bc[i][0] = 1;
  for (int j = 0; j <= n; j++) // choosing the last item as 1
    bc[j][j] = 1;

  for (i = 1; i <= n; i++) {
    for (j = 1; j < n; j++) {
      bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
    }
  }
  return bc[n][k];
};

int bc_recursive(int bc[MAX + 1][MAX + 1], int n, int k) {
  if (bc[n][k] == UNKNOWN) {
    bc[n][k] = bc_recursive(bc, n - 1, k - 1) + bc_recursive(bc, n - 1, k);
  }
  return bc[n][k];
}

int bc_driver(int n, int k) {
  int bc[MAX + 1][MAX + 1]; // table of binomial cofficients
  int i, j;                 // counters

  for (int i = 0; i <= n; i++) // choosing the first item as 1
    bc[i][0] = 1;

  for (int j = 0; j <= n; j++) // choosing the last item as 1
    bc[j][j] = 1;

  for (i = 0; i <= n; i++) { // setting other field as -1 for for betterment
    for (j = 0; j <= n; j++) {
      if (bc[i][j] != 1) {
        bc[i][j] = UNKNOWN;
      }
    }
  }

  return bc_recursive(bc, n, k);
}

int main() {
  int n = 15;
  int k = 3;
  int bc = binomial_cofficient(n, k);
  int bc_rec = bc_driver(n, k);
  printf("%d\n", bc);
  printf("%d\n", bc_rec);
  return 0;
}

#include <stdio.h>

// NOTE: Here we can only go down and right

//     3   2   1
//    --- --- ---
//  3| * |   |   |
//    --- --- ---
//  2|   |   |   |
//    --- --- ---
//  1|   |   |   |
//    --- --- ---

int countPaths(int row, int column) {
  // if row or column is one there is only one way to go to the destination so
  // return 1
  if (1 == row || 1 == column)
    return 1;

  int down = countPaths(row - 1, column);
  int right = countPaths(row, column - 1);

  return down + right;
}

int main() {
  int count = countPaths(3, 3);
  printf("%d\n", count);
  return 0;
}

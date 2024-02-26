#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10

// Vertial - V
// Horizontal - H
// Diagonal - D

void printPathIncludingDiagonal(char *path, int row, int col) {
  if (row == 1 && col == 1) {
    printf("%s\n", path);
  }

  char row_path[MAX_LENGTH];
  char col_path[MAX_LENGTH];
  char diag_path[MAX_LENGTH];
  strcpy(row_path, path);
  strcpy(col_path, path);
  strcpy(diag_path, path);

  if (row > 1 && col > 1) {
    // concatnating the old path with the new unique path
    printPathIncludingDiagonal(strncat(diag_path, "D", 1), row - 1, col - 1);
  }

  if (row > 1) {
    printPathIncludingDiagonal(strncat(row_path, "V", 1), row - 1, col);
  }

  if (col > 1) {
    printPathIncludingDiagonal(strncat(col_path, "H", 1), row, col - 1);
  }
}

int main() {
  char path[MAX_LENGTH] = "";
  printPathIncludingDiagonal(path, 3, 3);
  return 0;
}

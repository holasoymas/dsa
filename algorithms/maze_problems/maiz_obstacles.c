#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10
#define ROW 3
#define COL 3
#define TRUE 1
#define FALSE 0

// Vertial - V
// Horizontal - H
// Diagonal - D

int isObstacle(int arr[ROW][COL], int row, int col) {
  return arr[row][col] == FALSE;
}

void printPathIncludingDiagonal(int arr[ROW][COL], char *path, int row,
                                int col) {
  if (row == (ROW - 1) && col == (COL - 1)) {
    printf("%s\n", path);
  }

  char row_path[MAX_LENGTH];
  char col_path[MAX_LENGTH];
  char dig_path[MAX_LENGTH];
  strcpy(row_path, path);
  strcpy(col_path, path);
  strcpy(dig_path, path);

  if (isObstacle(arr, row, col)) {
    return;
  }

  if (row < (ROW - 1) && col < (COL - 1)) {
    // concatnating the old path with the new unique path and the 3rd arg is
    // the length of the "to be concanitated string"
    printPathIncludingDiagonal(arr, strncat(dig_path, "D", 1), row + 1,
                               col + 1);
  }

  if (row < (ROW - 1)) {
    printPathIncludingDiagonal(arr, strncat(row_path, "V", 1), row + 1, col);
  }

  if (col < (COL - 1)) {
    printPathIncludingDiagonal(arr, strncat(col_path, "H", 1), row, col + 1);
  }
}

int main() {
  int maiz[ROW][COL] = {
      {TRUE, TRUE, TRUE}, {TRUE, FALSE, TRUE}, {TRUE, TRUE, TRUE}};

  char path[MAX_LENGTH] = "";
  printPathIncludingDiagonal(maiz, path, 0, 0);
  return 0;
}

#include <stdio.h>
#include <string.h>

// D - DOWN
// R - RIGHT
// L - LEFT
// U - UP
// X - DIAGONAL

#define MAX_LENGTH 10
#define ROW 3
#define COL 3
#define TRUE 1
#define FALSE 0

int isObstacle(int arr[ROW][COL], int row, int col) {
  return arr[row][col] == FALSE;
}

void printPathMatrix(int pathNum[ROW][COL]) {
  for (int i = 0; i < ROW; i++) {
    printf("[ ");
    for (int j = 0; j < COL; j++) {
      printf("%d, ", pathNum[i][j]);
    }
    printf("],\n");
  }
}

void printAllPath(int arr[ROW][COL], char *path, int row, int col,
                  int pathNum[ROW][COL], int steps) {
  if (row == (ROW - 1) && col == (COL - 1)) {
    pathNum[row][col] = steps;
    printPathMatrix(pathNum);
    printf("%s\n", path);
    printf("\n");
    return;
  }

  char down_path[MAX_LENGTH];
  char right_path[MAX_LENGTH];
  char left_path[MAX_LENGTH];
  char up_path[MAX_LENGTH];
  char dig_path[MAX_LENGTH];

  strcpy(down_path, path);
  strcpy(right_path, path);
  strcpy(left_path, path);
  strcpy(up_path, path);
  strcpy(dig_path, path);

  if (isObstacle(arr, row, col)) {
    return;
  }

  // marking the visited path as FALSE so it doesn't go to the same path on the
  // same function call
  arr[row][col] = FALSE;
  pathNum[row][col] = steps;

  if (row < (ROW - 1) && col < (COL - 1)) {
    // concatnating the old path with the new unique path and the 3rd arg is
    // the length of the "to be concanitated string"
    printAllPath(arr, strncat(dig_path, "X", 1), row + 1, col + 1, pathNum,
                 steps + 1);
  }

  if (row < (ROW - 1)) {
    printAllPath(arr, strncat(down_path, "D", 1), row + 1, col, pathNum,
                 steps + 1);
  }

  if (col < (COL - 1)) {
    printAllPath(arr, strncat(right_path, "R", 1), row, col + 1, pathNum,
                 steps + 1);
  }

  if (row > 0) {
    printAllPath(arr, strncat(up_path, "U", 1), row - 1, col, pathNum,
                 steps + 1);
  }

  if (col > 0) {
    printAllPath(arr, strncat(left_path, "L", 1), row, col - 1, pathNum,
                 steps + 1);
  }
  // this line where the function will be over
  // so before the function get removed / executed , also remove the changes
  // that were made by that functions so it doesn't alter the original array
  arr[row][col] = TRUE;
  pathNum[row][col] = 0;
}

int main() {
  int maiz[ROW][COL] = {
      {TRUE, TRUE, TRUE}, {TRUE, TRUE, TRUE}, {TRUE, TRUE, TRUE}};

  int pathNum[ROW][COL] = {{0}};

  char path[MAX_LENGTH] = "";
  printAllPath(maiz, path, 0, 0, pathNum, 1);
  return 0;
}

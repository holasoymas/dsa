#include <math.h>
#include <stdio.h>
#define N 9
#define TRUE 1
#define FALSE 0

int isSafe(int board[N][N], int row, int col, int num);
int sudokoSolver(int board[N][N]);
void displaySudokoBoard(int board[N][N]);

int main() {
  int board[N][N] = {{5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
                     {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
                     {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 0, 2, 0, 0, 6},
                     {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
                     {0, 0, 0, 0, 8, 0, 0, 7, 9}};
  if (sudokoSolver(board)) {
    displaySudokoBoard(board);
  } else {
    printf("Sudoko cannot be solved , go get another sudoko \n");
  }
  return 0;
}

int isSafe(int board[N][N], int row, int col, int num) {
  // check the row if it contain the number
  for (int i = 0; i < N; i++) {
    if (board[row][i] == num) {
      return FALSE;
    }
  }

  // check the column if it already contain the number we are going to put
  for (int i = 0; i < N; i++) {
    if (board[i][col] == num) {
      return FALSE;
    }
  }

  // NOTE: Why did i do that ?
  //-> Doing so give the starting position of row and column of a particular
  // sub-board, if you don't believe me try yourself on paper.
  int SQRT = (int)sqrt(N);
  int rowStart = row - (row % SQRT);
  int colStart = col - (col % SQRT);

  for (int r = rowStart; r < rowStart + SQRT; r++) {
    for (int c = colStart; c < colStart + SQRT; c++) {
      if (board[r][c] == num) {
        return FALSE;
      }
    }
  }
  return TRUE;
}

int sudokoSolver(int board[N][N]) {
  // check if sudoko have been solved or not
  int row = -1;
  int col = -1;

  int isEmpty = FALSE;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 0) {
        // if you found any empty box put the index value at row and col
        // variable and update the isEmpty == TRUE so that it indicate that
        // empty element has been found and need to solve the sudoko again
        row = i;
        col = j;
        isEmpty = TRUE;
        // this statement come out of the loop of "j"'s scope
        break;
      }
    }
    // if you found any empty element, come out of row by break statement
    if (isEmpty == TRUE) {
      // this statement come out of the "i"'s scope
      break;
    }
  }

  // if we didn't find any empty element in the entire board we have solved the
  // sudoko so return true
  if (isEmpty == FALSE) {
    return TRUE; // sudoko solved
  }

  // NOW backtrack if isEmpty is TRUE to find other possible solution
  // if isEmpty == TRUE put the suitable number in that position one by one
  for (int num = 1; num <= N; num++) {
    if (isSafe(board, row, col, num)) {
      // checking the number if it is the right number
      board[row][col] = num;
      // if it is the right number sudokoSolver return TRUE
      if (sudokoSolver(board)) {
        return TRUE;
      } else {
        // if the current number is not the right number in the current position
        // mark it as 0 and backtrack so you give other number a chance to solve
        // sudoko
        board[row][col] = 0;
      }
    }
  }
  // sudoko cannot be solved
  return FALSE;
}

void displaySudokoBoard(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    if (i == 3 || i == 6) {
      printf("\n");
    }
    printf("[ ");
    for (int j = 0; j < N; j++) {
      if (j == 3 || j == 6) {
        printf(" | ");
      }
      printf("%d ", board[i][j]);
    }
    printf("]\n");
  }
}

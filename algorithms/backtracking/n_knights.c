#include <stdio.h>
#define N 4
#define TRUE 1
#define FALSE 0
#define TARGET_KNIGHT 4

// NOTE:  KNIGHT is a horse

void placeKnights(int board[N][N]);
void backtrack(int board[N][N], int row, int col, int targetKnights);
int is_a_solution(int board[N][N], int row, int col, int targetKnights);
void printBoard(int board[N][N]);
int isSafe(int board[N][N], int row, int col);
int isValidMove(int board[N][N], int row, int col);

int main() {
  int board[N][N] = {{FALSE}};

  backtrack(board, 0, 0, TARGET_KNIGHT);

  return 0;
}

void backtrack(int board[N][N], int row, int col, int targetKnights) {
  if (is_a_solution(board, row, col, targetKnights)) {
    printBoard(board);
    return;
  }

  // this is the last index of our board so return
  if (row == (N - 1) && col == (N)) {
    return;
  }

  // if the col become the length of the board we know that there are no column
  // left so try the new row
  if (col == (N)) {
    backtrack(board, row + 1, 0, targetKnights);
    return;
  }

  if (isSafe(board, row, col)) {
    // if the place is safe mark as TRUE and more to the next col to try next
    // and decrease the value of targetKnights as we have found one more place
    // to place the knight
    board[row][col] = TRUE;
    backtrack(board, row, col + 1, targetKnights - 1);
    // when you come out of the recursion call make sure to mark the place FALSE
    // for future call so that original array doesnt alter
    board[row][col] = FALSE;
  }
  // if it is not safe just try the next col;
  backtrack(board, row, col + 1, targetKnights);
}

int is_a_solution(int board[N][N], int row, int col, int targetKnights) {
  if (0 == targetKnights)
    return TRUE;
  return FALSE;
}

int isSafe(int board[N][N], int row, int col) {
  // We know that KNIGHT move in L like shape
  // so its possible move in the board can be
  //
  // [row - 1, col - 2]
  // [row - 1, col + 2]
  // [row - 2, col - 1]
  // [row - 2, col + 1]
  //
  // check on these places/indexes if any knight is there if there is return
  // false, if the place is empty place the KNIGHT

  if (isValidMove(board, row - 1, col - 2)) {
    if (board[row - 1][col - 2]) {
      return FALSE;
    }
  }

  if (isValidMove(board, row - 1, col + 2)) {
    if (board[row - 1][col + 2]) {
      return FALSE;
    }
  }

  if (isValidMove(board, row - 2, col - 1)) {
    if (board[row - 2][col - 1]) {
      return FALSE;
    }
  }

  if (isValidMove(board, row - 2, col + 1)) {
    if (board[row - 2][col + 1]) {
      return FALSE;
    }
  }
  return TRUE;
}

int isValidMove(int board[N][N], int row, int col) {
  if (row >= 0 && row < (N) && col >= 0 && col < (N)) {
    return TRUE;
  }
  return FALSE;
}

void printBoard(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    printf("[ ");
    for (int j = 0; j < N; j++) {
      if (board[i][j] == TRUE) {
        printf("%c ", 'K');
      } else {
        printf("%c ", '*');
      }
    }
    printf("]\n");
  }
  printf("\n");
}

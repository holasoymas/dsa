#include <math.h>
#include <stdio.h>
#define N 5
#define TRUE 1
#define FALSE 0

void placeQueens(int board[N][N]);
int backtrack(int board[N][N], int row);
int is_a_solution(int board[N][N], int row);
void printBoard(int board[N][N]);
int isSafe(int board[N][N], int row, int col);

int main() {
  int board[N][N] = {{FALSE}};
  printf("%d\n", backtrack(board, 0));
  return 0;
}

int backtrack(int board[N][N], int row) {
  if (is_a_solution(board, row)) {
    printBoard(board);
    return 1;
  }
  int count = 0;
  // placing the queen and checking for every row and col
  for (int col = 0; col < N; col++) {
    if (isSafe(board, row, col)) {
      // make the place visited when dealing with that place
      board[row][col] = TRUE;
      count += backtrack(board, row + 1);
      // again make the place unvisited to explore other possible path and not
      // to alter the original array
      board[row][col] = FALSE;
    }
  }
  return count;
}

// int isSafe(int board[N][N], int row, int col) {
//   // check the vertical row if any row contain any Queens or not
//   for (int i = 0; i < N; i++) {
//     if (board[i][col]) {
//       return FALSE;
//     }
//   }

//   // check the diagonal on left part if it contain any Queens, if contain
//   // FALSE
//   int maxLeftDiagonalMove = fmin(row, col);
//   for (int i = 1; i <= maxLeftDiagonalMove; i++) {
//     if (board[row - i][col - i]) {
//       return FALSE;
//     }
//   }

//   // check for the diagonal right part
//   int maxRightDiagonalMove = fmin(row, (N - col) - 1);
//   for (int i = 1; i <= maxRightDiagonalMove; i++) {
//     if (board[row - i][col + i]) {
//       return FALSE;
//     }
//   }
//   return TRUE;
// }

// NOTE: Alternative method

int isSafe(int board[N][N], int row, int col) {
  // check the vertical row if any row contains any Queens or not
  for (int i = 0; i < row; i++) {
    if (board[i][col]) {
      return FALSE;
    }
  }

  // check the diagonal on left part if it contains any Queens
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      return FALSE;
    }
  }

  // check the diagonal on right part if it contains any Queens
  for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
    if (board[i][j]) {
      return FALSE;
    }
  }

  return TRUE;
}

int is_a_solution(int board[N][N], int row) { return row == (N); }

void printBoard(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    printf("[ ");
    for (int j = 0; j < N; j++) {
      if (board[i][j] == TRUE) {
        printf("%c ", 'Q');
      } else {
        printf("%c ", '*');
      }
    }
    printf("]\n");
  }
  printf("\n");
}

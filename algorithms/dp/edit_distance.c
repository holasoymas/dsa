#include <stdio.h>
#include <string.h>
#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLENGTH 20
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// NOTE: MINIMUM EDIT DISTANCE ALGORITHM (string approx. algorithm)
//    | " " |  A  |  L  |  G  |  O  |  R  |  I  |  T  |  H  |  M   |
//    |------------------------------------------------------------|
// " "|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9   |
//    |------------------------------------------------------------|
//  A |  1  |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8   |
//    |------------------------------------------------------------|
//  L |  2  |  1  |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7   |
//    |------------------------------------------------------------|
//  G |  3  |  2  |  1  |  0  |  1  |  2  |  3  |  4  |  5  |  6   |
//    |------------------------------------------------------------|
//  E |  4  |  3  |  2  |  1  |  1  |  2  |  3  |  4  |  5  |  6   |
//    |------------------------------------------------------------|
//  B |  5  |  4  |  3  |  2  |  2  |  2  |  3  |  4  |  5  |  6   |
//    |------------------------------------------------------------|
//  R |  6  |  5  |  4  |  3  |  3  |  2  |  3  |  4  |  5  |  6   |
//    |------------------------------------------------------------|
//  A |  7  |  6  |  5  |  4  |  4  |  3  |  3  |  4  |  5  |  6   |
//    |------------------------------------------------------------|
//
//  Here we want to change the word "algebra" to "algorithm" .
//  what is the minimum way we can change the word "algebra" to "algorithm" ?
//
//  Let "algebra" be P and "algorithm" be T.
//
//  Let i(row) and j(column) be the indexes of the box of DP(i,j) :
//
//  if P[i] == T[j]:
//     DP[i][j] = DP[i - 1][j - 1]  // copy the value of prev. diagonal
//
//  else :                              // take the min of three
//     A[MATCH] = DP[i - 1][j - 1] + 1  // copy the prev. diagonal + 1 (REPLACE)
//     A[DELETE] = DP[i - 1][j] + 1  // copy the prev. row + 1 (DELETE in P)
//     A[INSERT] = DP[i][j - 1] + 1  // copy the prev. col + 1 (INSERT in P)
//
// -> Ans will be at the last row of last column . Here it is 6

int edit_distance(char *s1, char *s2) {
  int dp[MAXLENGTH][MAXLENGTH];
  int opt[3];
  int lowest_cost;

  // inicialize the first row and column as they will all be start for 0 to n
  for (int row = 0, col = 0; row < MAXLENGTH || col < MAXLENGTH; row++, col++) {
    dp[row][0] = row;
    dp[0][col] = col;
  }

  int l1 = strlen(s1);
  int l2 = strlen(s2);

  for (int row = 1; row <= l1; row++) {
    for (int col = 1; col <= l2; col++) {
      opt[MATCH] = dp[row - 1][col - 1] + (s1[row - 1] == s2[col - 1] ? 0 : 1);
      opt[INSERT] = dp[row][col - 1] + 1;
      opt[DELETE] = dp[row - 1][col] + 1;

      // thake the minimum of three and put it in dp of row and col
      dp[row][col] = MIN(opt[MATCH], MIN(opt[INSERT], opt[DELETE]));
    }
  }

  return dp[l1][l2];
}

int main() {
  char str1[] = "algorithm";
  char str2[] = "algebra";

  int distance = edit_distance(str1, str2);

  printf("The edit_distance btwn '%s' and '%s' is %d\n", str1, str2, distance);

  return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10

//     3   2   1
//    --- --- ---
//  3| * |   |   |
//    --- --- ---
//  2|   |   |   |
//    --- --- ---
//  1|   |   |   |
//    --- --- ---
//
// Wer are in (3,3) our goal is to print all the possible unique path we can go
// in (1,1) ?

// Here strncat function help to concat the string and the third argument it
// expect is the length of the "to be concinated string"

// NOTE: Flow of the program

//                              printPath("", 3, 3)
//                             /                   \
//           printPath("D",2,3)                     printPath("R",3,2)
//          /                  \                   /                  \
// ("DD",1,3)             ("DR",2,2)         ("RR",3,1)            ("RD",2,2)
//         \              /        \          /     \               /      \
//  ("DDR",1,2)   ("DRD",1,2)  ("DRR",2,1)           // Similar to left
//       \            \            /
// ("DDRR", 1,1)  ("DRDR",1,1)  ("DRRD",1,1)

// NOTE: Here we can only go down and right

void printPath(char *path, int row, int column) {
  // our base case is where row and column is 1 we have count one of the
  // possible way of finding path so print it and backtrack other path

  if (row == 1 && column == 1) {
    printf("%s\n", path);
    return;
  }

  // Make copies of the path to use in each recursive call
  char path_down[MAX_LENGTH];
  char path_right[MAX_LENGTH];
  strcpy(path_down, path);
  strcpy(path_right, path);

  if (row > 1) {
    printPath(strncat(path_down, "D", 1), row - 1, column);
  }
  if (column > 1) {
    printPath(strncat(path_right, "R", 1), row, column - 1);
  }
}

int main() {
  char path[MAX_LENGTH] = "";
  printPath(path, 3, 3);
  return 0;
}

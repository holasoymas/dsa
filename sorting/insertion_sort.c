#include <stdio.h>

// HACK: Insertion Sort
//
//    ---      ---      ---     ---     ---
//   | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//    ---      ---      ---     ---     ---
//
//   loop : i = 1
//   elmnt = arr[i]
//   j = i -1
//
//  Sotred  | Unsorted part
//  part    |
//          |
//    ---   |  ---      ---     ---     ---
//   | 7 |  | | 6 |    | 2 |   | 5 |   | 3 |
//    ---   |  ---      ---     ---     ---
//          |
//
// Another loop : while j>=0 && elmnt < arr[j]
//
//   arr[j] | elmnt
//    ---   |  ---      ---     ---     ---
//   | 7 |  | | 6 |    | 2 |   | 5 |   | 3 |
//    ---   |  ---      ---     ---     ---
//          |
//
//  Sorted part      | Unsorted part
//                   |
//            arr[j] | elmnt
//    ---      ---   |  ---     ---     ---
//   | 6 |    | 7 |  | | 2 |   | 5 |   | 3 |
//    ---      ---   |  ---     ---     ---
//                   |
//
// IS j >= 0 && elmnt < arr[j] , yes so do arr[j+1] = arr[j]
//
//  Sorted part      | Unsorted part
//                   |
//            arr[j] |
//    ---      ---   |  ---     ---     ---
//   | 6 |    | 7 |  | | 7 |   | 5 |   | 3 |
//    ---      ---   |  ---     ---     ---
//              |    |   |
//              |________|
//
//
// Now j = j-1;
// Again is elmnt(in this case here 2) is < arr[j] , yes it is
//
///  Sorted part     | Unsorted part
//                   |
//   arr[j]          |
//    ---      ---   |  ---     ---     ---
//   | 6 |    | 7 |  | | 7 |   | 5 |   | 3 |
//    ---      ---   |  ---     ---     ---
//                   |
//
// elmnt = 2
//
//
// IS j >= 0 && elmnt < arr[j] , yes so do arr[j+1] = arr[j]
//
///  Sorted part     | Unsorted part
//                   |
//   arr[j]          |
//    ---      ---   |  ---     ---     ---
//   | 6 |    | 6 |  | | 7 |   | 5 |   | 3 |
//    ---      ---   |  ---     ---     ---
//     |        |    |
//     |________|
//
//
// Now j = j-1
//
// Again is j>= 0 && elmnt < arr[j] , No cause j is now -1
// So you come out of the while loop and
// arr[j+1]= elmnt; here j = -1 so j+1[-1+1] = 0
// So arr[j] = elmnt
//
//
///  Sorted part     | Unsorted part
//                   |
//                   |
//    ---      ---   |  ---     ---     ---
//   | 2 |    | 6 |  | | 7 |   | 5 |   | 3 |
//    ---      ---   |  ---     ---     ---
//                   |
//
// Now :
//
///     Sorted part          |  Unsorted part
//                           |
//                    arr[j] | elmnt
//    ---      ---      ---  |  ---     ---
//   | 2 |    | 6 |    | 7 | | | 5 |   | 3 |
//    ---      ---      ---  |  ---     ---
//                           |
//
// So repeat this process until array become sorted
//

void insertionSort(int arr[], int size) {
  int elmnt, j;
  for (int i = 1; i < size; i++) {
    elmnt = arr[i];
    j = i - 1;
    while (j >= 0 && elmnt < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = elmnt;
  }
}

int main() {

  int n;
  printf("How many elements ? \n");
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the %d th element : ", i + 1);
    scanf("%d", &arr[i]);
  }

  insertionSort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}

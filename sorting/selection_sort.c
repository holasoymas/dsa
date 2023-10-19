#include <stdio.h>

// HACK: Selection Sort
//
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//
// Let 0 be the minimum index value of loop i . Here arr[0] = 7 is the minimum
// index value
//
// Do another loop j, And compare it with the minimum index value
// if (arr[min_index] > arr[j]) let min index value be "j"
//
//  min_indx  "j"
//    |        |
//    |        |
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//
//         min_indx    "j"
//             |        |
//             |        |
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//
//                 min_indx     "j"
//                      |        |
//                      |        |
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//
//                   min_indx          "j"
//                      |               |
//                      |               |
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//
//  Here minimum index value is 2 and the element is also 2 arr[min_indx] = 2
//  So swap it with the arr[i];
//
//  //               min_indx          "j"
//                      |               |
//                      |               |
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//    |_________________|(swap)
//
//
//
// Sorted  |   Unsorted part
// part    |
//         |
//   ---   |  ---      ---     ---     ---
//  | 2 |  | | 6 |    | 7 |   | 5 |   | 3 |
//   ---   |  ---      ---     ---     ---
//         |
//
// Now the minimum index value is 1. arr[1] = 6
//
// Do the same process as avobe until the array is sorted

void selectionSort(int arr[], int size) {
  int min_indx, tmp;
  for (int i = 0; i < size - 2; i++) {
    min_indx = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[min_indx] > arr[j]) {
        min_indx = j;
      }
    }
    tmp = arr[i];
    arr[i] = arr[min_indx];
    arr[min_indx] = tmp;
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

  selectionSort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}

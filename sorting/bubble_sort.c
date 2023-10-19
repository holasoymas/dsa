#include <stdio.h>

// HACK: Bubble Sort
//
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//
//  Compare "i" th element with "i + 1" th element. If "i" > "i + 1", swap them
//
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//    |________| (swap)
//
//    ---      ---      ---     ---     ---
//   | 6 |    | 7 |    | 2 |   | 5 |   | 3 |
//    ---      ---      ---     ---     ---
//              |________| (swap)
//
//    ---      ---      ---     ---     ---
//   | 6 |    | 2 |    | 7 |   | 5 |   | 3 |
//    ---      ---      ---     ---     ---
//                       |________| (swap)
//
//    ---      ---      ---     ---     ---
//   | 6 |    | 2 |    | 5 |   | 7 |   | 3 |
//    ---      ---      ---     ---     ---
//                               |_______| (swap)
//
//    ---      ---      ---     ---     ---
//   | 6 |    | 2 |    | 5 |   | 3 |   | 7 |
//    ---      ---      ---     ---     ---
//
//   Now repeat this process once more
//
//     ---      ---      ---     ---     ---
//    | 6 |    | 2 |    | 5 |   | 3 |   | 7 |
//     ---      ---      ---     ---     ---
//      |________| (swap)
//
//  Do this until the array is sorted
//

void bubbleSort(int size, int arr[]) {
  int tmp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
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

  bubbleSort(n, arr);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}

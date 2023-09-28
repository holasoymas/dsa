#include <stdio.h>

//: HACK: Find the mode

int findMode(int arr[], int size) {
  int maxCount = 0;
  int mode = 0;

  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = 0; j < size; j++) {
      if (arr[j] == arr[i]) {
        count++;
      }
      if (arr[i] == mode) { // just ignore the repeted number (break our the
                            // loop if previous number was same)
        break;
      }
    }
    if (count > maxCount) {
      maxCount = count;
      mode = arr[i];
    } else if (count == maxCount) {
      mode = 0;
    }
  }
  return mode;
}

int main(void) {
  int arr[] = {1, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 8, 9, 9, 9, 9, 9, 9, 1};

  int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
  int mode = findMode(arr, sizeOfArr);
  printf("Mode = %d\n", mode);
  printf("Size of an arr = %d\n", sizeOfArr);
  return 0;
}

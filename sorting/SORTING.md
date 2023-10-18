# SORTING ALGORITHMS


## Table of contents

*[Bubble Sort](#bubble-sort)


## Bubble sort 
Bubble sort is a very simple , naive sorting algorithm which sort by comparing the next element to the current element of next eleemnt is smaller than the current element they just swap the palces.

# C code for bubble sort 
```
#include <stdio.h>

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
```

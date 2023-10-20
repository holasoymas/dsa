# SORTING ALGORITHMS


## Table of contents

* [Bubble Sort](#bubble-sort)
* [Selection Sort](#selection-sort)

## Bubble sort 
Bubble sort is a very simple , naive sorting algorithm which sort by comparing the next element to the current element, if the next element is smaller than the current element then they just swap the palces.

For a better understanding please look the following animated video [Animated bubble sort video](https://www.youtube.com/watch?v=nmhjrI-aW5o)

### C code for bubble sort 
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

## Selection Sort 
Selection sort is a simple , naive sorting algorithm which sort items based on minimum's index value. First the index "0" is the minimum index value. It loop through the array and if it find item smaller than the minimum index value they swap places.

For a better understanding please look the following animated video [Animated Selection sort video](https://www.youtube.com/watch?v=xWBP4lzkoyM)

### C code for selection sort
```
#include <stdio.h>

void selectionSort(int arr[], int size) {
  int min_indx, tmp;
  for (int i = 0; i < size - 1; i++) {
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
```
## Insertion Sort
Insertion sort is a simple sorting algorithm that is efficient for small datasets. It works by dividing the list into a sorted part and an unsorted part. The sorted part initially contains only the first element of the list, and the unsorted part contains the rest of the list. The algorithm iterates through each element in the unsorted part, picking one at a time, and inserts it into its correct position in the sorted part


For a better understanding please look the following animated video [Animated Insertion sort video](https://www.youtube.com/watch?v=OGzPmgsI-pQ)

### C code for insertion sort 
```
#include<stdio.h>

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
```


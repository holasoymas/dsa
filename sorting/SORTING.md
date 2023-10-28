# SORTING ALGORITHMS

## Table of contents

- [Bubble Sort](#bubble-sort)
- [Selection Sort](#selection-sort)
- [Insertion Sort](#insertion-sort)

### Efficient algorithms

- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)

### Distribution Sorts Algorithms

- [Bucket Sort](#bucket-sort)

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

## Merge Sort

Merge Sort is an efficient, stable, and comparison-based sorting algorithm based on the divide and conquer technique. It works by dividing an array into two halves, recursively sorting each half, and then merging the sorted halves back together

Note: It is not in-memory sorting algorithm. The space complexity is O(n) because all elements are copied into an auxiliary array

For better visualization look at this animation video [Merge Sort Animated video](https://www.youtube.com/watch?v=JSceec-wEyw)

### Merge Sort in C

```
#include<stdio.h>

void merge(int arr[], int l, int m, int r) {

  int l_length = m - l + 1;
  int r_length = r - m;

  // Creating a temporary Array to hold the value of sub arrays
  int L[l_length], R[r_length];

  for (int i = 0; i < l_length; i++) {
    L[i] = arr[l + i];
  }
  for (int i = 0; i < r_length; i++) {
    R[i] = arr[m + 1 + i];
  }

  int i = 0, j = 0, k = l;

  while (i < l_length && j < r_length) {
    // Compare the elements of the two subarrays and
    // place the smaller element into arr[k].
    if (L[i] > R[j]) {
      arr[k] = R[j];
      j++;
    } else {
      arr[k] = L[i];
      i++;
    }
    k++;
  }
  // Copy any remaining elements of L[] or R[] if there are any.

  while (i < l_length) {

    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < r_length) {

    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
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

  mergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
```

## QUick Sort

Quick sort is a widely used and efficient sorting algorithm that follows a divide-and-conquer approach to sort a list or array of items. The key idea behind quick sort is to select a "pivot" element from the list and partition the other elements into two subarrays – one containing elements less than the pivot and another containing elements greater than the pivot. This process is then recursively applied to the subarrays until the entire list is sorted.

For better visual understanding watch : [Quick sort Animated video](https://www.youtube.com/watch?v=PgBzjlCcFvc)

### C code for Quick sort

```
#include<stdio.h>

int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Choose the right most element as pivot
  int i = low - 1; // Initialize an index i to keep track of the position where
                   // elements less than the pivot should go.
  int tmp;

  // Loop through the elements from 'low' to 'high-1'.
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) { // If the curr. element is less than the pivot ,
      i++;                // Increment the index i to move to the next position.
      tmp = arr[j];       // Swap arr[i] and arr[j].
      arr[j] = arr[i];
      arr[i] = tmp;
    }
  }
  // After the loop, all elements less than the pivot are on the left side of
  // the array.(which are upto "i"th element)

  tmp = arr[high]; // Swap arr[i+1] and the pivot element (arr[high]).
  arr[high] = arr[i + 1];
  arr[i + 1] = tmp;

  return i + 1;
  // Return the position of the pivot element in its sorted position.
  // HACK: And remember [i +1] never changes position throught the sorting
  // proccess as elements less than [i] are smaller than the pivot and elements
  // grater than [i] are grater than pivot so [i+1] is at the right place
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivotIndx = partition(arr, low, high);
    quickSort(arr, low, pivotIndx - 1);
    quickSort(arr, pivotIndx + 1, high);
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

  quickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
```

## Bucket Sort

Bucket sort, also known as bin sort, is a distribution-based sorting algorithm. This algorithm works by dividing the elements of an array into several "buckets", and then each bucket is sorted individually, either using a different sorting algorithm or by recursively applying the bucket sorting algorithm.

For better visualization see : [Bubble Sort Animated Video](https://www.youtube.com/watch?v=VuXbEb5ywrU)

We are using **math.h** library here so make sure to link that header file by :

```
clang bucket_sort.c -lm
```

### C code for Bucket Sort

```
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insertBucket(struct Node **bucket, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;

  // if bucket is null set the next value null as there are no elmnts
  if (*bucket == NULL) {
    newNode->next = NULL;
    *bucket = newNode;
    return;
  }

  // set the next value points as bucket and make that newNode a head
  newNode->next = *bucket;
  *bucket = newNode;
}

void insertSorted(struct Node **head, struct Node *newNode) {

  // If the list is empty or the new node is smaller than the head node, insert
  // at the front
  if (*head == NULL || (*head)->data > newNode->data) {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  // Find the position to insert the new node
  struct Node *curr = *head;
  while (curr->next != NULL && curr->next->data < newNode->data) {
    curr = curr->next;
  }
  // Current position for the data have been found So update the pointer
  newNode->next = curr->next;
  curr->next = newNode;
}

void insertionSort(struct Node **bucket) {

  struct Node *curr = *bucket;
  struct Node *sorted = NULL;
  struct Node *next = NULL;
  while (curr != NULL) {
    next = curr->next; // This is done here because we might lose next pointer
                       // while sorting
    insertSorted(&sorted, curr); // Insert the curr node in the sorted order
    curr = next;
  }

  // Now update the bucket pointer to point to the sorted list
  *bucket = sorted;
}

void bucketSort(int arr[], int size) {
  struct Node *Buckets[10];

  // Initialize buckets
  for (int i = 0; i < 10; i++) {
    Buckets[i] = NULL;
  }

  // Find maximum value in arr[]
  int maxVal = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }

  // Insert elements into appropriate buckets
  for (int i = 0; i < size; i++) {
    // Here 10 represent the numbers of buckets , this algorithm places the
    // number in appropriate place by normalizing
    int bucketNum = (int)(10.0 * arr[i] / (maxVal + 1));
    insertBucket(&Buckets[bucketNum], arr[i]);
  }

  // Sort each bucket and concatenate
  int indx = 0;
  for (int i = 0; i < 10; i++) {
    insertionSort(&Buckets[i]);
    struct Node *curr = Buckets[i];
    while (curr != NULL) {
      arr[indx++] = curr->data;
      curr = curr->next;
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

  bucketSort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
```

#include <math.h>
#include <stdio.h>

// NOTE: This implementation doesn't work on array with negative number(s).

// Radix Sort can be implemented by Counting sort. Here we took help of counting
// sort to Sort an array

//    ----      ----      ----     ----     ----    ----
//   | 17 |    | 26 |    | 41 |   | 59 |   | 35 |  | 01 |
//    ----      ----      ----     ----     ----    ----

// First find the maximum num. so that you can get max. digit
//
// Create a new array called countArr and count the no of occurance
// Loop throught the least signicificant digit and count its occurance
//
//    0    1     2     3     4     5     6     7     8     9
//  ----  ----  ----  ----  ----  ----  ----  ----  ----  ----
// | 0  || 2  || 0  || 0  || 0  ||  1 || 1  || 1  || 0  || 1  |
//  ----  ----  ----  ----  ----  ----  ----  ----  ----  ----
//
// Now add up the number of occurancees
//
//    0    1     2     3     4     5     6     7     8     9
//  ----  ----  ----  ----  ----  ----  ----  ----  ----  ----
// | 0  || 2  || 2  || 2  || 2  ||  3 || 4  || 5  || 5  || 6  |
//  ----  ----  ----  ----  ----  ----  ----  ----  ----  ----
//
// HACK: Now loop throught the array from opposite side and decrement the
// countArr
// eg : arr[5] = 01 , here the LSB is 1 now look at the index 1 of countArr.
// countArr[1] = 2. Now decrement countArr[1], so it become 1. Now put arr[5]
// into in arr[1].
//
//    0    1     2     3     4
//  ----  ----  ----  ----  ----
// | 41 || 01 || 35 || 26 || 17 |
//  ----  ----  ----  ----  ----
//
// LSB has been sorted , now keep on sorting digits until MSB. And your arr is
// sorted

int findMax(int arr[], int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

void countingSort(int arr[], int size, int exp) {
  int countArr[10] = {0};

  // Store count of occurrences in countArr[]
  for (int i = 0; i < size; i++) {
    countArr[(arr[i] / exp) % 10]++;
  }

  // Change countArr[i] so that countArr[i] now contains actual position
  for (int i = 1; i < 10; i++) {
    countArr[i] += countArr[i - 1];
  }

  // Copying the array cause the original array will be altered during
  //  exchaning data
  int tmpArr[size];
  for (int i = 0; i < size; i++) {
    tmpArr[i] = arr[i];
  }

  // Finding the appriopriate place to insert
  for (int i = size - 1; i >= 0; i--) {
    int indx = (tmpArr[i] / exp) % 10;
    countArr[indx]--;
    arr[countArr[indx]] = tmpArr[i];
  }
}

void radixSort(int arr[], int size) {

  int max = findMax(arr, size);

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(arr, size, exp);
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
  radixSort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

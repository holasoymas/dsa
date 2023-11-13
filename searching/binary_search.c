#include <limits.h>
#include <stdio.h>

// NOTE: To thake the advantage of binary search you have to make sure that your
// array is sorted

//               0    1    2    3    4    5
//              ---  ---  ---  ---  ---  ---
//             | 1 || 2 || 3 || 5 || 6 || 7 |
//              ---  ---  ---  ---  ---  ---
//             low                   key high
//
// Here we wan to find 6 ?
// First we have low = 0 and high = size - 1 (5)
// mid = low + (high - low ) / 2;  0 + (5-0 ) / 2 = 2
// Now arr[2] < key(6) so we know that data is in the right side of an array so
// make indx 2+1 as a  low
//
//               0    1    2    3    4    5
//              ---  ---  ---  ---  ---  ---
//             | 1 || 2 || 3 || 5 || 6 || 7 |
//              ---  ---  ---  ---  ---  ---
//                             low  key  high
//
// Now low = 3 and hight = 5
// mid = 3 + (5-3) / 2; = 4
// Now arr[4] == key So return the index
//
// THis process eleminate the need to look the entire array so we get the time
// complexity of O(log n), which is very efficient than O(n)

int binarySearch(int arr[], int size, int key) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (key > arr[mid]) {
      low = mid + 1;
    } else if (key < arr[mid]) {
      high = mid - 1;
    } else {
      return mid;
    }
  }
  // this code will run if there is no element that match the key in array
  return INT_MIN;
}

int binarySearchRec(int arr[], int size, int low, int high, int key) {

  if (low > high)
    return INT_MIN;

  int mid = low + (high - low) / 2;

  if (arr[mid] == key) {
    return mid;
  } else if (arr[mid] > key) {
    return binarySearchRec(arr, size / 2, low, mid - 1, key);
  } else {
    return binarySearchRec(arr, size / 2, mid + 1, high, key);
  }
}

int main() {

  int arr[100] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15,
                  16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                  31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
                  46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
                  61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75,
                  76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
                  91, 92, 93, 94, 95, 96, 97, 98, 99, 100};

  int found = binarySearch(arr, 100, 12);
  printf("Found Index = %d\n", found);

  return 0;
}

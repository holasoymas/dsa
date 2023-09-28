#include <stddef.h>
#include <stdio.h>

int binary_search(int arr[], int low, int high, int key) {
  // int high, low;
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;

  return (key == arr[mid]  ? mid
          : key < arr[mid] ? binary_search(arr, low, mid - 1, key)
                           : binary_search(arr, mid + 1, high, key));
}

int main(void) {
  int arr[14] = {3,   5,   7,    23,   89,   324,  643,
                 666, 777, 1234, 7777, 8888, 9090, 9999};
  int key = 666;
  int low = 0;
  int high = 13;
  int addr = binary_search(arr, low, high, key);
  printf("we found element in %d\n", addr);
  return 0;
}

#include <stdio.h>
#include <string.h>

float findMedian(int arr[], int size) {
  int midsize = size / 2;
  if (size % 2 == 0) {
    float twoarr = (arr[midsize] + arr[midsize - 1]);
    return twoarr / 2;
  }
  return arr[midsize];
}

int main(void) {
  int arr[] = {1, 4, 6, 7, 8, 9, 11, 15, 19, 20};
  int sizeofArr = sizeof(arr) / sizeof(arr[0]);

  float median = findMedian(arr, sizeofArr);

  printf("The median is %.1f\n", median);
  printf("size of arr %d\n", sizeofArr);
  return 0;
}

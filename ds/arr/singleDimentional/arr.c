#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMLISTS 5

int main(int argc, char *argv[]) {
  int arr[NUMLISTS], total = 0;
  float avg, diff;
  printf("Enter the value of arr : \n");

  for (int i = 0; i < NUMLISTS; i++) {
    printf("Enter the %d th element : ", i + 1);
    scanf("%d", &arr[i]);
    total = total + arr[i];
  }
  printf("The total value of the sum of arr is = %d\n", total);

  avg = (float)total / NUMLISTS;
  printf("The average of the elements is = %f\n", avg);

  printf("This is the difference of the average of that arr \n");

  for (int i = 0; i < NUMLISTS; i++) {
    diff = arr[i] - avg;
    printf("The diff of %dth element is %.2f\n", i + 1, diff);
  }

  return 0;
}

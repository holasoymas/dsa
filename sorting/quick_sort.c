#include <stdio.h>
#include <stdlib.h>

// HACK: The main idea of quick sort is a element called pivot.
// In the left all the elements should be smaller than pivot and in the right
// all the elements should be grater than pivot

// HACK: There are number of ways to selet pivot some of them are :
// 1. Selecting the first or last element as pivot
// 2. Selecting the random element as pivot
// 3. Selecting the pivot by median of 3 method

// Out of them random element and median of 3 method provide good performance
// and avoid
//  O(n^2) time complexity

// Lets visualize quickSort using pivot as a last element
//
// pivot = 3
// pivotIndx = low -1 , here low is 0 now
// loop through it (i with initial value as low)
// if arr[i] < arr[high]
//       swap(arr[i], arr[pivotIndx])
//
//    i                                pivot
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
// here 7 !< 3 so continue
//
//            i                        pivot
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
// here 6 !< 3 so continue
//
//                      i             pivot
//   ---      ---      ---     ---     ---
//  | 7 |    | 6 |    | 2 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//    |_________________|
//
// here 2 < 3 so, do pivotIndx++, and swap(arr[pivotIndx],arr[i])
//
// Now it look like :                   pivot
//   ---      ---      ---     ---     ---
//  | 2 |    | 6 |    | 7 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//
//                              i     pivot
//   ---      ---      ---     ---     ---
//  | 2 |    | 6 |    | 7 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
// here 5 !< 3 so continue (this is the end of the loop)
//
// Coming out of loop :
//
// now swap(arr[pivotIndx+1], arr[high])
//
//   ---      ---      ---     ---     ---
//  | 2 |    | 6 |    | 7 |   | 5 |   | 3 |
//   ---      ---      ---     ---     ---
//             |________________________|
//
// Now the array is ready to do partition
//
// Left part|        | Right part
//   ---   |  ---   |   ---     ---     ---
//  | 2 |  | | 3 |  |  | 7 |   | 5 |   | 6 |
//   ---   |  ---   |   ---     ---     ---
//         |        |
//
// By doing this we insure that at left we have smaller than pivot and at right
// grather than privot
//
// Now break them and and quickSort recursively
//
// NOTE: Here 3 is at the right position throught sorting casuse smaller
// elements are at left side and larger are at right side
//
//     | Now the return is in step|
//     | no 2 the first quickSort |
//     | is returned and now      |
//  7. |  quickSort(3,4) will be  |
//     |called and recursion start|
//     | again                    |
//     |__________________________|
//     | quickSort(1,1)       P.F |
//     | l = 1, r = 1  (r !> l)   |
//  6. | SO return to its calle(3)|
//     |__________________________|
//     | quickSort(0,0)       P.F |
//     | l = 0, r = 0  (r !> l)   |
//     | Here r is ! > than l, So |
//  5. | return Step no 6         |
//     |                          |
//     |__________________________|
//     |                          |
//     | quickSort(0,-1)      P.F |
//  4. | l = 0, r = -1 (r !> l)   |
//     |So return to its calle(3) |
//     |__________________________|
//     | quickSort(0,1)       P.F |
//     | l = 0, r = 1  (r > l)    |
//     | partition= 0             |
//  3. | quickSort(0,-1)    C.R.C |
//     | quickSort(1,1)     N.E.Y |
//     |__________________________|
//     | quickSort(0,4)       P.F |
//     | l = 0, r = 4  (r > l)    |
//     | partition = 2            |
//  2. | quickSort(0,1)     C.R.C |
//     | quickSort(3,4)     N.E.Y |
//     |__________________________|
//     | main                     |
//  1. | l = 0, r = 4             |
//     | quickSort(0,4)           |
//     |__________________________|
//
//
//

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

int medianOfThreePartition(int arr[], int low, int high) {
  int mid = low + (high - low) / 2;
  int tmp;
  // Find the median of arr[low], arr[mid], and arr[high] and move it to
  // arr[high]
  if (arr[mid] < arr[low]) {
    // Swap arr[mid] and arr[low]
    tmp = arr[mid];
    arr[mid] = arr[low];
    arr[low] = tmp;
  }
  if (arr[high] < arr[low]) {
    // Swap arr[high] and arr[low]
    tmp = arr[high];
    arr[high] = arr[low];
    arr[low] = tmp;
  }
  if (arr[mid] < arr[high]) {
    // Swap arr[mid] and arr[high]
    tmp = arr[mid];
    arr[mid] = arr[high];
    arr[high] = tmp;
  }
  // Now arr[high] is the median element

  // Index of the last element that is smaller than the pivot
  int pivotIndx = low - 1;
  for (int i = low; i < high; i++) {
    if (arr[i] < arr[high]) { // Compare with arr[high], not median
      pivotIndx++;            // Increment pivotIndx before swapping
      // Swap arr[i] and arr[pivotIndx]
      tmp = arr[i];
      arr[i] = arr[pivotIndx];
      arr[pivotIndx] = tmp;
    }
  }
  // Swap arr[pivotIndx+1] and arr[high]
  tmp = arr[pivotIndx + 1];
  arr[pivotIndx + 1] = arr[high];
  arr[high] = tmp;

  return pivotIndx + 1;
}

int randomPartition(int arr[], int low, int high) {
  // Generating random number between high and low
  int pivot = rand() % (high - low + 1) + low;
  int pivotIndx = low - 1, tmp;

  // Swap the arr[pivot] and arr[high] as this is important to ensure that pivot
  // element is correctly positioned in the final sort
  tmp = arr[pivot];
  arr[pivot] = arr[high];
  arr[high] = tmp;

  for (int i = low; i < high; i++) {
    if (arr[i] < arr[high]) { // As now hight is the pivot element
      pivotIndx++;
      tmp = arr[i];
      arr[i] = arr[pivotIndx];
      arr[pivotIndx] = tmp;
    }
  }
  tmp = arr[pivotIndx + 1];
  arr[pivotIndx + 1] = arr[high];
  arr[high] = tmp;
  return pivotIndx + 1;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // int pivotIndx = partition(arr, low, high);
    // int pivotIndx = randomPartition(arr, low, high);
    int pivotIndx = medianOfThreePartition(arr, low, high);
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

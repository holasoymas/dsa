#include <stdio.h>
//                            |
//              ---  ---  --- | ---  ---  ---
//             | 7 || 6 || 2 ||| 5 || 3 || 1 |
//              ---  ---  --- | ---  ---  ---
//              /                        \
//        ---  --- | ---                ---  ---  ---
//       | 7 || 6 ||| 2 |              | 5 || 3 || 1 |
//        ---  --- | ---                ---  ---  ---
//          /         \                  /         \
//     ---  ---      ---            ---  ---      ---
//    | 7 || 6 |    | 2 |          | 5 || 3 |    | 1 |
//     ---  ---      ---            ---  ---      ---
//
//  ---     ---     ---         ---    ---    ---
// | 7 |   | 6 |   | 2 |       | 5 |  | 3 |  | 1 |
//  ---     ---     ---         ---    ---    ---
//
// Elements have been broken down to the atomic level , now merge
//
//      ---  ---      ---            ---  ---      ---
//     | 6 || 7 |    | 2 |          | 3 || 5 |    | 1 |
//      ---  ---      ---            ---  ---      ---
//         /                            \
//      ---  ---  ---                ---  ---  ---
//     | 2 || 6 || 7 |              | 1 || 3 || 5 |
//      ---  ---  ---                ---  ---  ---
//                 \                   /
//              ---  ---  ---  ---  ---  ---
//             | 1 || 2 || 3 || 5 || 6 || 7 |
//              ---  ---  ---  ---  ---  ---
//
//
//
//
// Now lets deep dipe in recersion of Merge Sort
//
// At main we have left at 0 (l = 0) and r=(6-1=5)
//
//
//
//
//
//
//  N.E.Y = Not Executed yet
// A.E = Already Executed
// C.R.C = Current Recursive Call
// P.F = Parameter Function
//
//
//
//
//
//      | merge(0,0,1)         P.F |         | merge(3,3,4)         P.F |
//      | l_len = m-l+1  = 1       |         | l_len = m-l+1  = 1       |
//      | r_len = r-m   = 1        |         | r_len = r-m   = 1        |
//      | Creating tmp. array      |         | Creating tmp. array      |
//   9. | L[l_len], R[r_len]       |     17. | L[l_len], R[r_len]       |
//      | Cmp val. and place in    |         | Cmp val. and place in    |
//      | right order & return     |         | right order & return     |
//      | Its return position is in|         | Its return position is in|
//      | step no 4,               |         | step no 15               |
//      | mergeSort(0,1) terminates|         | mergeSort(3,4) terminates|
//      | and in stp. 3 will return|         | and in stp.14 will return|
//      |__________________________|         |__________________________|
//      | mergeSort(0,1)       P.F |         |mergeSort(3,3)            |
//      | l = 0, r = 1  (r > l)    |         | l=3,r=3 (r !> l ) return |
//      | m = 0                    |         | in step 15 & agian       |
//   8. | mergeSort(0,0)       A.E |     16. | mergeSort(4,4) so in     |
//      | mergeSort(1,1)       A.E |         | merge(3,3,4) part        |
//      | merge(0,0,1)       C.R.C |         |                          |
//      |__________________________|         |__________________________|
//      | mergeSort(1,1)       P.F |         | mergeSort(3,4)       P.F |
//      | l = 1, r = 1  (r !> l)   |         | l = 3, r = 4  (r > l)    |
//      | Here r is ! > than l, So |         | m = 3                    |
//   7. | return Step no 8         |     15. | mergeSort(3,3)     C.R.C |
//      |                          |         | mergeSort(4,4)     N.Y.E |
//      |                          |         | mergeSort(3,3,4)   N.E.Y |
//      |__________________________|         |__________________________|
//      | mergeSort(0,1)       P.F |         | mergeSort(3,5)       P.F |
//      | l = 0, r = 1  (r > l)    |         | l = 3, r = 5  (r > l)    |
//      | m = 0                    |         | m = 4                    |
//   6. | mergeSort(0,0)       A.E |     14. | mergeSort(3,4)     C.R.C |
//      | mergeSort(1,1)     C.R.C |         | mergeSort(5,5)     N.Y.E |
//      | merge(0,0,1)       N.E.Y |         | merge(3,4,5)       N.E.Y |
//      |__________________________|         |__________________________|
//      | mergeSort(0,0)       P.F |         | mergeSort(0,5)       P.F |
//      | l = 0, r = 0  (r !> l)   |         | l = 0, r = 5  (r > l)    |
//      | Here r is ! > than l, So |         | mergeSort(0,2)       A.E |
//   5. | return Step no 6         |     13. | mergeSort(3,5)     C.R.C |
//      |                          |         | merge(0,2,5)       N.Y.E |
//      |__________________________|         |__________________________|
//      |                          |         | merge(0,1,2)         P.F |
//      | mergeSort(0,1)       P.F |         | l_len = 2, r_len = 1     |
//      | l = 0, r = 1  (r > l)    |         | Again copy the elements  |
//      | m = 0                    |         | in L[l_len] & R[r_len] & |
//   4. | mergeSort(0,0)     C.R.C |     12. | merge and sort them & it |
//      | mergeSort(1,1)     N.E.Y |         | will return in step 2    |
//      | merge(0,0,1)       N.E.Y |         | flow state in step 13    |
//      |__________________________|         |__________________________|
//      | mergeSort(0,2)       P.F |         | mergeSort(2,2)       P.F |
//      | l = 0, r = 2  (r > l)    |         | l = 2, r = 2  (r !> l)   |
//      | m = 1                    |         | Here fun. will return    |
//   3. | mergeSort(0,1)     C.R.C |     11. | and its flow state is    |
//      | mergeSort(2,2)     N.E.Y |         |  shown in step 12        |
//      | merge(0,1,2)       N.E.Y |         |                          |
//      |__________________________|         |__________________________|
//      | mergeSort(0,5)       P.F |         | mergeSort(0,2)       P.F |
//      | l = 0, r = 5  (r > l)    |         | l = 0, r = 2  (r > l)    |
//      | m = 2                    |         | m = 1                    |
//   2. | mergeSort(0,2)     C.R.C |     10. | mergeSort(0,1)       A.E |
//      | mergeSort(3,5)     N.E.Y |         | mergeSort(2,2)     C.R.C |
//      | merge(0,2,5)       N.Y.E |         | merge(0,1,2)       N.Y.E |
//      |__________________________|         |__________________________|
//      | main                     |
//   1. | l = 0, r = 5             |
//      | mergeSort(0,5)           |
//      |__________________________|
//
// This process will continue like this until whole array is merged & sorted
//
//
//
//

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

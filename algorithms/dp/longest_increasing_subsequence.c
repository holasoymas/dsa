#include <stdio.h>
#define MAXLENGTH 20
#define MAX(a, b) ((a) > (b) ? (a) : (b))

//    | 2 | 3 | 0 | 1 | 7 | 4 | 6 |  -> Ans : 4 [2,3,4,6]
//
// arr =  | 2 | 3 | 0 | 1 | 7 | 4 | 6 |
//
//  dp =  | 1 | 1 | 1 | 1 | 1 | 1 | 1 | // init. longest sebsequence as 1
//
//
//  Let i be i = 1 ; i < arr.length ; i++
//        and j = 0 ; j < i ; j++
//
//          j   i
//         ---------------------------
// arr =  | 2 | 3 | 0 | 1 | 7 | 4 | 6 |
//         ---------------------------
//
//           if arr[i] > arr[j] , increment the value of (i)th pos. by 1
//
//  dp =  | 1 | 2 | 1 | 1 | 1 | 1 | 1 |
//
//          j       i
//         ---------------------------
// arr =  | 2 | 3 | 0 | 1 | 7 | 4 | 6 |
//         ---------------------------
//
//
//              j   i
//         ---------------------------
// arr =  | 2 | 3 | 0 | 1 | 7 | 4 | 6 |
//         ---------------------------
//
//   // Here none j th postion are grater than arr[i] so skip
//
//    // continue this process and you will get the max value in dp arr
//    // That is the longest increasing subsequence
//

// NOTE: Longest Inc. Subsequence with O(n^2) time complexity

int longest_inc_subsequence(int arr[], int size) {
  int dp[MAXLENGTH] = {1};
  int subSeq[MAXLENGTH + 1] = {0};
  int indx = 1;

  for (int i = 1; i < size; i++) {
    int j = 0;
    while (j < i) {
      if (arr[j] < arr[i]) {
        dp[i] = MAX(dp[i], dp[j] + 1);
        subSeq[indx] = j; // code for finding the actual elements
      }
      j++;
    }
    indx++;
  }

  // code for just finding the largest element and its indx in dp
  int max = dp[0];
  int maxIndx = 0;
  for (int i = 1; i < size; i++) {
    if (dp[i] > max) {
      max = dp[i];
      maxIndx = i;
    }
  }

  // printing the elemetns with subsequence in opposite order
  // NOTE: start from the highest index val and loop throught its until 0 come
  int endIndx = maxIndx;
  printf("Elements are : [ ");
  while (endIndx != 0) {
    printf("%d ", arr[endIndx]);
    endIndx = subSeq[endIndx];
  }
  printf("] (In opposite order)\n");

  return max;
}

// NOTE:  Using O(n log n) time complexity
// I will do it later , it is too difficult for me
int optimize_LIS(int arr[], int size) { return 0; }

int main() {
  int arr[MAXLENGTH] = {2, 3, -1, 1, 7, 4, 6, 3};
  int size = 8;
  int long_inc_sub = longest_inc_subsequence(arr, size);
  printf("%d\n", long_inc_sub);
  return 0;
}

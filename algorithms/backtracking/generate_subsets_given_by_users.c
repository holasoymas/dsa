#include <stdio.h>
#define TRUE 1
#define FALSE 0

int is_a_solution(int a[], int k, int n) { return k == n; }

void process_solution(int arr[], int a[], int k, int n) {
  printf("{ ");
  for (int i = 1; i <= k; i++) {
    if (a[i]) {
      printf("%d, ", arr[i - 1]);
    }
  }
  printf("}\n");
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {
  c[0] = TRUE;
  c[1] = FALSE;
  *ncandidates = 2;
}

void backtrack(int arr[], int a[], int k, int n) {
  int c[2];
  int ncandidates;
  if (is_a_solution(a, k, n))
    process_solution(arr, a, k, n);
  else {
    k++;
    construct_candidates(a, k, n, c, &ncandidates);
    for (int i = 0; i < ncandidates; i++) {
      a[k] = c[i];
      backtrack(arr, a, k, n);
    }
  }
}

void generate_subsets(int arr[], int n) {
  int a[n];
  backtrack(arr, a, 0, n);
}

int main(void) {
  int n;
  printf("Enter the value of n : ");
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the value of %d th element : ", i);
    scanf("%d", &arr[i]);
  }

  generate_subsets(arr, n);

  return 0;
}

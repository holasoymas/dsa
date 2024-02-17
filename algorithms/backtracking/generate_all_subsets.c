#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define NMAX 10

// NOTE: How many subsets are there of an n-element set, say the integers {1, .
// . . , n}?
// Each new element doubles the number of possibilities, so there are 2^n
// subsets of n elements.

void backtrack(int a[], int k, int n);
int is_a_solution(int a[], int k, int n);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k);
void generate_subsets(int n);

int main() {
  int n;

  printf("Enter the number of elements in the set: ");
  scanf("%d", &n);

  generate_subsets(n);

  return 0;
}

void generate_subsets(int n) {
  int a[NMAX];
  backtrack(a, 0, n);
}

void backtrack(int a[], int k, int n) {
  int c[2];
  int ncandidates;
  int i;

  if (is_a_solution(a, k, n)) {
    process_solution(a, k);
  } else {
    k++;
    construct_candidates(a, k, n, c, &ncandidates);
    for (i = 0; i < ncandidates; i++) {
      a[k] = c[i];
      backtrack(a, k, n);
    }
  }
}

int is_a_solution(int a[], int k, int n) { return (k == n); }

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {
  c[0] = TRUE;
  c[1] = FALSE;
  *ncandidates = 2;
}

void process_solution(int a[], int k) {
  int i;

  printf("{");
  for (i = 1; i <= k; i++)
    if (a[i] == TRUE)
      printf(" %d,", i);
  printf(" }\n");
}

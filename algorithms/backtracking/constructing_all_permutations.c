#include <stdio.h>

#define NMAX 10
#define TRUE 1
#define FALSE 0

void backtrack(int a[], int k, int n);
int is_a_solution(int a[], int k, int n);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k, int n);

void generate_permutations(int n);

int main() {
  int n;
  printf("Enter the number of permutation to perform : ");
  scanf("%d", &n);
  generate_permutations(n);
  return 0;
}

void generate_permutations(int n) {
  int a[NMAX]; // Solution vector
  backtrack(a, 0, n);
}

void backtrack(int a[], int k, int n) {
  int c[NMAX];
  int ncandidates, i;

  if (is_a_solution(a, k, n)) {
    process_solution(a, k, n);
  } else {
    k++;
    construct_candidates(a, k, n, c, &ncandidates);
    for (i = 0; i < ncandidates; i++) {
      a[k] = c[i];
      backtrack(a, k, n);
    }
  }
}

int is_a_solution(int a[], int k, int n) { return k == n; }

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {
  int in_perm[NMAX + 1] = {FALSE}; // to keep track of numbers in permutation
  *ncandidates = 0;
  for (int i = 1; i <= k - 1; i++) {
    in_perm[a[i]] = TRUE; // Mark numbers already in the permutation
  }
  for (int i = 1; i <= n; i++) {
    if (!in_perm[i]) {
      c[*ncandidates] = i;
      (*ncandidates)++;
    }
  }
}

void process_solution(int a[], int k, int n) {
  int i;
  printf("{ ");
  for (i = 1; i <= k; i++) {
    printf("%d, ", a[i]);
  }
  printf("}\n");
}

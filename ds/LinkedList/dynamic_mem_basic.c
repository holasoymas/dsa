#include <stdio.h>
#include <stdlib.h>

int main() {

  int *p, *q;
  p = (int *)malloc((sizeof(int)));
  *p = 5;

  q = (int *)malloc(sizeof(int));
  *q = 8;
  // printf("%p\n", q);
  free(p);
  // p = NULL;
  printf("P = %d\n", *p);
  // p = q;
  *q = 6;
  // BUG: We re-asign the q in heap memory so when we free(q)
  // the initial q will be lost , there is no way that we can refrence the
  // original q , this is the example of memory leak so avoid this situation
  q = (int *)malloc(sizeof(int));
  // printf("%p\n", q);
  *q = 12;
  printf("P = %d and q = %d\n", *p, *q);
  return 0;
}

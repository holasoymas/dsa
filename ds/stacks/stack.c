#include "stack.h"
#include <stdio.h>

int main(void) {
  Stack s;
  __initStack__(&s);
  // push(&s, 12);
  push(&s, 82);
  push(&s, 62);
  push(&s, 6);
  push(&s, 2);
  // pop(&s);
  // pop(&s);
  int x = pop(&s);
  printf("Pop item of stack = %d\n", x);

  int isEmp = isEmpty(&s);
  printf("%d\n", isEmp);

  int stackTop = top(&s);
  printf("%d\n", stackTop);

  return 0;
}

#ifndef STACK
#define STACK

#define STACKSIZE 100
#include <stdbool.h>

typedef struct {
  char items[STACKSIZE];
  int top;
  int stackSize;
} Stack;

void __initStack__(Stack *);
int size(Stack *);
void push(Stack *, char value);
char pop(Stack *);
char top(Stack *);
bool isEmpty(Stack *);

#endif // STACK

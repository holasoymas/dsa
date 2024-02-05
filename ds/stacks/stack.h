#ifndef STACK
#define STACK

#include <stdio.h>
#define ERROR "An error occured"
#define STACKSIZE 100
#define TRUE 1
#define FALSE 0

typedef struct Stack {
  char items[STACKSIZE];
  int top;
  int stackSize;
} Stack;

void __initStack__(Stack *);
int size(Stack *);
void push(Stack *, char);
void pushNum(Stack *, int);
char pop(Stack *);
int popNum(Stack *s);
char top(Stack *);
int isEmpty(Stack *);

#endif // STACK

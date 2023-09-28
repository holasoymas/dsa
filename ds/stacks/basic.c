#include <stdbool.h>
#include <stdio.h>
#define STACKSIZE 100

typedef struct {
  int items[STACKSIZE];
  int top;
  int sizeOfStack;
} Stack;

void __initStack__(Stack *);
bool push(Stack *, int);
int pop(Stack *);
int stacktop(Stack *);
int sizeOfStack(Stack);
int isEmpty(Stack *);

int main(void) {
  Stack s;
  __initStack__(&s);
  // push(&s, 12);
  // push(&s, 1);
  // push(&s, 2);
  // push(&s, 17);
  push(&s, 82);
  push(&s, 62);
  push(&s, 6);
  push(&s, 2);
  // pop(&s);
  // pop(&s);
  int top = stacktop(&s);
  int sos = sizeOfStack(s);
  // int x = pop(&s);
  printf("Size of stack = %d\n", sos);
  // printf("Pop item of stack = %d\n", x);
  printf("Stack top is = %d\n", top);
  return 0;
}

void __initStack__(Stack *s) {
  (*s).top = -1;
  // s->top = -1;
}

bool push(Stack *s, int val) {
  if (s->top >= STACKSIZE - 1) {
    printf("Stack Overflow\n");
    return false;
  }
  s->items[++s->top] = val;
  return true;
}

int pop(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack underflow\n");
    return -1;
  }
  return s->items[--s->top];
}

int stacktop(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack is empty\n");
    return -1;
  }
  return s->items[s->top];
}

int isEmpty(Stack *s) {
  if (s->top == -1) {
    return 1;
  }
  return 0;
}

int sizeOfStack(Stack s) { return s.top + 1; }

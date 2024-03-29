#include "stack.h"

void __initStack__(Stack *s) { s->top = -1; }

int size(Stack *s) { return s->top + 1; }

int isEmpty(Stack *s) {
  if (size(s) == -1) {
    return TRUE;
  }
  return FALSE;
}

void push(Stack *s, char value) {
  // if (s->top >= STACKSIZE) {
  //   fprintf(stderr, "An error occured : %s\n", "Stack is full");
  // } else {
  //   s->items[++s->top] = value;
  // }
  // NOTE: If the stack is full do nothing i.e value of s.top is unchanged
  // but if it is not full increment the s.top and assign that index value
  // to the variable "value";

  s->top = (s->top >= STACKSIZE - 1)
               ? (fprintf(stderr, ERROR " : %s\n", "Stack overflow"), s->top)
               : (s->items[++s->top] = value, s->top);
}

void pushNum(Stack *s, int value) {
  s->top = (s->top >= STACKSIZE - 1)
               ? (fprintf(stderr, ERROR " : %s\n", "Stack overflow"), s->top)
               : (s->items[++s->top] = value, s->top);
}

int popNum(Stack *s) {
  if (isEmpty(s)) {
    fprintf(stderr, ERROR " : %s\n", "Stack underflow");
  }
  return s->items[s->top--];
}

char pop(Stack *s) {
  if (isEmpty(s)) {
    fprintf(stderr, ERROR " : %s\n", "Stack underflow");
    return -1;
  }
  return s->items[s->top--];
}

char top(Stack *s) {
  if (isEmpty(s)) {
    fprintf(stderr, ERROR " : %s\n", "Stack underflow");
    return -1;
  }
  return s->items[s->top];
}

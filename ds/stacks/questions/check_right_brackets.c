#include "stack.h"
#include <stdio.h>

// TODO: [A+B] [{B+D}+C] {V+5} //CORRECT BRACKETS FORMAT
// TODO: (B+D) [{B+A)] (A+D] //INCORRECT BRACKET FORMAT

char matchBraces(char ch) {
  if (ch == '(') {
    return ')';
  } else if (ch == '{') {
    return '}';
  }
  return ']';
}

int main(void) {
  Stack s;
  __initStack__(&s);
  FILE *file = fopen("brackets.txt", "r");
  if (file == NULL) {
    perror("Error occured while opening a file\n");
    return -1;
  }
  // int countSmallBrackets = 0, countCurlyBrackets = 0, countBigBrackets = 0;
  int ch;
  char curChar;
  while ((ch = fgetc(file)) != EOF) {
    curChar = (char)ch;
    if (curChar == '(' || curChar == '{' || curChar == '[') {
      push(&s, curChar);
    }
    if (curChar == ')' || curChar == '}' || curChar == ']') {
      if (isEmpty(&s)) {
        fprintf(stderr,
                "An error occured : Closed brackets canno't come in advance\n");
        return -1;
      } else if (curChar != matchBraces(top(&s))) {
        fprintf(stderr, "An error occured : Got %c instead of %c\n", curChar,
                top(&s));
        return -1;
      } else {
        pop(&s);
      }
    }
  }
  printf("Brackets are in the right position\n");
  return 0;
}

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAXSTRING 20

int getsymbl(char str[], int length, int *ppos);
int expr(char *, int, int *);
int term(char *, int, int *);
int factor(char *, int, int *);

int main() {

  char str[MAXSTRING];
  printf("Enter the expression : \n");
  scanf("%s", str);

  int length, pos;

  length = strlen(str);
  pos = 0;

  if (expr(str, length, &pos) == TRUE && pos >= length)
    printf("Valid :)\n");
  else
    printf("Invalid ):\n");

  return 0;
}

int getsymbl(char str[], int length, int *ppos) {
  char c;
  if (*ppos < length) { // if pointer position is less than len c == str[pos] ;
    c = str[*ppos];
  } else {
    c = ' '; // if length is grater make c empty;
  }
  (*ppos)++;
  return c;
}

int expr(char str[], int length, int *ppos) {
  // look for a term , every valid term is a valid expression
  if (term(str, length, ppos) == FALSE) {
    return FALSE;
  }
  //
  if (getsymbl(str, length, ppos) != '+') {
    (*ppos)--;
    return TRUE;
  }
  return term(str, length, ppos);
}

int term(char str[], int length, int *ppos) {
  if (factor(str, length, ppos) == FALSE) {
    return FALSE;
  }
  if (getsymbl(str, length, ppos) != '*') {
    (*ppos)--;
    return TRUE;
  }
  return factor(str, length, ppos);
}

int factor(char str[], int lenght, int *ppos) {
  int c;
  if ((c = getsymbl(str, lenght, ppos)) != '(') {
    return isalpha(c);
  }
  return (expr(str, lenght, ppos) && (getsymbl(str, lenght, ppos) == ')'));
}

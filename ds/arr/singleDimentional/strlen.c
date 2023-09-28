#include <stddef.h>
#include <stdio.h>
#include <string.h>
#define STRSIZE 20

// FIX: This file is highly buggy so fix it

int strlength(char[]);

int main(void) {
  char name[STRSIZE] = "Mahesh Chualgain";
  int length = strlength(name);
  int a = sizeof(name);
  int len = strlen(name);
  printf("Length of str is %d\n", length);
  printf("A is of  is %d\n", a);
  printf("Strlen function  is = %d\n", len);
  return 0;
}

int strlength(char lenght[]) {
  int i;
  for (i = 0; lenght[i] != '\0'; i++)
    ;
  return i;
}

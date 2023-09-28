#include <stdio.h>

extern int x;
struct {
  char name[10];
  char midname;
  char lname[10];
} sname, ename; // this create two struct variables, with each having 3 members

// we can also give a tag(name ) to the struct

struct nametype {
  char first[10];
  char mid;
  char last[10];
};

typedef struct {
  char first[10];
  char mid;
  char last[10];
} NAMETYPE;

int main(void) {

  NAMETYPE person;
  struct nametype per;
  printf("%d\n", x);
  return 0;
};

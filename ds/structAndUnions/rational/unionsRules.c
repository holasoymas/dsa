#include <stdio.h>
#define LIFE 1
#define AUTO 2
#define HOME 3

int x = 12;

struct addr {
  char street[50];
  char city[20];
};

struct date {
  int month;
  int day;
  int year;
};

struct policy {
  char name[20];                  // Fided memory location
  struct addr address;            // Fixed memory location
  int amount;                     // Fixed memory location
  int kind; /*LIFE AUTO or HOME*/ // Fixed memory location

  // NOTE: Union allocate the value which member have the higest memory
  // allocation and allocate upto that much space , so we can only access union
  // member only one at a time

  union { // NOTE: choose one of the three depending upon the kind value
    struct {
      char beneficiary[20];
      struct date birthday;
    } life;
    struct {
      int autodeduct;
      char license[10];
      char state[3];
      char model[15];
      int year;
    } automovil;
    struct {
      int homededuct;
      int yearbuilt;
    } home;
  } policyinfo;
};

int main(void) { return 0; }

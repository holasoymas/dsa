

// Overloading allows a same function to apply different function if they have
// different parameters

#include <cstdio>
class Rational {
  int n; // numenator
  int d; // denomenator

public:
  Rational setRational(int n, int d);
  Rational setRational(int n); // when a denomenator is missing it is mean n/1
};
int main(int argc, char *argv[]) {
  printf("This is Overloading chapter\n");
  return 0;
}

#include <iostream>

class Rational {
  int numenator;
  int denomenator;
  Rational reduce(int n, int d);

public:
  void printRational();
  void reduce();
};

// WARNING: If you need to implement methods(function) outside of a class
// you need to mention the classname like :

void Rational::printRational() {
  printf("this is the format of the rational num\n");
}

int main(int argc, char *argv[]) {
  std::cout << "HELLO WORLD\n";
  return 0;
}

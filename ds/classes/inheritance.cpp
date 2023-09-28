#include <cstdio>

// WARNING: private - only the class is able to acces it who define it

// WARNING: protected - only the class who inherited that class.Like Integer in
// this example can access Rational fields like n and d.

// WARNING : public - anyone can access and manipulate it

class Rational {
protected:
  int n;
  int d;

public:
  Rational setRational(Rational n, Rational d);
  Rational setRational(Rational n);
};

class Integer : public Rational { // NOTE: Here, public mean the public and
                                  // protected members of Rational will be the
                                  // same in Integer, public and protected
public:
  Integer setRational(int n, int d); // denomenator is 1
  Integer setRational(int n);
};

class Integer2 : protected Rational {};
// NOTE: hERE, protected represent public members of Rational will become
// protected members of Integer2

class Integer3 : private Rational {};
// NOTE: Here, public and protected members of Rational would become private
// members of Integer3

Integer Integer::setRational(int a, int b) {
  Integer Int;
  if (b != 1) {
    printf("Error : Non integer assignement");
  }
  Int.n = a;
  Int.d = b;
  return Int;
}

Integer Integer::setRational(int n) {
  Integer Int;
  Int.n = n;
  Int.d = 1;
  return Int;
}

int main(int argc, char *argv[]) {
  printf("THis is inheritance\n");
  return 0;
}

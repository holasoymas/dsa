

// NOTE: A constructor is a special method  of a class that is invoked whenever
//  an obj of a class is created

class Rational {
protected:
  int n;
  int d;

public:
  void printRational(int a, int b);
  Rational(void);         // constructor
  Rational(int n);        // constructor
  Rational(int n, int d); // constructor
};

Rational::Rational(void) {
  n = 0;
  d = 1;
}

Rational::Rational(int a) {
  n = a;
  d = 1;
}

Rational ::Rational(int a, int b) {
  n = a;
  d = b;
}

int main(int argc, char *argv[]) {
  Rational r1; // set the first constructor Rational(void) since no parameter is
               // given n = 0, d = 1
  Rational r2(3);    // second constructor is set , n = 3, d = 1
  Rational r3(2, 3); // Third constructor is set

  // NOTE: We can also use new keywoard

  Rational *rat1 = new Rational;
  Rational *rat2 = new Rational(3);
  Rational *rat3 = new Rational(3, 2);

  delete rat1;
  return 0;
}

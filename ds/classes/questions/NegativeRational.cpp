
#include <cstdio>
class Rational {
public:
  int n;
  int d;

public:
  static Rational sub(Rational r1, Rational r2) {
    Rational r;
    Rational tmp1 = Rational::reduce(r1.n, r1.d);
    Rational tmp2 = Rational::reduce(r2.n, r2.d);
    r.n = (r1.n * r2.d) - (r1.d * r2.n);
    r.d = r1.d * r2.d;
    return r;
  }

  Rational(void) {
    n = 1;
    d = 1;
  }
  static Rational reduce(int n, int d) {
    int numo = n;
    int deno = d;

    Rational r;
    int a, b, rem;
    if (n > d) {
      a = n;
      b = d;
    } else if (d > n) {
      a = d;
      b = n;
    } else {
      r.n = 1;
      r.d = 1;
      return r;
    }

    while (b != 0) {
      rem = a % b;
      a = b;
      b = rem;
    }
    r.n = (numo / a);
    r.d = deno / a;
    // if (n > 0 && d > 0) {
    //   r.n = numo / a;
    //   r.d = deno / a;
    // } else if (n < 0 && d < 0) {
    //   r.n = numo / a;
    //   r.d = deno / a;
    // } else {
    //   int negate = numo / a;
    //   r.n = -negate;
    //   r.d = deno / a;
    // }
    return r;
  }
  Rational(int a, int b) {
    n = a;
    d = b;
  }
};

int main(int argc, char *argv[]) {
  Rational r = Rational::reduce(100, 10);
  printf("the value is %d and %d\n", r.n, r.d);
  Rational r1(11, 5), r2(10, 3);
  Rational sub = Rational::sub(r1, r2);
  printf("Sub = %d and %d\n", sub.n, sub.d);
  return 0;
}

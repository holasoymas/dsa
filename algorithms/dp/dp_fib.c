#include <stdio.h>
#define UNKNOWN -1 // contents denote an empty cell
#define MAX 200
long f[MAX + 1]; // array for caching computed fib values

long long fib(long long n) {
  if (f[n] == UNKNOWN) { // if f[n] is -1 , compute f[n]
    f[n] = fib(n - 1) + fib(n - 2);
  }
  return f[n];
}

long long fib_driver(long long n) {
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = UNKNOWN; // setting all the field of cache to -1
  }
  return fib(n);
}

// NOTE: A more efficient program which remove recursion

long long fib_dp(long long n) {
  long f[MAX + 1];
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}

// NOTE: A more even efficent program which remove recursion including space

long long fib_ultimate(long long n) {
  long long next;
  long long back2 = 0;
  long long back1 = 1;
  for (int i = 2; i < n; i++) {
    next = back1 + back2;
    back2 = back1;
    back1 = next;
  }
  return (back1 + back2);
}

int main() {
  long long f = fib_driver(199);
  long long f_without_recursion = fib_dp(199);
  long long fib_ult = fib_ultimate(199);
  printf("%lld\n", f);
  printf("%lld\n", f_without_recursion);
  printf("%lld\n", fib_ult);
  return 0;
}

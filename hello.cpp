// #include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {

  char text[] = "aabrakadabra";
  char tofind[] = "adabra";
  int t = sizeof(text);
  int p = sizeof(tofind);
  // cout << t << p << endl;
  printf("The size of the string are %d and %d\n", t, p);
  int i, j;
  for (i = 0; i <= (t - p); i++) {
    j = 0;
    while ((j < p) && (text[i + j] == tofind[j])) {
      j += 1;
    }
    if (j == p) {
      printf("this is miracle %d", i);
    }
  }
  return 0;
}

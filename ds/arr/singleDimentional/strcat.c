#include <stdio.h>
#include <string.h>

void strcon(char s1[], char s2[], int size) {
  int i, j;
  int s1len = strlen(s1);
  int s2len = strlen(s2);
  int totallen = s1len + s2len;
  // int tc = sizeof(s1);
  if (totallen >= size) {
    printf("OPPS CAPACITY FULL , YOU FOOL\n");
    return;
  }
  for (i = 0; i <= s2len; i++) {
    s1[s1len + i] = s2[i];
  }
  s1[i] = '\0';
}

int main(void) {
  char fname[30] = "Mahesh";
  char lname[20] = "Chaulagain";
  strcon(fname, lname, 55);
  printf("%s\n", fname);
  return 0;
}

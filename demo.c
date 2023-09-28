#include <stdio.h>
#include <string.h>

int main(void) {
  char name[5][20], tmp[20];
  printf("Enter your name ?\n");
  for (int i = 0; i < 5; i++) {
    printf("Enter the %dth name : ", i + 1);
    fgets(name[i], sizeof(name), stdin);
  }
  // printf("%s\n", name);
  // sort them
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (strcmp(name[i], name[j]) > 0) {
        strcpy(tmp, name[i]);
        strcpy(name[i], name[j]);
        strcpy(name[j], tmp);
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    printf("%s\n", name[i]);
  }

  return 0;
}

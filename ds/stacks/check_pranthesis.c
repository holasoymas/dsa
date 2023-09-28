#include <stdio.h>

int main() {
  int countOpenBrackets = 0;
  FILE *file = fopen("example.txt", "r");

  if (file == NULL) {
    perror("Error opening the file");
    return 1;
  }
  int ch;
  char currentChar;
  while ((ch = fgetc(file)) != EOF) {
    // Print the character
    currentChar = (char)ch;
    if (currentChar == '(') {
      countOpenBrackets++;
    }
    if (countOpenBrackets == 0 && currentChar == ')') {
      printf("OPPS, the char ')' cannot come first before '('.\n");
      return -1;
    }
    if (currentChar == ')') {
      countOpenBrackets--;
    }
    // printf("%c\n", currentChar);
  }
  printf("Yep, the syntax is all correct.:)))))))\n");
  // Close the file
  fclose(file);

  return 0;
}

#include <cstdio>
#include <cstring>

class String {
public:
  // char str[];

  static int getStrlen(char str[]) {
    int i = Strlen(str);
    return i;
  }

private:
  static int Strlen(char str[]) {
    int i = strlen(str);
    return i;
  }
};

int main(int argc, char *argv[]) {
  char mychar[] = "Hello i am mas";
  int str = String::getStrlen(mychar);
  printf("The lengt of int is %d\n", str);
  return 0;
}

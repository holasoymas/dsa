#include <stdio.h>
#include <unistd.h>

int getNumberOfCores() { return sysconf(_SC_NPROCESSORS_ONLN); }
int getNumberOfThreads() { return sysconf(_SC_NPROCESSORS_CONF); }

int main() {
  int cores = getNumberOfCores();
  int threads = getNumberOfThreads();
  printf("Number of CPU cores: %d\n", cores);
  printf("Number of CPU threads: %d\n", threads);
  return 0;
}

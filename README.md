# Data Structures and Algorithms (DSA)

This repository contains various data structures and algorithm problems and their solutions.

## Table of Contents

* [Tower of Hanoi](#tower-of-hanoi)
* [Numbers Of Cores And Threads](#numbers-of-cores-and-threads)

## Tower of Hanoi

Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules: 
1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3. No disk may be placed on top of a smaller disk.

### C solution
```
#include <stdio.h>

void towers(int, char, char, char);

int main() {
  int n;
  printf("Enter the number of tower : \n");
  scanf("%d", &n);
  towers(n, 'A', 'B', 'C');
  return 0;
}

void towers(int n, char from, char to, char aux) {
  if (n == 1) {
    printf("Move disk %d from ring %c to ring %c\n", n, from, to);
    return;
  }
  towers(n - 1, from, aux, to);
  printf("Move disk %d from ring %c to ring %c\n", n, from, to);
  towers(n - 1, aux, from, to);
}
```

## Numbers Of Cores And Threads 

Simple c program to find the numbers of cores and threads in your system 

### C solution 
```
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
```


#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#define MAX_ELEMENTS 100

typedef struct {
  int items[MAX_ELEMENTS];
  int first, last;
  int size;
} Queue;

void __queueinit__(Queue *q);
bool isFull(Queue *q);
bool isQueueEmpty(Queue *q);
int enQueue(Queue *q, int data);
int deQueue(Queue *q);
void displayQueue(Queue *q);

#endif /* QUEUE_H */

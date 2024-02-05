#include "queue.h"

void __queueinit__(Queue *q) {
  // Initializing the first and last element same(last index) so that first
  // element start at index 0
  q->first = q->last = 0;
  q->size = 0;
}

bool isFull(Queue *q) {
  // if q->size == (MAX_ELEMENTS - 1) it return 1
  return (q->size == (MAX_ELEMENTS - 1));
}

bool isQueueEmpty(Queue *q) {
  // if queue size is 0 return empty ,
  return ((q->size == 0) ? true : false);
}

int enQueue(Queue *q, int data) {
  if (isFull(q)) {
    printf("Stack overflow ):\n");
    return -1;
  }
  q->items[q->last] = data;
  // NOTE:incrementing the value of q.last and when it reaches the last index,
  // use the % symbol to make it circular nature
  q->last = (q->last + 1) % MAX_ELEMENTS;
  q->size++;
  return 0;
}

int deQueue(Queue *q) {
  if (isQueueEmpty(q)) {
    printf("Stack Underflow ):\n");
    return -1;
  }
  int removed = q->items[q->first];
  // q.first is the first first element so removing it make the next element
  // q.first
  q->first = (q->first + 1) % MAX_ELEMENTS;
  q->size--;
  return removed;
}

void displayQueue(Queue *q) {
  if (isQueueEmpty(q)) {
    printf("Queue is empty ):\n");
    return;
  }
  int i;
  i = q->first;
  do {
    printf("%d <-- ", q->items[i]);
    // Move to the next element, considering the circular nature
    i = (i + 1) % MAX_ELEMENTS;
  } while (i != q->last); // end if it reach the last element
  printf("\n");
}

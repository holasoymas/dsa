#include <stdbool.h>
#include <stdio.h>
#define MAX_ELEMENTS 20

typedef struct {
  int items[MAX_ELEMENTS];
  int first, last;
  int size;
} Queue;

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

bool isEmpty(Queue *q) {
  // if queue size is 0 return empty ,
  return ((q->size == 0) ? 1 : 0);
}

int insertQueue(Queue *q, int data) {
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

int removeQueue(Queue *q) {
  if (isEmpty(q)) {
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
  if (isEmpty(q)) {
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

int main() {
  Queue q;
  __queueinit__(&q);
  insertQueue(&q, 3);
  insertQueue(&q, 9);
  insertQueue(&q, 0);
  insertQueue(&q, 7);
  insertQueue(&q, 1);
  insertQueue(&q, 8);
  displayQueue(&q);
  removeQueue(&q);
  displayQueue(&q);
  printf("Queue size is = %d\n", q.size);
  return 0;
}

#include "queue.h"

int main() {
  Queue q;
  __queueinit__(&q);
  enQueue(&q, 3);
  enQueue(&q, 9);
  enQueue(&q, 0);
  enQueue(&q, 7);
  enQueue(&q, 1);
  enQueue(&q, 8);
  displayQueue(&q);
  deQueue(&q);
  displayQueue(&q);
  printf("Queue size is = %d\n", q.size);
  return 0;
}

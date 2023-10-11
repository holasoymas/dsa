#include "doublyLinkedList.h"
#include <stdio.h>

int main() {
  DLL *head = NULL;
  DLL *tail = NULL;

  insertNode(&head, &tail, 12);
  insertNode(&head, &tail, 42);
  insertNode(&head, &tail, 55);
  insertNode(&head, &tail, 77);
  insertNode(&head, &tail, 34);
  displayNode(&head, &tail);
  deleteHead(&head, &tail);
  displayNode(&head, &tail);
  deleteTail(&head, &tail);
  displayNode(&head, &tail);
  deleteDLL(&head, &tail, 55);
  displayNode(&head, &tail);
  return 0;
}

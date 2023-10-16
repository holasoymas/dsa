#include <stdio.h>
#include <stdlib.h>

typedef struct List {
  int data;
  struct List *next;
} List;

void insert(List **head, List **tail, int data) {

  List *tmp = (List *)malloc(sizeof(List));
  tmp->data = data;
  tmp->next = NULL;
  if (*head == NULL) {
    *head = tmp;
    *tail = tmp;
    return;
  }
  (*tail)->next = tmp;
  *tail = tmp;
}

void reverseList(List **head, List **tail) {
  List *prev = NULL;
  List *current = *head;
  List *next;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  // Update the head and tail pointers
  *tail = *head;
  *head = prev;
}

void displayList(List *head, List *tail) {
  if (head == NULL) {
    printf("Empty List\n");
    return;
  }
  List *ptr = head;
  do {
    printf("%p | %d , %p|--->", ptr, ptr->data, ptr->next);
    ptr = ptr->next;
  } while (ptr != NULL);
  printf("\n");
}

int main() {
  List *head = NULL;
  List *tail = NULL;
  insert(&head, &tail, 11);
  insert(&head, &tail, 45);
  insert(&head, &tail, 26);
  insert(&head, &tail, 56);
  displayList(head, tail);
  printf("After reversing : \n");
  reverseList(&head, &tail);
  displayList(head, tail);
  return 0;
}

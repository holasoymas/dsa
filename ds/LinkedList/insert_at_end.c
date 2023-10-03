#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void insertAtEnd(Node **head, int data) {
  Node *ptr, *tmp;
  ptr = *head;

  tmp = (Node *)malloc(sizeof(Node));
  tmp->data = data;
  tmp->next = NULL;

  if (ptr == NULL) {
    *head = tmp;
  } else {
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = tmp;
  }
}

void deleteAtEnd(Node **head) {
  Node *tmp, *ptr;
  ptr = *head;
  if (ptr == NULL) {
    printf("Void deletion\n");
    return;
  }
  // if there is only one element in the list node->next->next doesn't work
  if (ptr->next == NULL) {
    free(ptr);
    *head = NULL;
    return;
  }
  while (ptr->next->next != NULL) {
    ptr = ptr->next;
  }

  tmp = ptr;
  ptr = ptr->next;
  free(ptr);
  ptr = NULL;
  tmp->next = NULL;
}

void displayNode(Node *head) {
  Node *ptr = head;
  while (ptr != NULL) {
    printf("|%d|<--", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

void freeNode(Node **head) {
  Node *ptr, *tmp;
  ptr = *head;
  while (ptr != NULL) {
    tmp = ptr;
    ptr = ptr->next;
    free(tmp);
    tmp = NULL;
  }
}

int main() {

  Node *head = NULL;
  insertAtEnd(&head, 12);
  insertAtEnd(&head, 52);
  insertAtEnd(&head, 86);
  deleteAtEnd(&head);
  displayNode(head);
  freeNode(&head);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void insertAtEnd(Node *h, int data) {

  Node *ptr, *tmp;

  ptr = h;

  tmp = (Node *)malloc(sizeof(Node));
  tmp->data = data;
  tmp->next = NULL;

  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = tmp;
}

/*
 head itself is a pointer so , **head is pointer to the pointer
(Head = NULL So it doesnt point to anything)

//NOTE: Insert at the begining

   *head
  ------                               ------
 |NULL  |                   &head =   |0x1000|
  ------                               ------
  0X1000 ---|                           0x600
            |
            |
            -----------------------
                                  |
   tmp                            |   tmp (*head)
  ------                          |   ------
 |      |                         |  | 12   | data
  ------ (Heap Allocation)        |   ------
 |      |                         |  |0x1000| *next
  ------                          |   ------
  0x2000                          ----0x2000 ---------------
                                                           |
   tmp2                                                    |    tmp2 (*head)
  ------                                                   |   ------
 |      |                                                  |  | 33   | data
  ------ (Heap Allocation)                                 |   ------
 |      |                                                  |  |0x2000| next*
  ------                                                   |   ------
  0x3000                                                    ---0x3000

*/

void insertAtBegining(Node **head, int data) {

  Node *tmp = (Node *)malloc(sizeof(Node));

  tmp->data = data;
  tmp->next = *head; // pointing the next to the value of dereferenced head
  *head = tmp;
}

void displayNode(Node *node) {
  Node *n = node;
  while (n != NULL) {
    printf("|%d|<--", n->data);
    n = n->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL;
  insertAtBegining(&head, 12);
  insertAtBegining(&head, 32);
  insertAtBegining(&head, 15);
  insertAtBegining(&head, 52);
  displayNode(head);
  return 0;
}

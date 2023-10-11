#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

typedef struct DoublyLinkedList {
  int data;
  struct DoublyLinkedList *left;
  struct DoublyLinkedList *right;
} DLL;

void insertNode(DLL **head, DLL **tail, int data);
void displayNode(DLL **head, DLL **tail);
void deleteHead(DLL **head, DLL **tail);
void deleteTail(DLL **head, DLL **tail);
void deleteDLL(DLL **head, DLL **tail, int data);

#endif // !DOUBLY_LINKED_LIST

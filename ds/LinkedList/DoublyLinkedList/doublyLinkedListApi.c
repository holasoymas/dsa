#include <stdio.h>
#include <stdlib.h>

#include "doublyLinkedList.h"

void insertNode(DLL **head, DLL **tail, int data) {

  DLL *ptr = *head;
  DLL *tmp = (DLL *)malloc(sizeof(DLL));

  if (ptr == NULL) {
    tmp->data = data;
    tmp->left = tmp;
    tmp->right = tmp;
    *head = tmp;
    *tail = tmp;
  }

  (*tail)->right = tmp; // Pointing the last node to the newly created node;
  tmp->data = data;
  // Pointing the newly created left node to the last node(tail)
  tmp->left = *tail;
  tmp->right = *head; // Newly created node will be the last node so point the
                      // tmp->right to head creating a circular behaviour

  // Head's node left data will point to the last node (tmp)
  (*head)->left = tmp;
  *tail = tmp; // Now update the value of tail
}

void deleteHead(DLL **head, DLL **tail) {
  DLL *ptr = *head;
  if (ptr == NULL) {
    printf("Void deletion, EMpty list\n");
    return;
  }
  // Updating the value of tail to the ptr->right as head is about to go
  (*tail)->right = ptr->right;
  // ptr->right gives the value next node which ptr points to and if we do
  //(ptr->right)->left , we are asking for the next node left data so we can
  // point is to tail as this is going to be new head
  (ptr->right)->left = *tail;
  // Updatring the head to the next node
  *head = ptr->right;
  free(ptr);
  ptr = NULL;
}

void deleteTail(DLL **head, DLL **tail) {
  DLL *ptr = *tail;
  if (ptr == NULL) {
    printf("VOid deletion,Empty list\n");
    return;
  }

  ((*tail)->left)->right = *head;
  (*head)->left = (*tail)->left;
  *tail = (*tail)->left;
  free(ptr);
  ptr = NULL;
}

void deleteDLL(DLL **head, DLL **tail, int data) {
  DLL *ptr = *head;
  if (ptr == NULL) {
    printf("Void deletion , Empty list\n");
  }
  if (ptr->data == data && ptr == *head) {
    deleteHead(head, tail);
    return;
  }
  if (ptr->data == data && ptr == *tail) {
    deleteTail(head, tail);
    return;
  }
  do {
    if (ptr->data == data) {
      // Assign the prefious node right data to the next node;
      (ptr->left)->right = ptr->right;
      // Assign the next node left data to the previous node ;
      (ptr->right)->left = ptr->left;
      free(ptr);
      ptr = NULL;
      return;
    }
    ptr = ptr->right;

  } while (ptr->right != *head);
  printf("Void deletion , %d not found.\n", data);
  return;
}

void displayNode(DLL **head, DLL **tail) {
  DLL *ptr = *head;
  if (ptr == NULL) {
    printf("EMpty List\n");
    return;
  }

  // HACK:  But when to stop traversing in  circular linked list ?
  // Ans -> Traverse until ptr->next point to head node.
  // We will know that we have reach our tail node, so stop there

  do {
    printf("(%p)| %p, %d , %p |--> ", ptr, ptr->left, ptr->data, ptr->right);
    ptr = ptr->right;
  } while (ptr != (*head));
  printf("\n");
}

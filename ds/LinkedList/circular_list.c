#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct CircularNode {
  int data;
  struct CircularNode *next;
} CircularNode;

void insertNode(CircularNode **head, CircularNode **tail, int data) {

  CircularNode *ptr = *head;

  CircularNode *tmp = (CircularNode *)malloc(sizeof(CircularNode));
  tmp->data = data;
  tmp->next = NULL;

  if (ptr == NULL) {
    *head = tmp;
    *tail = tmp;

    // If there is only one node , the head and tail is the same
    (*tail)->next = *head;
    return;
  }

  // HACK: Update the tmp->next to (*head) as tmp is the last node
  // This must be done first as if we do (*tail)->next = tmp without this
  // we will make a problem as tmp->next is NULL , so first update this
  tmp->next = (*head);

  // HACK: After new node is inserted , that new node become tail ,
  // That previous tail before insertion , update that tail to point to the new
  // tail (tmp)
  (*tail)->next = tmp;

  // HACK: Update the tail pointer to the tmp (new latest tail)
  *tail = tmp;
}

void deleteHead(CircularNode **head, CircularNode **tail) {

  CircularNode *ptr = *head;

  if (ptr == NULL) {
    printf("Void deletion, Empty List\n");
    return;
  }

  // This is necessary if we have only one node
  if (*head == *tail) {
    free(*head);
    *head = NULL;
    return;
  }

  // Update the head pointer to the next pointer
  *head = ptr->next;
  free(ptr);
  ptr = NULL;
  // Update the tail to the next head
  (*tail)->next = *head;
}

void deleteTail(CircularNode **head, CircularNode **tail) {
  CircularNode *ptr = *head;
  CircularNode *tailNode = *tail;
  if (ptr == NULL) {
    printf("Void deletion, Empty List\n");
    return;
  }

  // This is necessary if we have only one node because
  if (*head == *tail) {
    free(*tail);
    *tail = NULL;
    return;
  }
  //  finding the second last node
  while (ptr->next != *tail) {
    ptr = ptr->next;
  }
  // Assign the second last node as ptr->next = *head as tail node is going to
  // be delete
  ptr->next = *head;
  // Assigning the second last node to the tail node
  *tail = ptr;
  free(tailNode);
  tailNode = NULL;
}

CircularNode *findBefore(CircularNode **head, CircularNode **tail, int num) {

  CircularNode *ptr = *head;

  if (ptr == NULL) {
    return NULL;
  }
  if (ptr->data == num) {
    return NULL; // Head is the first element, no element is before it
  }
  do {
    if (ptr->next->data == num) {
      return ptr;
    }
    ptr = ptr->next;
  } while (ptr != (*tail));

  printf("No element found, %d doesn't exist in the list\n", num);
  return NULL;
}

// WARNING : Remember that this implementation has a flaw , if there were
// multiple nodes with the same data as there value it will only delete the
// first node with that value

CircularNode *deleteNode(CircularNode **head, CircularNode **tail,
                         int toDelElmnt) {
  CircularNode *ptr = *head;
  if (ptr == NULL) {
    printf("Void deletion of item on empty list\n");
    return NULL;
  }

  // HACK: This is also know known as shallow Copy , when doing a shallow copy
  // you get the reference to the original object so if you cange something in
  // original object changes will get reflected in shallow copy also. So if you
  // free the original object the shallow copy will also get greed and accessing
  // that freed object will get you in undesired situation. So if you need to
  // free something and return it, it is not possible

  // CircularNode *deleteNode = toDeleteNode; // making a shallow copy (bad
  // idea)

  // HACK: To solve that we need another type of copy "deep copy" which copy the
  // content of the original object not reference it.So if you make in original
  // object it will not reflect on the deep copyed object and vice-versa.

  CircularNode *deleteNode = (CircularNode *)malloc(sizeof(CircularNode));

  if (ptr->data == toDelElmnt && ptr == *head) {
    *deleteNode = **head; // deep copy the value of head into deleteNode
    deleteHead(head, tail);
    return deleteNode;
  }

  if (ptr->data == toDelElmnt && ptr == *tail) {
    *deleteNode = **tail; // deep copy the value of tail into deleteNode
    deleteTail(head, tail);
    return deleteNode;
  }

  CircularNode *FoundBefore = findBefore(head, tail, toDelElmnt);
  if (FoundBefore == NULL) {
    return NULL;
  }
  CircularNode *toDeleteNode = FoundBefore->next;

  *deleteNode = *toDeleteNode;

  FoundBefore->next = toDeleteNode->next;
  free(toDeleteNode);
  toDeleteNode = NULL;
  return deleteNode;
}

void displayNode(CircularNode **head, CircularNode **tail) {
  CircularNode *ptr = *head;
  if (ptr == NULL) {
    printf("EMpty List\n");
    return;
  }

  // HACK:  But when to stop traversing in  circular linked list ?
  // Ans -> Traverse until ptr->next point to head node.
  // We will know that we have reach our tail node, so stop there

  do {
    printf("(%p)| %d , %p |--> ", ptr, ptr->data, ptr->next);
    ptr = ptr->next;
  } while (ptr != (*head));
  printf("\n");
}

void freeNode(CircularNode **head, CircularNode **tail) {
  CircularNode *ptr, *tmp;
  ptr = *head;

  do {
    tmp = ptr;
    ptr = ptr->next;
    free(tmp);
    tmp = NULL;
  } while (ptr != *tail);
  // while traversing only the tail node is left so free it
  free(*tail);
  *head = NULL;
  *tail = NULL;
}

int main() {
  CircularNode *tail = NULL;
  CircularNode *head = NULL;

  insertNode(&head, &tail, 12);
  insertNode(&head, &tail, 76);
  insertNode(&head, &tail, 52);

  displayNode(&head, &tail);

  CircularNode *deleted = deleteNode(&head, &tail, 12);
  if (deleted != NULL) {
    printf("Data = %d, Addr = %p\n", deleted->data, deleted->next);
    displayNode(&head, &tail);
    free(deleted);
  }
  freeNode(&head, &tail);
  // CircularNode *FoundedElmnt = findBefore(&head, &tail, 62);
  // printf("%d\n", FoundedElmnt->data);
  // printf("%p\n", FoundedElmnt->next);
  // deleteHead(&head, &tail);

  // displayNode(&head, &tail);

  // deleteTail(&head, &tail);

  // displayNode(&head, &tail);

  // deleteHead(&head, &tail);

  // displayNode(&head, &tail);

  // deleteHead(&head, &tail);

  // displayNode(&head, &tail);
  return 0;
}

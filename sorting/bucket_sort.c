#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insertBucket(struct Node **bucket, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;

  // if bucket is null set the next value null as there are no elmnts
  if (*bucket == NULL) {
    newNode->next = NULL;
    *bucket = newNode;
    return;
  }

  // set the next value points as bucket and make that newNode a head
  newNode->next = *bucket;
  *bucket = newNode;
}

void insertSorted(struct Node **head, struct Node *newNode) {

  // If the list is empty or the new node is smaller than the head node, insert
  // at the front
  if (*head == NULL || (*head)->data > newNode->data) {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  // Find the position to insert the new node
  struct Node *curr = *head;
  while (curr->next != NULL && curr->next->data < newNode->data) {
    curr = curr->next;
  }
  // Current position for the data have been found So update the pointer
  newNode->next = curr->next;
  curr->next = newNode;
}

void insertionSort(struct Node **bucket) {

  struct Node *curr = *bucket;
  struct Node *sorted = NULL;
  struct Node *next = NULL;
  while (curr != NULL) {
    next = curr->next; // This is done here because we might lose next pointer
                       // while sorting
    insertSorted(&sorted, curr); // Insert the curr node in the sorted order
    curr = next;
  }

  // Now update the bucket pointer to point to the sorted list
  *bucket = sorted;
}

void bucketSort(int arr[], int size) {
  struct Node *Buckets[10];

  // Initialize buckets
  for (int i = 0; i < 10; i++) {
    Buckets[i] = NULL;
  }

  // Find maximum value in arr[]
  int maxVal = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }

  // Insert elements into appropriate buckets
  for (int i = 0; i < size; i++) {
    // Here 10 represent the numbers of buckets , this algorithm places the
    // number in appropriate place by normalizing
    int bucketNum = (int)(10.0 * arr[i] / (maxVal + 1));
    insertBucket(&Buckets[bucketNum], arr[i]);
  }

  // Sort each bucket and concatenate
  int indx = 0;
  for (int i = 0; i < 10; i++) {
    insertionSort(&Buckets[i]);
    struct Node *curr = Buckets[i];
    while (curr != NULL) {
      arr[indx++] = curr->data;
      curr = curr->next;
    }
  }
}

int main() {
  int n;
  printf("How many elements ? \n");
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the %d th element : ", i + 1);
    scanf("%d", &arr[i]);
  }

  bucketSort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

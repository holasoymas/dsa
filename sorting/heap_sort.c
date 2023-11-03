#include <stdio.h>

// NOTE: This is a sorting technique where elements are sorted by constructing a
// data structure called heap. There are 2 kind of heaps :
// 1. Max Heap  (where parent is grater than child(s) node)
// 2. Min Heap  (where parent is smaller than child(s) node)

//    ---      ---      ---     ---     ---
//   |40 |    |20 |    |25 |   |15 |   |19 |
//    ---      ---      ---     ---     ---

//// HACK:  Heap Representation       --
//                                   |40|
//                                    --
//                                  /    \
//                                 /      \
//                                /        \
//                               --           --
//                              |20|         |25|
//                            /  -- \         --
//                           /       \
//                          /         \
//                         /           \
//                        --            --
//                       |15|          |19|
//                        --            --
//
//                         Fig : Max Heap

// NOTE: Properties of heap
//
// To know the parent's index =  i / 2
//
// If index start at 1:
// To know the left child index = 2 * i
// To know right child index = (2 * i) + 1

// If index start at 0:
// To know the left child index = (2 * i)+1
// To know right child index = (2 * i) + 2

// If we have n nodes in heap then
//  To find the indexes of leaf node = [ (n / 2 ) + 1 ] to n

// If we have n nodes in heap then
// To find the last non-leaf node index = [(n / 2) - 1 (if index start at 0)]
//                                        [n / 2 (if index start at 1)]

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void maxHiplify(int arr[], int i, int size) {
  int largest = i;
  int left_child = (i * 2) + 1;
  int right_child = (i * 2) + 2;

  // If the left child is larger, update the largest index
  if (left_child < size && arr[left_child] > arr[largest])
    largest = left_child;

  // If the right child is larger, update the largest index
  if (right_child < size && arr[right_child] > arr[largest])
    largest = right_child;

  // If the alrgest index == i we will know that subtree satisfy the max heap
  // property so exit from the function
  // If the largest index is not the root, swap them and recurse on the subtree
  // cause while swapping the values the lowers sub trees doesn't necesserly
  // preserve the max heap property ;so by using recursion on sub trees we will
  // perserve the property of a max-heap
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    maxHiplify(arr, largest, size);
  }
}

void buildHeap(int arr[], int size) {
  int nonLeafNode = (size / 2) - 1;

  for (int i = nonLeafNode; i >= 0; i--) {
    maxHiplify(arr, i, size);
  }
}

void heapSort(int arr[], int size) {

  buildHeap(arr, size);

  for (int i = size - 1; i >= 0; i--) {
    // Heap has been build so replace the first value(largest) with the last
    // index value
    swap(&arr[0], &arr[i]);
    // After replacing call hiplify as the heap property has been disturved as
    // we are moving the last index value to the first So it is good to put that
    // value to appriopriate place to preserve the property of heap
    maxHiplify(arr, 0, i);
    // NOTE: We don't need to build heap every time we need to remove the item
    // as building heap one time is enough to preserve it's property and we can
    // just hiplify when we delete the first node and replace it with the last
    // index value and loop throught until appriopriate place come & put there.
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
  buildHeap(arr, n);
  printf("Building Heap : ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  heapSort(arr, n);
  printf("Sorting : ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

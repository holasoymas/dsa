#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree {
  int data;
  struct BinarySearchTree *left;
  struct BinarySearchTree *right;
} BST;

BST *createNode(int data) {
  BST *tmp = (BST *)malloc(sizeof(BST));
  tmp->data = data;
  tmp->right = NULL;
  tmp->left = NULL;
  return tmp;
}

// WARNING: As recursive program are timely and spacely expensive so use
// inserBST function instead of this
BST *insertBSTRec(BST **root, int data) {
  if (*root == NULL) {
    *root = createNode(data);
    return *root;
  } else if (data < (*root)->data) {
    (*root)->left = insertBSTRec(&(*root)->left, data);
  } else {
    (*root)->right = insertBSTRec(&(*root)->right, data);
  }
  return *root;
}

void insertBST(BST **root, int data) {
  BST *parent = NULL;
  BST *current = *root;

  // Finding the proper place to insert
  while (current != NULL) {
    parent = current;
    if (data < current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  BST *newNode = createNode(data);

  // Appropriate place has been found so , if parent == NULL ,
  // assign the root note the newly created node
  if (parent == NULL) {
    *root = newNode;
    return;
  }
  // else there are 2 places to insert that node if node's value is smaller than
  // the parent insert in the left side of the node , else you know where to put
  else if (data < parent->data) {
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }
}

int findMin(BST **root) {

  if ((*root) == NULL) {
    printf("Void finding, On a empty tree\n");
    return INT_MIN;
  }

  BST *current = *root;
  // By default on a BST the smallest item is on the left side of the tree
  while (current->left != NULL) {
    current = current->left;
  }
  return current->data;
}

int findMax(BST **root) {
  if (*root == NULL) {
    printf("Void finding, On a empty tree \n");
    return INT_MIN;
  }
  BST *current = *root;
  // By default on a BST the largest item is on the right side of the tree
  while (current->right != NULL) {
    current = current->right;
  }
  return current->data;
}

void inOrderTraverse(BST *root) {
  if (root != NULL) {
    inOrderTraverse(root->left);
    printf("%d ", root->data);
    inOrderTraverse(root->right);
  }
}

int main() {
  BST *root = NULL;
  insertBSTRec(&root, 40);
  insertBSTRec(&root, 15);
  insertBSTRec(&root, 45);
  insertBSTRec(&root, 55);
  insertBSTRec(&root, 25);
  inOrderTraverse(root);
  printf("\n");
  int min = findMin(&root);
  printf("Min is %d\n", min);

  int max = findMax(&root);
  printf("Max is %d\n", max);

  return 0;
}

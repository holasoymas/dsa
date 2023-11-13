#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// NOTE: AVL (Adelson-Velsky Landis) is a self-balancing binary search tree
// (BST). The key property of an AVL tree is that the difference between heights
// of left and right subtrees for any node cannot be more than one.If the
// difference (a.k.a balance factor) of any node in an AVL tree is not -1, 0, or
// +1, then the tree is unbalanced and needs to be balanced again by using
// rotation operations. There are 4 types of rotation to be performed in AVL
//
// 1. Left left case
//
// T1, T2, T3 and T4 are subtrees.
//         z                                      y
//        / \                                   /   \
//       y   T4      Right Rotate (z)          x      z
//      / \          - - - - - - - - ->      /  \    /  \
//     x   T3                               T1  T2  T3  T4
//    / \
//  T1   T2
//
//
//
// 2. Right right case
//
//         z                               y
//       /  \                            /   \
//      T1   y     Left Rotate(z)       z      x
//          /  \   - - - - - - - ->    / \    / \
//         T2   x                     T1  T2 T3  T4
//             / \
//           T3  T4
//
//
//
// 3. Left Right case
//
//         z                                  z
//        / \                               /   \
//       y   T4  First Left Rotate (T3)    T3   T4   Then again Right rotate(T3)
//      / \      - - - - - - - - - ->     /  \        - - - - - - - - - - - -
//     x   T3                            y   T2                             |
//        / \                           / \                                 |
//      T1   T2                        x  T1                                |
//                                                                          |
//                                                             T3       <---
//                                                           /    \
//                                                          y      z
//                                                         / \    /  \
//                                                        x  T1  T2  T4
//
//
//
// 4. Right Left case
//
//         z                                     z
//        / \                                  /   \
//       y   T4     First RIght Rotate(x)     y     x    Again Left rotate(x)
//          / \      - - - - - - - - - ->         /  \    - - - - - - - - -
//         x   T3                                T1  T4                   |
//        / \                                       /  \                  |
//      T1   T2                                    T2   T3                |
//                                                                        |
//                                                             x     <-----
//                                                           /   \
//                                                          z     T4
//                                                         / \   /  \
//                                                        y  T1  T2  T3
///
//

typedef struct AVL {
  int data;
  struct AVL *left, *right;
  int height;
} AVL;

int max(int a, int b) { return a > b ? a : b; }

AVL *createNode(int data) {
  AVL *node = (AVL *)malloc(sizeof(AVL));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->height = 1; // setting the leaf node as a height of 1
  return node;
}

// Recursively finding the height of the tree
int height(AVL *tree) {
  if (tree == NULL) {
    return 0;
  }
  return 1 + max(height(tree->left), height(tree->right));
}

int getHeight(AVL *tree) { // Range [-1,0,1]
  // If the height is out of this range we know that the tree is unbalanced
  if (tree == NULL)
    return 0;

  return height(tree->left) - height(tree->right);
}

AVL *rightRotate(AVL **root) {

  AVL *rootLeft = (*root)->left;
  AVL *rootLefts_Right = rootLeft->right;

  // Rotating part
  rootLeft->right = *root;
  (*root)->left = rootLefts_Right;

  // Update their height
  (*root)->height = max(height((*root)->left), height((*root)->right)) + 1;
  rootLeft->height = max(height(rootLeft->left), height(rootLeft->right)) + 1;

  return rootLeft;
}

AVL *leftRotate(AVL **root) {

  AVL *rootRight = (*root)->right;
  AVL *rootRights_Left = rootRight->left;

  // Rotating part
  rootRight->left = *root;
  (*root)->right = rootRights_Left;

  // Update their height
  (*root)->height = max(height((*root)->left), height((*root)->right)) + 1;
  rootRight->height =
      max(height(rootRight->left), height(rootRight->right)) + 1;

  return rootRight;
}

void insertAVL(AVL **root, int data) {

  AVL *parent = NULL;
  AVL *current = *root;

  AVL *newNode = createNode(data);

  if (*root == NULL) {
    *root = newNode;
    return;
  }

  // Finding the appriopriate place to insert
  while (current != NULL) {
    parent = current;
    if (data < current->data)
      current = current->left;
    else
      current = current->right;
  }

  // appriopriate place has been found so if it is smaller than father put in
  // left if bigger put in right
  if (parent->data < data)
    parent->right = newNode;
  else
    parent->left = newNode;

  int isBalanced = getHeight(*root);

  // Left-left case
  if (isBalanced > 1 && data < (*root)->left->data) {
    *root = rightRotate(root);
    return;
  }

  // Right-right case
  if (isBalanced < -1 && data > (*root)->right->data) {
    *root = leftRotate(root);
    return;
  }

  // Left-Right case

  if (isBalanced > 1 && data > (*root)->left->data) {
    AVL *leftTree = (*root)->left;
    (*root)->left = leftRotate(&leftTree);
    *root = rightRotate(root);
    return;
  }

  // Right-Left case
  if (isBalanced < -1 && data < (*root)->right->data) {
    AVL *rightTree = (*root)->right;
    (*root)->right = rightRotate(&rightTree);
    *root = leftRotate(root);
    return;
  }
}

void inOrderTraversal(AVL *root) {
  if (root != NULL) {
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
  }
}

int main() {

  AVL *root = NULL;
  insertAVL(&root, 12);
  insertAVL(&root, 2);
  insertAVL(&root, 1);
  insertAVL(&root, 1);
  insertAVL(&root, 25);
  insertAVL(&root, 3);

  inOrderTraversal(root);
  printf("\n");

  return 0;
}

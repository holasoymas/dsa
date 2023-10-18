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

BST *findBST(BST **root, int data) {
  if (*root == NULL) {
    printf("Void finding : Empty tree or No node found of data %d \n", data);
    return NULL;
  }
  if ((*root)->data == data) {
    return *root;
  } else if (data < (*root)->data) {
    return findBST(&(*root)->left, data);
  }

  return findBST(&(*root)->right, data);
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

// HACK: Deleting a node from a BST is somewhat tricky
// There are three cases we have to keep in mind
// 1. when node has no childern , you just make its parent point to null,
// 2. when node has one childern, make the parent of the deleted node point
// to its grand-childeren(node pointed by the to be deleted node ) the one
// and only grand children cause there is only one node pointed by that to be
// deleted node
// 3. when the node has 2 children, This is somehow more tricky,
// But we can do it in a two way
// 3.a. - Either find the maximum element in the left sub-tree
// 3.b. - Or find the minimum element in the right sub-tree
//
// By doing this you preserve the property of the BST, Now if you find this
// just replace that item (min. item in right sub-tree or max in left sub tree)
// with to be deleted note. And remove from its original place and U R done !

// HACK:                               --
//                                    |40|
//                                     --
//                                  /    \
//                                 /      \
//                                /        \
//                               --           --
//                              |20|         |55|
//                            /  -- \         --
//                           /       \
//                          /         \
//                         /           \
//                       --            --
//                       |15|          |25|
//                        --            --
//                    /     \         /    \
//                   /       \       /      \
//                  --       --     --      --
//                  |10|     |18|   |23|    |30|
//                   --       --     --      --
//
// Here , If we want to delete 20, we have 2 method to do it.
// Lets follow the 3.b. method (Finding the minimum element in right sub tree)
// Here the minimum element in the right sub-tree (asuming 20 as a root) is 23.
// Replace 20 with 23 and remove the 23 from the tree, and you are good to go.

// After that our tree will look like this :

// HACK:                               --
//                                    |40|
//                                     --
//                                  /    \
//                                 /      \
//                                /        \
//                               --           --
//                              |23|         |55|
//                            /  -- \         --
//                           /       \
//                          /         \
//                         /           \
//                       --            --
//                       |15|          |25|
//                        --            --
//                    /     \              \
//                   /       \              \
//                  --       --             --
//                  |10|     |18|          |30|
//                   --       --            --

void deleteBST(BST **root, int data) {
  if (*root == NULL) {
    printf("Void deletion : root is empty\n");
    return;
  }

  BST *parent = NULL;
  BST *node = *root;
  while (node != NULL && node->data != data) {
    parent = node;
    if (data < node->data)
      node = node->left;
    else
      node = node->right;
  }

  // Here in the loop we already found the node to be deleted and its parent

  // If data is not found, node will give the NULL as a value
  if (node == NULL) {
    printf("Void deletion : %d not found in the tree\n", data);
    return;
  }

  // Case 1: When the node is leaf node i.e node which has no children at all
  if (node->left == NULL && node->right == NULL) {
    // If that is a root node, make the tree empty
    if (node == *root) {
      *root = NULL;
    } else {
      // if the parent's left node is the node to be deleted make it detached by
      // setting it to NULL else make the right child NULL
      if (parent->left == node)
        parent->left = NULL;
      else
        parent->right = NULL;
    }
    // Free the detached node
    free(node);
  }

  // Case 2: When the node has one children
  else if (node->right == NULL || node->left == NULL) {
    // Either in the left or right there is one child so find which one is it
    BST *child = node->left != NULL ? node->left : node->right;
    if (node == *root) {
      // If the root node is the node make the one and only child the root node
      *root = child;
    } else {
      // If the parent's left node is the node to be deleted connect the parent
      // to the child of the node disconnecting the node element, if the right
      // child is the node to be deleted do the same thing to the right child
      if (parent->left == node)
        parent->left = child;
      else
        parent->right = child;
    }
    free(node);
  }

  // Case 3 : when the node has 2 children
  else {

    // Find the inorder successor of the node and its parent
    BST *succ_parent = node;
    BST *succ = node->right;
    // Finding the smallest node in right sub-tree
    while (succ->left != NULL) {
      succ_parent = succ;
      succ = succ->left;
    }
    // Copy the data of the successor to the node
    node->data = succ->data;
    // To understand this part of a code make a tree with data
    // 40,20,15,25,10,18,23,30,55,50,60,45,52,57,65
    // Delete first 20 and then try to delete 23 you will understand
    // That elxplanation is beyond my imagination So just take a copy and pen
    // and visualize it
    if (succ_parent->left == succ)
      succ_parent->left = succ->right;
    else
      succ_parent->right = succ->right;

    free(succ);
  }
}

void inOrderTraverse(BST *root) {
  if (root != NULL) {
    inOrderTraverse(root->left);
    printf("%d ", root->data);
    inOrderTraverse(root->right);
  }
}

void freeBST(BST **root) {}

int main() {
  BST *root = NULL;
  insertBSTRec(&root, 40);
  insertBSTRec(&root, 20);
  insertBSTRec(&root, 55);
  insertBSTRec(&root, 15);
  insertBSTRec(&root, 25);
  insertBSTRec(&root, 50);
  insertBSTRec(&root, 60);
  insertBSTRec(&root, 10);
  insertBSTRec(&root, 18);
  insertBSTRec(&root, 23);
  insertBSTRec(&root, 30);
  insertBSTRec(&root, 45);
  insertBSTRec(&root, 52);
  insertBST(&root, 57);
  insertBST(&root, 65);
  inOrderTraverse(root);
  printf("\n");
  int min = findMin(&root);
  printf("Min is %d\n", min);

  int max = findMax(&root);
  printf("Max is %d\n", max);

  BST *findElmnt = findBST(&root, 35);
  if (findElmnt != NULL) {
    printf("Data = %d\n", findElmnt->data);
    printf("Left Data = %d\n", findElmnt->left->data);
    printf("Right Data = %d\n", findElmnt->right->data);
  }

  deleteBST(&root, 20);
  deleteBST(&root, 23);
  printf("After deletion : \n");
  inOrderTraverse(root);
  printf("\n");

  return 0;
}

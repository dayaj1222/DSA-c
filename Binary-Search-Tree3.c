#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int dat;
  struct Node *left;
  struct Node *right;
} Node;

Node *
Insert(Node *root,
       int v) { // Primise to return the passed node with new value attached

  if (root == NULL) {
    Node *newnode = malloc(sizeof(Node));
    newnode->dat = v;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
  }

  if (v > root->dat) {
    root->right = Insert(root->right, v);
  } else {
    root->left = Insert(root->left, v);
  }

  return root;
}

int count = 0;

// promise to return the node with the kth max elemnt.
Node *Max(Node *root, int k) {

  // given node is Null meaning no kth eelemetn in this branch.
  if (root == NULL) {
    return NULL;
  }

  Node *right = Max(root->right, k); // try to find it on right subtree
  if (right != NULL) {
    return right; // if right returns node thats the answer just pass it up.
  }

  count++;
  // Check if i am the required node
  if (count == k) {
    return root;
  }

  // if not then only left is remaining so return whatever left subtree returns
  return Max(root->left, k);
}

Node *Min(Node *root, int k) {

  // given node is Null meaning no kth eelemetn in this branch.
  if (root == NULL) {
    return NULL;
  }

  Node *left = Min(root->left, k); // try to find it on right subtree
  if (left != NULL) {
    return left; // if right returns node thats the answer just pass it up.
  }

  count++;
  // Check if i am the required node
  if (count == k) {
    return root;
  }

  // if not then only left is remaining so return whatever left subtree returns
  return Min(root->right, k);
}

void Print(Node *root) {

  if (root == NULL) {
    return;
  }

  Print(root->left);
  printf("%d ", root->dat);
  Print(root->right);
}

int main() {

  Node *root = NULL;

  root = Insert(root, 5);
  root = Insert(root, 6);
  root = Insert(root, 20);
  root = Insert(root, 2);

  Print(root);

  printf("\n2nd max: %d", Max(root, 2)->dat);
  count = 0;
  printf("\n2nd min: %d", Min(root, 2)->dat);
}

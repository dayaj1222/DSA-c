// Binary search tree

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

int add(int value, Node *root);
int print_dfs(Node *root);
int print_bfs(Node *root);
int free_sub_tree(Node *node);

int main() {
  Node *root = malloc(sizeof(Node));

  if (root == NULL) {
  }

  root->left = NULL;
  root->right = NULL;
  root->value = 2;

  add(3, root);
  add(1, root);
  add(10, root);

  print_dfs(root);

  free_sub_tree(root);
  return EXIT_SUCCESS;
}

int add(int value, Node *root) {

  Node *to_add = malloc(sizeof(Node));
  if (to_add == NULL) {
  }
  to_add->value = value;

  to_add->left = NULL;
  to_add->right = NULL;

  if (root == NULL) {
    root = to_add;
    return 0;
  };

  if (root->left == NULL && value < root->value) {
    root->left = to_add;
    return 0;
  };
  if (root->right == NULL && value > root->value) {
    root->right = to_add;
    return 0;
  }

  if (value > root->value) {
    add(value, root->right);
    return 0;
  }

  if (value < root->value) {
    add(value, root->left);
    return 0;
  }

  if (value == root->value) {
    free(to_add);
  }

  return 0;
};

int free_sub_tree(Node *node) {
  if (node == NULL) {
    return 0;
  }

  free_sub_tree(node->right);
  free_sub_tree(node->left);
  free(node);
  return 0;
};

int print_dfs(Node *root) {
  if (root == NULL) {
    return 0;
  }
  print_dfs(root->left);
  printf("%d, ", root->value);
  print_dfs(root->right);
  return 0;
}
// TODO
int print_bfs(Node *root) { return 0; };

#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
} Node;

Node *create_node(int val) {
  Node *node = malloc(sizeof(Node));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node *Insert(Node *root, int val) {
  if (root == NULL) {
    return create_node(val);
  }

  if (root->val > val) {
    root->left = Insert(root->left, val);
  }
  if (root->val < val) {
    root->right = Insert(root->right, val);
  }

  return root;
}

// Pass node->right to find the successor
Node *find_succesor(Node *node) {
  if (node->left == NULL) {
    return node;
  }

  return find_succesor(node->left);
}

Node *Delete(Node *root, int val) {
  if (root == NULL)
    return NULL;

  if (val < root->val) {
    root->left = Delete(root->left, val);
  } else if (val > root->val) {
    root->right = Delete(root->right, val);
  } else {
    if (root->left == NULL) {
      Node *tmp = root->right;
      free(root);
      return tmp;
    } else if (root->left == NULL) {
      Node *tmp = root->left;
      free(root);
      return tmp;
    } else {
      Node *node = find_succesor(root->right);
      root->val = node->val;
      root->right = Delete(root->right, node->val);
    }
  }

  return root;
}

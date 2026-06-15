#include <climits>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iso646.h>
#include <string>

using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
};

class Tree {

  Tree(int rootVal) {
    Node *node = new Node;
    node->left = nullptr;
    node->right = nullptr;
    node->val = rootVal;

    this->root = node;
  };

private:
  void inorder(Node *node) {
    if (node == NULL) {
      return;
    }

    inorder(node->left);
    cout << node->val << endl;
    inorder(node->right);
  }
  void preorder(Node *node) {
    if (node == NULL) {
      return;
    }

    cout << node->val << endl;
    inorder(node->left);
    inorder(node->right);
  }
  void postorder(Node *node) {
    if (node == NULL) {
      return;
    }

    inorder(node->left);
    inorder(node->right);
    cout << node->val << endl;
  }

  void release(Node *node) {
    if (node == nullptr) {
      return;
    }
    release(node->left);
    release(node->right);

    delete node;
  }

  int findMax(Node *node, int k) {

    if (node == nullptr) {
      return INT_MIN;
    }

    int leftMax = findMax(node->left, k);
    int rightMax = findMax(node->right, k);

    int max = node->val;
    if (leftMax > max) {
      max = leftMax;
    }

    if (rightMax > max) {
      max = rightMax;
    }

    return max;
  }

public:
  Node *root;

  void Print(string order) {
    (order == "inorder")    ? inorder(this->root)
    : (order == "preorder") ? preorder(this->root)
                            : postorder(this->root);
  };

  int Max(int k) {

    cout << "Max " << k << "th element in the tree is" << findMax(this->root, k)
         << endl;
  }

  ~Tree() {
    release(this->root);
    root = nullptr;
  }
};

#include <stdio.h>

int counter = 0; // Tracks how many elements we have processed

struct Node *findKthLargest(struct Node *root, int k) {
  if (root == NULL) {
    return NULL;
  }

  // 1. Search the right subtree (larger elements)
  struct Node *right = findKthLargest(root->right, k);
  if (right != NULL) {
    return right; // If found in right subtree, pass it up
  }

  // 2. Process current node
  counter++;
  if (counter == k) {
    return root; // Found the kth largest node
  }

  // 3. Search the left subtree (smaller elements)
  return findKthLargest(root->left, k);
}

Node *findMin(Node *node, int k) {
  if (node == NULL) {
    return NULL;
  }

  Node *left = findMin(node->left, k);
  if (left != NULL) {
    return left;
  }

  counter++;
  if (counter == k) {
    return node;
  }

  return findMin(node->right, k);
}

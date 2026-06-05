#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int passengers;
  struct Node *next;
} Node;

void Insert(Node *root, int pos, int passengers) {

  Node *newnode = malloc(sizeof(Node));
  newnode->passengers = passengers;
  newnode->next = NULL;

  Node *current = root;

  for (int i = 0; i < pos - 1; i++) {
    current = current->next;
  }
  if (current->next == NULL) {
    current->next = newnode;
    return;
  }

  newnode->next = current->next;
  current->next = newnode;
}

void Print(Node *node) {
  Node *current = node;
  while (current != NULL) {
    printf("%d ", current->passengers);
    current = current->next;
  }
}

int main() {

  Node *root = malloc(sizeof(Node));
  root->next = NULL;
  root->passengers = 0;

  int n, p;
  printf("\nEnter the number of coaches in the train: ");
  scanf("%d", &n);

  printf("Enter the number of passenger in each coach: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &p);
    Insert(root, i + 1, p);
  }

  printf("Coaches before: ");
  Print(root->next);

  printf(
      "\nEnter the coach to be inserted in the train with passenger count: ");
  scanf("%d", &p);
  Insert(root, 3, p);

  printf("\nCoaches after the insert: ");
  Print(root->next);

  Insert(root, 3, p);
}

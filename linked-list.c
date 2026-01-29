// Singly linked list with insertion at any index.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node *head;
  int count;
} LinkedList;

bool add(int index, int value, LinkedList *list) {

  if (index > list->count) {
    printf("index out of bounds // add");
    return 0;
  };

  if (list->head == NULL) {
    Node *to_add = malloc(sizeof(Node));
    to_add->value = value;
    to_add->next = NULL;
    list->head = to_add;
    list->count++;
    return true;
  }

  if (index == list->count) {
    Node *required = list->head;

    for (int i = 1; i < index; i++) {
      required = required->next;
    }

    Node *to_add = malloc(sizeof(Node));
    to_add->value = value;
    to_add->next = NULL;
    required->next = to_add;
    list->count++;
    return true;
  }

  if (index == 0) {
    Node *required = list->head;
    Node *to_add = malloc(sizeof(Node));
    to_add->value = value;
    to_add->next = required;
    list->head = to_add;
    list->count++;
    return true;
  }

  Node *required = list->head;
  for (int i = 1; i < index; i++) {
    required = required->next;
  }
  Node *required_next = required->next;
  Node *to_add = malloc(sizeof(Node));
  to_add->value = value;
  to_add->next = required_next;
  required->next = to_add;
  list->count++;
  return true;
}

bool print(LinkedList *list) {
  Node *required = list->head;
  while (required != NULL) {
    printf("[%d]->", required->value);
    required = required->next;
  }
  printf("NULL\n");
  return true;
}

bool free_list(LinkedList *list) {
  Node *curr = list->head;
  while (curr != NULL) {
    Node *tmp = curr;
    curr = curr->next;
    free(tmp);
  }
  list->head = NULL;
  list->count = 0;
  return true;
}

int main() {
  LinkedList mylist = {NULL, 0};

  add(0, 1, &mylist);
  print(&mylist);
  return 0;
}

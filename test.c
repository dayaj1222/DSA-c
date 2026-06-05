#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int v;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct List {
  Node *head;
  Node *tail;
  int len;
} List;

List *New(int val) {

  List *newList = malloc(sizeof(List));
  Node *head = malloc(sizeof(Node));
  head->v = val;
  head->next = NULL;
  head->prev = NULL;

  newList->head = head;
  newList->tail = head;
  newList->len = 1;

  return newList;
}

void Push(List *list, int val) {
  Node *newNode = malloc(sizeof(Node));
  newNode->v = val;
  newNode->next = NULL;
  newNode->prev = list->tail;

  if (list->tail) {
    list->tail->next = newNode;
  } else {
    list->head = newNode;
  }
  list->tail = newNode;
  list->len++;
}

void rm(Node *node) {
  if (node->prev != NULL) {
    node->prev->next = node->next;
  }
  if (node->next != NULL) {
    node->next->prev = node->prev;
  }
  free(node);
}

void Remove(List *list, int v) {
  if (list->len == 0) {
    printf("Not Found\n");
    return;
  }
  Node *current = list->head;
  while (current != NULL) {
    if (current->v == v) {
      if (current == list->head) {
        if (current->next != NULL) {
          list->head = current->next;
        } else {
          list->head = NULL;
          list->tail = NULL;
        }
        rm(current);
        printf("Remove Successful\n");
        return;
      } else if (current == list->tail) {
        if (current->prev != NULL) {
          list->tail = current->prev;
        } else {
          list->tail = NULL;
          list->head = NULL;
        }
        rm(current);
        printf("Remove Successful\n");
        return;
      } else {
        rm(current);
        printf("Remove Successful\n");
        return;
      }
    }
    current = current->next;
  }
  printf("Not Found\n");
}

void Print(List *list) {
  Node *current = list->head;
  while (current != NULL) {
    if (current == list->tail) {
      printf("%d", current->v);
      return;
    }
    printf("%d->", current->v);
    current = current->next;
  }
}

int main() {
  List *mylist = New(3);
  Push(mylist, 40);
  Push(mylist, 41);
  Push(mylist, 42);
  Push(mylist, 43);
  Push(mylist, 44);
  Push(mylist, 45);
  Push(mylist, 46);

  Remove(mylist, 42);

  Print(mylist);
}

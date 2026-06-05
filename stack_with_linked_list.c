#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory Allocation Failed\n");
    return;
  }
  newNode->data = value;
  newNode->next = top;
  top = newNode;
  printf("%d pushed onto stack\n", value);
}

void pop() {
  if (top == NULL) {
    printf("Stack Underflow\n");
    return;
  }
  struct Node *temp = top;
  top = top->next;
  printf("%d popped from stack\n", temp->data);
  free(temp);
}

void peek() {
  if (top == NULL) {
    printf("Stack is empty\n");
    return;
  }
  printf("Top element is %d\n", top->data);
}

void display() {
  if (top == NULL) {
    printf("Stack is empty\n");
    return;
  }
  struct Node *temp = top;
  printf("Stack elements: ");
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}
int main() {
  int choice, value, n;

  printf("Enter the number of elements to be inserted:\n");
  scanf("%d", &n);

  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &value);
    push(value);
  }

  do {
    printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
    printf("\nEnter your choice:");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the element to be pushed:\n");
      scanf("%d", &value);
      push(value);
      break;
    case 2:
      pop();
      break;
    case 3:
      peek();
      break;
    case 4:
      display();
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice! Please enter a number between 1 and 5.\n");
    }
  } while (choice != 5);

  return 0;
}

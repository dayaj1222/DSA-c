// Stack Implementation

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int capacity;
  int top;
  int *elements;
  bool (*push)(int, struct Stack *);
  bool (*pop)(struct Stack *);
  bool (*print)(struct Stack *);
} Stack;

bool push(int, Stack *stack);
bool pop(Stack *stack);
bool print(Stack *stack);

int main(int argc, char *argv[]) {

  Stack mystack = {};
  mystack.top = -1;
  mystack.capacity = 20;
  int elements[mystack.capacity];
  mystack.elements = elements;
  mystack.print = print;
  mystack.push = push;
  mystack.pop = pop;

  mystack.push(2, &mystack);
  mystack.push(4, &mystack);
  mystack.push(5, &mystack);
  mystack.push(6, &mystack);
  mystack.push(0, &mystack);

  mystack.pop(&mystack);

  mystack.print(&mystack);
  return EXIT_SUCCESS;
}

bool push(int num, Stack *stack) {

  if (stack->top + 1 >= stack->capacity)
    return true;

  stack->top += 1;
  (stack->elements)[stack->top] = num;
  return false;
}

bool pop(Stack *stack) {
  if (stack->top - 1 < 0)
    return true;
  stack->top -= 1;
  return false;
}

bool print(Stack *stack) {

  if (stack->top < 0) {
    return true;
  }

  printf("[");
  for (int i = 0; i <= stack->top; i++) {
    printf("%d", stack->elements[i]);
    if (i < stack->top)
      printf(",");
  };

  printf("]\n");
  return false;
}

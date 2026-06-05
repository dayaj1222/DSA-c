#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

typedef struct Result {
  bool error;
  int val;
} Result;

typedef struct Stack {
  int *arr;
  int top;
} Stack;

Result Pop(Stack *stack);
Result Push(Stack *stack, int val);
Result isEmpty(Stack *stack);
Result Peek(Stack *stack);
void Print(Stack *stack);

int main() {

  // Initialization
  int *arr = malloc(sizeof(int) * 100);
  Stack *mystack = malloc(sizeof(Stack));
  mystack->arr = arr;
  mystack->top = -1;

  for (int i = 2; i < 100; i += 2) {
    Push(mystack, i);
  }

  printf("Elements Added\n");
  Print(mystack);

  printf("\n\n Popped 20 times.");

  for (int i = 0; i < 20; i++) {
    Pop(mystack);
  }
  Print(mystack);

  free(mystack->arr);
  free(mystack);
}

Result Push(Stack *stack, int val) {
  Result result = {false, val};
  if (stack->top == CAPACITY - 1) {
    result.error = true;
    return result;
  }

  stack->top++;
  stack->arr[stack->top] = val;
  return result;
}

Result Pop(Stack *stack) {
  Result result = {false, 0};
  if (isEmpty(stack).val) {
    result.error = true;
    return result;
  }
  result.val = stack->arr[stack->top];
  stack->top--;
  return result;
}

Result isEmpty(Stack *stack) {
  Result result = {false, false};
  if (stack->top == -1) {
    result.val = true;
    return result;
  }
  return result;
}

Result Peek(Stack *stack) {

  Result result = {false, stack->arr[stack->top]};
  if (isEmpty(stack).val) {
    result.error = 1;
    return result;
  }
  return result;
}

void Print(Stack *stack) {
  printf("[");
  for (int i = 0; i <= stack->top; i++) {
    if (i == stack->top)
      printf("%d", stack->arr[i]);
    else
      printf("%d, ", stack->arr[i]);
  }
  printf("]\n");
}

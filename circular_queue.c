#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 60

typedef struct Queue {
  int *arr;
  int front;
  int rear;
} Queue;

int Enque(Queue *q, int val);
int Deque(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
int Peek(Queue *q);
void Print(Queue *q);

int main() {
  int *arr = malloc(sizeof(int) * CAPACITY);

  Queue *q = malloc(sizeof(Queue));
  q->arr = arr;
  q->front = -1;
  q->rear = -1;

  printf("================Enque Test(50)====================\n\n");
  for (int i = 0; i < 100; i += 2) {
    (Enque(q, i));
  }

  Print(q);

  printf("==================Deque test(40)======================\n\n");
  for (int i = 0; i < 40; i++) {
    Deque(q);
  }

  Print(q);

  free(arr);
  free(q);
}

int isEmpty(Queue *q) {
  if (q->front == -1) {
    return 1;
  }
  return 0;
}

int isFull(Queue *q) {
  if ((q->rear + 1) % CAPACITY == q->front) {
    return 1;
  }
  return 0;
}

int Enque(Queue *q, int val) {
  if (isFull(q)) {
    return 0;
  }
  if (isEmpty(q)) {
    q->front = q->rear = 0;
    return 1;
  } else {

    q->rear = (q->rear + 1) % CAPACITY;
  }
  q->arr[q->rear] = val;
  return 1;
}

int Deque(Queue *q) {
  if (isEmpty(q)) {
    return 0;
  }
  q->front = q->front % CAPACITY;
  return 1;
}

int Peek(Queue *q) {
  if (isEmpty(q)) {
    return -99;
  }

  return q->arr[q->front];
}

void Print(Queue *q) {
  // if (isEmpty(q)) {
  //   printf("[]");
  //   return;
  // }
  printf("[");
  for (int i = 0; i < CAPACITY; i++) {
    if (i < q->front) {
      printf(",");
    }
    if (i >= q->front && i < q->rear) {
      printf("%d, ", q->arr[i]);
    }
    if (i >= q->rear) {
      printf(",");
    }
  }
  printf("]\n\n");
}

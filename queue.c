// Circular Queue Implementation

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {

  int *elements;
  int start;
  int current;
  int end;
  int count;

  bool (*enqueue)(int, struct Queue *);
  bool (*dequeue)(struct Queue *);
  void (*print)(struct Queue *);
} Queue;

bool enqueue(int num, Queue *queue);
bool dequeue(Queue *queue);
void print(Queue *queue);

int main() {

  Queue myqueue = {};

  myqueue.end = 20;
  int elements[myqueue.end];
  myqueue.elements = elements;
  myqueue.start = 0;
  myqueue.current = -1;
  myqueue.print = print;
  myqueue.enqueue = enqueue;
  myqueue.dequeue = dequeue;
  myqueue.count = 0;

  myqueue.enqueue(1, &myqueue);
  myqueue.enqueue(2, &myqueue);
  myqueue.enqueue(3, &myqueue);

  myqueue.dequeue(&myqueue);

  myqueue.print(&myqueue);

  return EXIT_SUCCESS;
}

bool enqueue(int num, Queue *queue) {

  if (queue->count >= queue->end) {
    return false;
  }
  queue->elements[(queue->current + 1) % queue->end] = num;
  queue->count++;
  queue->current = (queue->current + 1) % queue->end;
  return true;
};

bool dequeue(Queue *queue) {

  if (queue->count < 0) {
    return false;
  }
  queue->start = (queue->start + 1) % queue->end;
  queue->count -= 1;
  return true;
};

void print(Queue *queue) {
  int i = queue->start;
  printf("[");
  for (int c = 0; c < queue->count; c++) {
    printf("%d", queue->elements[i]);

    if (c + 1 < queue->count) {
      printf(",");
    }
    i = (i + 1) % queue->end;
  }
  printf("]");
}

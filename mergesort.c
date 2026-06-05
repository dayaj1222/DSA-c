#include <stdio.h>

void merge(int *A, int *b, int l, int m, int h) {
  int i = l;
  int j = m + 1;
  int k = l;

  while (i <= m && j <= h) {
    if (A[i] < A[j]) {
      b[k] = A[i];
      i++;
    } else {
      b[k] = A[j];
      j++;
    }
    k++;
  }

  for (; i <= m; i++) {
    b[k] = A[i];
    k++;
  }
  for (; j <= h; j++) {
    b[k] = A[j];
    k++;
  }

  for (int t = l; t <= h; t++) {
    A[t] = b[t];
  }
}

void mergesort(int *arr, int *buf, int l, int h) {
  if (l >= h) {
    return;
  }

  int mid = (l + h) / 2;

  mergesort(arr, buf, l, mid);
  mergesort(arr, buf, mid + 1, h);
  merge(arr, buf, l, mid, h);
}

int main() {
  int data[] = {38, 27, 43, 3, 9, 82, 10, -5, 0, 27};
  int n = sizeof(data) / sizeof(data[0]);
  int buf[10];

  printf("Original array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");

  mergesort(data, buf, 0, n - 1);

  printf("Sorted array:   ");
  for (int i = 0; i < n; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");

  return 0;
}

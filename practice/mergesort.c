#include <stdio.h>

void merge(int *a, int *b, int l, int m, int h) {
  int i = l;
  int j = m + 1;
  int k = l;
  while (i <= m && j <= h) {
    if (a[i] < a[j]) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      j++;
    }
    k++;
  }

  for (; i <= m; i++) {
    b[k] = a[i];
    k++;
  }

  for (; j <= h; j++) {
    b[k] = a[j];
    k++;
  }

  for (int i = l; i < k; i++) {
    a[i] = b[i];
  }
}

void mergesort(int *a, int *b, int l, int h) {
  if (l == h) {
    return;
  }

  int mid = (l + h) / 2;

  mergesort(a, b, l, mid);
  mergesort(a, b, mid + 1, h);
  merge(a, b, l, mid, h);
}

int main() {

  int arr[6] = {4, 5, 1, 2, 7, 8};

  int h = sizeof(arr) / sizeof(arr[0]);
  int buffer[h];
  mergesort(arr, buffer, 0, h - 1);

  for (int i = 0; i < h; i++) {
    printf("%d ", arr[i]);
  }
}

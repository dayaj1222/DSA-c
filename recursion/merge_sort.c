#include <stdio.h>

void merge(int *arr, int *buf, int low, int mid, int high) {
  int i = low;
  int j = mid + 1;
  int k = low;

  // Merge the array in ascending order
  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) {
      buf[k] = arr[i];
      i++;
      k++;
    } else if (arr[j] < arr[i]) {
      buf[k] = arr[j];
      j++;
      k++;
    }
  }

  // Copy the remaining elements from two arrays
  for (; i <= mid; i++) {
    buf[k] = arr[i];
    k++;
  }
  for (; j <= high; j++) {
    buf[k] = arr[j];
    k++;
  }

  // Copy to read array from temporary.
  for (int i = low; i <= high; i++) {
    arr[i] = buf[i];
  }
  return;
}

void mergesort(int *arr, int *buf, int l, int h) {
  if (l >= h) {
    return;
  }
  int m = (l + h) / 2;

  mergesort(arr, buf, l, m);
  mergesort(arr, buf, m + 1, h);
  merge(arr, buf, l, m, h);
}

int main() {
  int arr[6] = {4, 3, 2, 5, 6, 7};
  int buf[6];
  mergesort(arr, buf, 0, 5);

  for (int i = 0; i < 6; i++) {
    printf("%d ", arr[i]);
  }
}

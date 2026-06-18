#include <stdio.h>

int partition(int *arr, int l, int h) {
  int pivot = arr[l];
  int i = l + 1;
  int j = h;

  while (i <= j) {
    while (i <= h && arr[i] < pivot)
      i++;
    while (j > l && arr[j] > pivot)
      j--;

    // swap ij only if i<j
    if (i < j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  // swwap pivto and j
  arr[l] = arr[j];
  arr[j] = pivot;

  return j;
}

void quicksort(int *arr, int l, int h) {
  if (l >= h) {
    return;
  }

  int mid = partition(arr, l, h);

  quicksort(arr, l, mid - 1);
  quicksort(arr, mid + 1, h);
}

int main() {

  int arr[] = {4, 5, 1, 2, 7, 8};

  int h = sizeof(arr) / sizeof(arr[0]);
  quicksort(arr, 0, h - 1);

  for (int i = 0; i < h; i++) {
    printf("%d ", arr[i]);
  }
}

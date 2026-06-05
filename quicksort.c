#include <stdio.h>

int partition(int *arr, int l, int h) {

  int pivot = arr[l];
  int i = l + 1;
  int j = h;

  while (i <= j) {

    while (arr[i] < pivot && i <= h) {
      i++;
    }

    while (arr[j] >= pivot && j > l) {
      j--;
    }
    if (i < j) {
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
    }
  }

  int tmp = arr[l];
  arr[l] = arr[j];
  arr[j] = tmp;

  return j;
}

void quicksort(int *arr, int l, int h) {
  if (l >= h)
    return;

  int mid = partition(arr, l, h);
  quicksort(arr, l, mid - 1);
  quicksort(arr, mid + 1, h);
}

int main() {
  int data[] = {38, 27, 43, 3, 9, 82, 10, -5, 0, 27};
  int n = sizeof(data) / sizeof(data[0]);

  printf("Original array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");

  quicksort(data, 0, n - 1);

  printf("Sorted array:   ");
  for (int i = 0; i < n; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");

  return 0;
}

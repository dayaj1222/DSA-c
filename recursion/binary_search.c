#include <stdio.h>

int bin_search(int *arr, int low, int high, int target) {

  if (low > high) {
    return -1;
  }

  int m = (low + high) / 2;

  if (arr[m] == target) {
    return m;
  }

  int left = bin_search(arr, low, m - 1, target);
  if (left != -1) {
    return left;
  }

  return bin_search(arr, m + 1, high, target);
}

int main() {
  int arr[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  printf("%d", bin_search(arr, 0, 5, 5));
}

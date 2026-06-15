#include <stdio.h>

void sort(int *arr) {
  for (int i = 1; i < 8; i++) {
    int tmp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > tmp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = tmp;
  }
}

int main(int argc, char *argv[]) {
  int arr[] = {2, 3, 1, 4, 9, 5, 6, 8};

  sort(arr);

  for (int i = 0; i < 8; i++) {
    printf("%d ", arr[i]);
  }
}

#include <stdio.h>
#define N 5

int sol[N];
int k = 0;

int isValid(int cur_sum, int req_sum, int e) {
  return (e + cur_sum <= req_sum) ? 1 : 0;
}

void Display() {
  printf("\n");
  for (int i = 0; i < k; i++) {
    printf("%d ", sol[i]);
  }
}

void sos(int *arr, int cur_idx, int cur_sum, int req_sum) {
  if (cur_sum == req_sum) {
    Display();
    return;
  }

  for (int i = cur_idx; i < N; i++) {
    if (!isValid(cur_sum, req_sum, arr[i])) {
      continue;
    }

    sol[k++] = arr[i];
    cur_sum += arr[i];

    sos(arr, i + 1, cur_sum, req_sum);

    k--;
    cur_sum -= arr[i];
  }
}

int main() {
  int arr[N] = {2, 3, 4, 1, 5};
  sos(arr, 0, 0, 7);
}

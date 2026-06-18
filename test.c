#include <stdio.h>
#define N 4

int sol[N];
int k = 0;

int is_valid(int element, int current_sum, int required_sum) {
  return current_sum + element < required_sum;
}

void Display() {
  for (int i = 0; i < k; i++)
    printf("%d ", sol[i]);
  printf("\n");
}

void sum_of_subsets(int *set, int current_idx, int current_sum,
                    int required_sum) {

  if (current_sum == required_sum) {
    Display();
    return;
  }

  for (int i = current_idx; i < N; i++) {
    if (!is_valid(set[i], current_sum, required_sum)) {
      continue;
    }
    sol[k++] = set[i];
    current_sum += set[i];

    sum_of_subsets(set, i + 1, current_sum, required_sum);

    k--;
    current_sum -= set[i];
  }
}

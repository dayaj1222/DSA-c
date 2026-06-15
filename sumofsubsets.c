#include <stdio.h>
#define N 6

int sol[N];
int k = 0;

int is_valid(int required_sum, int current, int element) {

  // Invalid if the element makes the sum more than required.
  if (current + element > required_sum) {
    return 0;
  }

  return 1;
}

void solve(int *subset, int c_idx, int required_sum, int current) {
  if (current == required_sum) {
    printf("Solution found!");

    for (int i = 0; i < k; i++) {
      printf("%d ", sol[i]);
    }
    printf("\n");
    return;
  }

  for (int i = c_idx; i < N; i++) {
    if (!is_valid(required_sum, current, subset[i])) {
      continue;
    }
    sol[k] = subset[i];
    k++;
    current = current + subset[i];
    solve(subset, i + 1, required_sum, current);

    k--;
    current = current - subset[i];
  }
}

int main() {
  int set[N] = {3, 5, 6, 8, 13, 1};
  int sum = 14;
  int current = 0;

  solve(set, 0, sum, current);
}

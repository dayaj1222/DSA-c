#include <stdio.h>
#define N 3

int sol[N];
int k = 0;

void solve(int *set, int c_idx) {
  if (c_idx >= N) {
    for (int i = 0; i < k; i++) {
      printf("%d ", sol[i]);
    }
    printf("\n");
    return;
  }

  // first include
  sol[k] = set[c_idx];
  k++;
  solve(set, c_idx + 1);
  k--;

  // then exclude
  solve(set, c_idx + 1);
}

int main() {
  int set[] = {1, 2, 3};

  solve(set, 0);
  printf("\nPHI");
}

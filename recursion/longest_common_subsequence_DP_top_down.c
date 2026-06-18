#include <stdio.h>
#include <string.h>
#define N 3
int memo[N + 1][N + 1];
int max(int a, int b) { return a > b ? a : b; }

int lcs(int A[], int B[], int i, int j) {
  if (i == 0 || j == 0)
    return 0;
  if (memo[i][j] != -1)
    return memo[i][j];
  if (A[i] == B[j])
    memo[i][j] = 1 + lcs(A, B, i - 1, j - 1);
  else
    memo[i][j] = max(lcs(A, B, i - 1, j), lcs(A, B, i, j - 1));
  return memo[i][j];
}

int result[N];
int len = 0;

void reconstruct(int A[], int B[], int i, int j) {
  if (i == 0 || j == 0)
    return;
  if (A[i] == B[j]) {
    reconstruct(A, B, i - 1, j - 1);
    result[len++] = A[i];
  } else {
    memo[i - 1][j] > memo[i][j - 1] ? reconstruct(A, B, i - 1, j)
                                    : reconstruct(A, B, i, j - 1);
  }
}

int main() {
  int A[] = {0, 'A', 'B', 'C'};
  int B[] = {0, 'C', 'A', 'B'};
  memset(memo, -1, sizeof(memo));
  printf("LCS length: %d\n", lcs(A, B, N, N));
  reconstruct(A, B, N, N);
  for (int i = 0; i < len; i++)
    printf("%c ", result[i]);
  printf("\n");
}

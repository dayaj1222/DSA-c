#include <stdio.h>
#include <string.h>
#define N 3

int memo[3][3];

int max(int a, int b) { return a > b ? a : b; }

int lcs(int A[], int B[], int i, int j) {

  if (i == -1 || j == -1) {
    return 0;
  }

  if (memo[i][j] != -1)
    return memo[i][j];

  int result;
  if (A[i] == B[j]) {
    result = 1 + lcs(A, B, i - 1, j - 1);
  } else {

    result = max(lcs(A, B, i - 1, j), lcs(A, B, i, j - 1));
  }
  memo[i][j] = result;
  return result;
}

int result[N];
int len = 0;

void reconstruct(int A[], int B[], int i, int j) {
  if (i == -1 || j == -1) {
    return;
  }

  if (A[i] == B[j]) {
    reconstruct(A, B, i - 1, j - 1);
    result[len++] = A[i];

  } else {
    memo[i - 1][j] > memo[i][j - 1] ? reconstruct(A, B, i - 1, j)
                                    : reconstruct(A, B, i, j - 1);
  }
}

int main() {
  int A[] = {'A', 'B', 'C'};
  int B[] = {'C', 'A', 'B'};
  memset(memo, -1, sizeof(memo));

  printf("%d", lcs(A, B, 2, 2));
  reconstruct(A, B, 2, 2);

  printf("\n");
  printf("%c %c %c", result[0], result[1], result[2]);
}

#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int lcs(int A[], int B[], int i, int j) {

  if (i == -1 || j == -1) {
    return 0;
  }

  if (A[i] == B[j]) {
    return 1 + lcs(A, B, i - 1, j - 1);
  }

  return max(lcs(A, B, i - 1, j), lcs(A, B, i, j - 1));
}

int main() {
  int A[] = {'A', 'B', 'C'};
  int B[] = {'C', 'A', 'B'};

  printf("%d", lcs(A, B, 2, 2));
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lcs(int **memo, int *a, int *b, int i, int j) {
  if (i == 0 || j == 0) {
    return 0;
  }

  if (memo[i][j] != -1) {
    return memo[i][j];
  }

  int result;
  if (a[i] == b[j]) {
    result = 1 + lcs(memo, a, b, i - 1, j - 1);
  } else {
    int op1 = lcs(memo, a, b, i - 1, j);
    int op2 = lcs(memo, a, b, i, j - 1);
    result = op1 > op2 ? op1 : op2;
  }
  memo[i][j] = result;
  return result;
}

int main() {
  char a[] = "ABDF";
  char b[] = "DFAB";

  int m = strlen(a);
  int n = strlen(b);

  int **memo = malloc(sizeof(int) * 100);

  lcs(memo, a, b, m, n);

  int sol[10];
  int k = 0;
}

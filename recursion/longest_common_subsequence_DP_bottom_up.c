#include <stdio.h>
#define N 3

int max(int a, int b) { return (a > b) ? a : b; }

int table[N + 1][N + 1];

int lcs(int *A, int *B) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (A[i - 1] == B[j - 1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
      } else {
        table[i][j] = max(table[i][j - 1], table[i - 1][j]);
      }
    }
  }
  return table[N][N];
}

int result[N];
int l = 0;
void reconstruct(int *a, int *b) {
  int i = N, j = N;
  while (i > 0 && j > 0) {

    if (a[i - 1] == b[j - 1]) {
      result[l++] = a[i - 1];
      i--;
      j--;

    } else {
      if (table[i][j - 1] > table[i - 1][j]) {
        j--;
      } else {
        i--;
      }
    }
  }
}

int main() {
  int A[] = {'A', 'B', 'C'};
  int B[] = {'C', 'A', 'B'};

  printf("%d", lcs(A, B));
  reconstruct(A, B);

  printf("\n");
  for (int k = l - 1; k >= 0; k--)
    printf("%c ", result[k]);
}

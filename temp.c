#include <stdio.h>
#define V 3

int max(int a, int b) { return a > b ? a : b; }

int table[V][V]; // should be -1 initialized

int lcs(int *A, int *B, int i, int j) {
  if (i == -1 || j == -1) {
    return 0;
  }

  if (table[i][j] != -1) {
    return table[i][j];
  }

  if (A[i] == B[j]) {
    table[i][j] = 1 + lcs(A, B, i - 1, j - 1);
  } else {
    table[i][j] = max(lcs(A, B, i - 1, j), lcs(A, B, i, j - 1));
  }

  return table[i][j];
}

int ans[V];
int k = 0;

void reconstruct_iter(int *A, int *B) {
  int i = V;
  int j = V;

  while (i >= 0 && j >= 0) {
    if (A[i] == B[j]) {
      ans[k++] = A[i];
      j--;
      i--;
    } else {
      int can_go_up = (i > 0);
      int can_go_left = (j > 0);

      if (can_go_up && can_go_left) {
        if (table[i - 1][j] > table[i][j - 1])
          i--;
        else
          j--;
      } else if (can_go_up) {
        i--;
      } else {
        j--;
      }
    }
  }
}

void reconstruct_rec(int *A, int *B, int i, int j) {
  if (i == -1 || j == -1) {
    return;
  }

  if (A[i] == B[j]) {
    reconstruct_rec(
        A, B, i - 1,
        j - 1); // reconstruct first then add to ans for right order.
    ans[k++] = A[i];
  } else {
    if (table[i - 1][j] > table[i][j - 1]) {
      reconstruct_rec(A, B, i - 1, j);
    } else {
      reconstruct_rec(A, B, i, j - 1);
    }
  }
}

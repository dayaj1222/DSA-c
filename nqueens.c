#include <stdio.h>
#include <stdlib.h>

int sols = 0;

int is_safe(int *board, int row, int col) {
  for (int i = 0; i < row; i++) {
    if (board[i] == col)
      return 0;
    if (abs(board[i] - col) == abs(i - row)) {
      return 0;
    }
  }
  return 1;
}

void solve(int *board, int row, int n) {
  if (row == n) {
    printf("\nSolution Found:\n");
    for (int i = 0; i < n; i++) {
      printf("%d ", board[i]);
    }
    sols++;
  }

  for (int col = 0; col < n; col++) {
    if (!is_safe(board, row, col)) {
      continue;
    }
    board[row] = col;
    solve(board, row + 1, n);
  }
  return;
}

int main(int argc, char **argv) {
  int n = 8;
  int board[n];
  (solve(board, 0, n));
  printf("\nNumber of solutions: %d", sols);
  return 0;
}

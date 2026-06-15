#include <stdio.h>

#define N 8

int moves[N][N]; // move[col][row] = step; will store the moves of the knight
int step = 0;
int sols = 0;

int dir_x[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dir_y[] = {2, -2, -1, 1, 2, -2, 1, -1};

int isSafe(int c, int r) {
  if (moves[r][c] == -1) {
    return 0;
  }

  if (c >= 8 || c < 0 || r >= 8 || r < 0) {
    return 0;
  }
  return 1;
}

int solve(int col, int row) {
  if (step == N * N) {
    printf("Solution found");
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (moves[i][j] != -1) {
          printf("\nStep: %d ", moves[i][j]);
          printf("\n(%d, %d)", i, j);
        }
      }
    }
    return 1;
  }

  for (int i = 0; i < 8; i++) {
    int ncol = col + dir_y[i];
    int nrow = row + dir_x[i];

    if (!isSafe(ncol, nrow)) {
      continue;
    }

    moves[nrow][ncol] = step;
    step++;

    solve(ncol + 1, nrow + 1);

    moves[ncol][nrow] = -1;
    step--;
  }
  return 0;
}

int main() { solve(0, 0); }

#include <stdio.h>
#define N 4

int solve(int *a, int n) {
  if (n == N) {
    return 0;
  }
  // perform my task to place the queen on current row, in a valid column
  int toinsert = 0;
  int isinvalid = 1;
  while (isinvalid) { // loop until we find a valid plave to put the queen
    printf("row=%d toinsert=%d\n", n, toinsert);
    isinvalid = 0;
    for (int j = 0; j < n; j++) { // check all column from 0 to current
      if (toinsert == a[j]) { // if any column has a queen set invalid flag and
                              // stop checking
        isinvalid = 1;
        continue;
      }
    }

    // otherwise we need to check the diagonal case to verify if this
    // cell is valid
    // we loop throughthe 0 to n again this time.
    for (int i = 0; i < n; i++) {
      int sum = a[i] + i;
      int diff = a[i] - i;
      if (sum == n + toinsert || diff == n - toinsert) {
        isinvalid = 1;
        continue;
      }
    }

    if (isinvalid) {
      toinsert++;
    }

    if (toinsert > N) {
      return 1;
    }

    if (!isinvalid) {
      a[n] = toinsert;
      if (solve(a, n + 1) == 0)
        return 0; // success
      toinsert++;
      isinvalid = 1; // force the while to continue
    }
  }
  return 0;
}

int main() {
  int arr[N];

  solve(arr, 0);

  for (int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }
}

#include <stdio.h>

int climb(int n) {
  if (n == 0)
    return 1;

  if (n == 1)
    return 1;

  return climb(n - 1) + climb(n - 2);
}

int main() { printf("%d", climb(2)); }

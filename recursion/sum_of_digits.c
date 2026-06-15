#include <stdio.h>

int sum(int n) {
  if (n < 10) {
    return n;
  }

  int last = n % 10;
  int other = n / 10;
  return last + sum(other);
}

int main() { printf("%d", sum(43215)); }

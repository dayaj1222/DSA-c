#include <stdio.h>

int gcd(int a, int b) {
  if (a == 0) {
    return b;
  } else if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

int main() { printf("%d", gcd(20, 4)); }

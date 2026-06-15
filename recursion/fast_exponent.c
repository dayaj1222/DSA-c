#include <stdio.h>

int expo(int base, int e) {
  if (e == 1) {
    return base;
  }

  int half = expo(base, e / 2);
  if (e % 2 == 0) {
    return half * half;
  } else {
    return half * half * base;
  }
}

int main() { printf("%d", expo(5, 5)); }

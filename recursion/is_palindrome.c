#include <stdio.h>

int is_palindrome(char *c, int start, int end) {
  if (start >= end) {
    return 1;
  }

  if (c[start] == c[end]) {
    if (is_palindrome(c, start + 1, end - 1)) {
      return 1;
    }
  }
  return 0;
}

int main() { printf("%d", is_palindrome("aab", 0, 2)); }

#include <stdio.h>

void Display(int *arr, char *b, int n) {
  printf("\n");
  for (int i = 0; i < n; i++) {

    if (b[i] == '1') {
      printf("%d", arr[i]);
    }
  }
}

int check(char *b, int n) {
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == '1') {
      c++;
    }
  }
  return c == n;
}

int *subset(int *arr, int n) {
  if (n == 1) {
    char t[] = "1";
    Display(arr, t, n);
    printf("\n PHI");
  }

  char bin[n + 1];
  bin[n] = '\0';
  for (int i = 0; i < (1 << n); i++) {
    for (int b = 0; b < n; b++) {
      bin[b] = ((i >> (n - 1 - b)) & 1) ? '1' : '0';
    }

    if (check(bin, n)) {
      Display(arr, bin, n);
    }
  }
  subset(arr, n - 1);
  return 0;
}

int main() {
  int set[] = {1, 2, 3, 4};
  subset(set, 4);
}

#include <stdio.h>

int count = 0;

void paths(int n, int m) {
  if (m == 1 && n == 1) {
    count++;
    return;
  }

  if (n >= 0) {
    paths(n - 1, m);
  }
  if (m >= 0) {
    paths(n, m - 1);
  }
}

int main() {

  paths(3, 4);
  printf("%d", count);
}

// Better solution
// int count(int m , int n){
// if (m == 1 || n==1)
// return count (int m-1,n)+ count_paths(m,n-1);
// }

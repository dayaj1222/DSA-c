#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[5][5] = {{1, 2, 3, 4, 5},
                   {2, 3, 4, 5, 6},
                   {9, 8, 7, 6, 5},
                   {12, 23, 53, 54, 65},
                   {12, 34, 12, 34, 5}};

  // for (int i = 0; i < 5; i++) {
  //   for (int j = 0; j < 5; j++) {
  //     scanf("%d", (*(arr + i) + j));
  //   }
  // }
  // Print
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d\n", *(*(arr + i) + j));
    }
  }

  return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
  int s1;
  printf("Enter size of first array: ");
  scanf("%d", &s1);

  int *arr1 = malloc(sizeof(int) * s1);
  printf("\nEnter elements in the array one after another until end\n");

  for (int i = 0; i < s1; i++) {
    scanf("%d", arr1 + i);
  }
  printf("End of first array\n\n");

  int s2;
  printf("Enter size of second array: ");
  scanf("%d", &s2);
  int *arr2 = malloc(sizeof(int) * s2);

  printf("\nEnter elements in the array one after another until end\n");
  for (int i = 0; i < s2; i++) {
    scanf("%d", arr2 + i);
  }
  printf("End of second array\n\n");

  int arr3[s1 + s2];
  for (int i = 0; i < s1; i++) {

    arr3[i] = arr1[i];
  }

  for (int i = 0; i < s2; i++) {
    arr3[s1 + i] = arr2[i];
  }

  printf("Merged Array\n");
  printf("[");
  for (int i = 0; i < (s1 + s2); i++) {
    printf("%d ", arr3[i]);
  }
  printf("]");

  return 0;
}

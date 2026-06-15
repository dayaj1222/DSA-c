#include <stdio.h>

void hanoi(int n, int from, int to, int aux) {

  if (n == 1) {
    printf("\nMove disk %d from %c to %c", n, from, to);
    return;
  }

  // my job is to move the nth disk, first i need to move n-1 disk from A to C;
  hanoi(n - 1, from, aux, to);

  // Then i move the Nth disk to the B;
  printf("\nMove disk %d from %c to %c", n, from, to);

  // Then move those n-1 disks from C to B, All N disks are moved from A to B
  hanoi(n - 1, aux, to, from);
}

int main() { hanoi(2, 'a', 'b', 'c'); }

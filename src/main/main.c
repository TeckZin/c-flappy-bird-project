#include <stdio.h>

int main() {

  printf("hello world\n");
  int i = 2;
  printf("%d\n", i);
  int *iP = &i;
  *iP = 4;
  printf("%d\n", i);

  return 0;
}

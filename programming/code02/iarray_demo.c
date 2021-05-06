// iarray_demo.c --- array input/output and equality demo.
#include <stdio.h>
#include <stdbool.h>
void iarray_read(int *a, int n) {
  for(int i = 0; i < n; ++i) {
    printf("%d> ", i+1); scanf("%d", a+i);
  }
}
void iarray_print(int *a, int n) {
  for(int i = 0; i < n; ++i) { printf(" %2d", a[i]); }
  printf("\n");
}
bool iarray_equal(int *a, int *b, int n) {
  for(int i = 0; i <= n; ++i) {
    if(a[i] != b[i]) { return false; }
  }
  return true;
}
char *bool2str(bool b) { return b ? "true" : "false"; }
int main(void) {
  int a[4], b[4];
  iarray_read(a, 4); iarray_print(a, 4);
  iarray_read(b, 4); iarray_print(b, 4);
  printf("equal: %s\n", bool2str(iarray_equal(a, b, 4)));
  return 0;
}

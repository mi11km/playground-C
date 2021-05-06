// ivec_demo.c --- int vector demonstration.
#include <stdio.h>
#include <stdlib.h>
void iarray_read(int *a, int n) {
  for(int i = 0; i < n; ++i) {
    printf("%d> ", i+1); scanf("%d", a+i);
  }
}
void iarray_print(int *a, int n) {
  for(int i = 0; i < n; ++i) { printf(" %2d", a[i]); }
  printf("\n");
}
int *ivec_new(int size) {
  int *a = (int*)malloc((size+1) * sizeof(int));
  a[0] = size; return a;
}
void ivec_read(int *a) { iarray_read(a+1, a[0]); }
void ivec_print(int *a) { iarray_print(a+1, a[0]); }
int *ivec_concat(int *a, int *b) {
  int *c = ivec_new(a[0]+b[0]);
  for(int i = 1; i <= a[0]; ++i) { c[i] = a[i]; }
  for(int i = 1; i <= b[0]; ++i) { c[i + a[0]] = b[i]; }
  return c;
}
int main(void) {
  int *a, *b, *c;
  a = ivec_new(3); ivec_read(a);
  b = ivec_new(2); ivec_read(b);
  c = ivec_concat(b, a); ivec_print(c);
  free(a); free(b); free(c);
  return 0;
}

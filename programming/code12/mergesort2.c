// mergesort2 --- merge sort with recuresive division
#include <stdlib.h>
(mergeはここでは省略)
static void ms(int *a, int i, int j, int *b) {
  if(i >= j) { return; }
  int k = (i + j) / 2;
  ms(a, i, k, b); ms(a, k+1, j, b);
  merge(b, a+i, k-i+1, a+k+1, j-k);
  for(k = 0; k < j-i+1; ++k) { a[i+k] = b[k]; }
}
void mergesort2(int *a, int n) {
  int *b = (int*)malloc(n * sizeof(int)); ms(a, 0, n-1, b); free(b);
}

// binsort.c --- binsort with specified maximum
#include <stdlib.h>
void binsort(int n, int *a, int max) {
  int i, k = 0, *bin = (int*)malloc((max+1) * sizeof(int));
  for(i = 0; i <= max; ++i) { bin[i] = 0; }
  for(i = 0; i < n; ++i) { ++bin[a[i]]; }
  for(i = 0; i <= max; ++i) {
    while(--bin[i] >= 0) { a[k++] = i; }
  }
  free(bin);
}

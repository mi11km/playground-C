// quicksort --- quick sort with recuresive division
static void iswap(int *a, int i, int j) {
  int x = a[i]; a[i] = a[j]; a[j] = x;
}
void qs(int *a, int i, int j) {
  if(j <= i) { return; }
  int s = i, pivot = a[j];
  for(int k = i; k < j; ++k) {
    if(a[k] < pivot) { iswap(a, s++, k); }
  }
  iswap(a, j, s); qs(a, i, s-1); qs(a, s+1, j);
}
void quicksort(int *a, int n) { qs(a, 0, n-1); }

static void iswap(int a[], int i, int j) {
  int x = a[i]; a[i] = a[j]; a[j] = x;
}
static int minrange(int a[], int i, int j) {
  int min = a[i], pos = i;
  for(int k = i+1; k <= j; ++k) {
    if(a[k] < min) { min = a[k]; pos=k; }
  }
  return pos;
}
void selectionsort(int n, int a[]) {
  for(int i = 0; i < n; ++i) { iswap(a, i, minrange(a, i, n-1)); }
}

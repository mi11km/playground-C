// heapsort1 --- heap sort using balanced bin-tree
#define P(i) ((i-1)/2)
#define L(i) (2*i+1)
#define R(i) (2*i+2)

static void iswap(int *a, int i, int j) {
  int x = a[i]; a[i] = a[j]; a[j] = x;
}
void pd(int *a, int i, int j) {
  for(int k = L(i); k <= j; ) {
    if(k < j && a[k] < a[k+1]) { ++k; }
    if(a[P(k)] >= a[k]) { break; }
    iswap(a, P(k), k); k = L(k);
  }
}
void heapsort1(int *a, int n) {
  for(int i = n-1; i >= 0; --i) { pd(a, i, n-1); }
  for(int i = n-1; i > 0; --i) { iswap(a, 0, i); pd(a, 0, i-1); }
}

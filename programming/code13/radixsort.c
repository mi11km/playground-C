// radixsort.c --- radixsort (upper->lower) from specified mask
static void swap(int *a, int i, int j) {
  int x = a[i]; a[i] = a[j]; a[j] = x;
}
static void rs(int *a, int i, int j, int mask) {
  if(i >= j || mask == 0) { return; }
  int k, s;
  for(s = k = i; k <= j; ++k) {
    if((a[k]&mask) == 0) { swap(a, s++, k); }
  }
  rs(a, i, s-1, mask/2); rs(a, s, j, mask/2);
}
void radixsort(int n, int *a) { rs(a, 0, n-1, 0x40000000); }

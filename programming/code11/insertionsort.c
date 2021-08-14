static int shiftrange(int a[], int i) {
  int x = a[i], j;
  for(j = i; j > 0 && a[j-1] > x; --j) { a[j] = a[j-1]; }
  a[j] = x;
}
void insertionsort(int n, int a[]) {
  for(int i = 1; i < n; ++i) { shiftrange(a, i); }
}

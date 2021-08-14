static void iswap(int a[], int i, int j) {
  int x = a[i]; a[i] = a[j]; a[j] = x;
}
void bublesort(int n, int a[]) {
  bool done = false;
  while(!done) {
    done = true;
    for(int i = 1; i < n; ++i) {
      if(a[i-1] > a[i]) { iswap(a, i-1, i); done = false; }
    }
  }
}

int bsearch(int *a, int e, int i, int j) {
  if(i > j) { return -1; }
  int k = (i + j) / 2;
  if(a[k] == e) {
    return k;
  } else if(a[k] > e) {
    return bsearch(a, e, i, k-1);
  } else {
    return bsearch(a, e, k+1, j);
  }
}

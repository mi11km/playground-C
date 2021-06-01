int fact1(int n, int r) {
  if(n < 1) {
    return r;
  } else {
    return fact1(n-1, r*n);
  }
}
int fact(int n) { return fact1(n, 1); }

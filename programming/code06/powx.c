int powx(double x, int n) {
  if(n < 1) {
    return 1.0;
  } else {
    return x * powx(x, n-1);
  }
}

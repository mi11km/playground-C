int gcd(int x, int y) {
  if(x == y) {
    return x;
  } else if(x > y) {
    return gcd(x-y, y);
  } else {
    return gcd(x, y-x);
  }
}

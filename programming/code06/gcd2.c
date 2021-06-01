int gcd2(int x, int y) {
  while(true) {
    if(x == y) {
      return x;
    } else if(x > y) {
      x = x - y;
    } else {
      y = y - x;
    }
  }
}

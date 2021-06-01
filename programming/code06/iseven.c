bool iseven(int n) {
  if(n == 0) {
    return true;
  } else if(n == 1) {
    return false;
  } else {
    return iseven(n - 2);
  }
}

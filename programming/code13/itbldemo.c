// itbldemo.c --- register primes with ranks.
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "itbl.h"

bool isprime(int n) {
  int lim = (int)sqrt(n);
  for(int i = 2; i <= lim; ++i) { if(n % i == 0) { return false; } }
  return true;
}
int regist(itblp t, int lim) {
  int r = 0;
  for(int i = 2; i <= lim; ++i) { if(isprime(i)) { itbl_put(t, i, ++r); } }
  return r;
}
int main(int argc, char *argv[]) {
  itblp t = itbl_new();
  printf("max rank = %d\n", regist(t, 10000));
  for(int i = 1; i < argc; ++i) {
    int k = atoi(argv[i]); printf("%d: %d\n", k, itbl_get(t, k));
  }
  return 0;
}


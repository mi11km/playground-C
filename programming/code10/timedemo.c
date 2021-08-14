// timedemo.c --- demonstration of mesuring time.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "iset.h"

int pow3n(int n) {
  if(n < 1) { return 1; }
  else { return pow3n(n-1)+pow3n(n-1)+pow3n(n-1); }
}
int main(int argc, char *argv[]) {
  int i, n = atoi(argv[1]);
  struct timespec tm1, tm2;
  clock_gettime(CLOCK_REALTIME, &tm1);
  int v = pow3n(n);
  clock_gettime(CLOCK_REALTIME, &tm2);
  double dt = (tm2.tv_sec-tm1.tv_sec) + 1e-9*(tm2.tv_nsec-tm1.tv_nsec);
  printf("pow3n(%d) = %d; elapsed-time = %.4f\n", n, v, dt);
  return 0;
}


// randdemo.c --- demonstration of rand.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int i, n = atoi(argv[1]);
  srand(time(NULL));
  for(i = 0; i < n; ++i) { printf(" %d", rand() % 1000); }
  printf("\n");
  for(i = 0; i < n; ++i) { printf(" %.3f", rand()/(double)RAND_MAX); }
  printf("\n");
  return 0;
}

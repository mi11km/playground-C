// test_sort.c --- unit test for sort algorithms.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void iswap(int a[], int i, int j) {
  int x = a[i]; a[i] = a[j]; a[j] = x;
}
static int minrange(int a[], int i, int j) {
  int min = a[i], pos = i;
  for(int k = i+1; k <= j; ++k) {
    if(a[k] < min) { min = a[k]; pos=k; }
  }
  return pos;
}
void selectionsort(int n, int a[]) {
  for(int i = 0; i < n; ++i) { iswap(a, i, minrange(a, i, n-1)); }
}
static int shiftrange(int a[], int i) {
  int x = a[i], j;
  for(j = i; j > 0 && a[j-1] > x; --j) { a[j] = a[j-1]; }
  a[j] = x;
}
void insertionsort(int n, int a[]) {
  for(int i = 1; i < n; ++i) { shiftrange(a, i); }
}
void bubblesort(int n, int a[]) {
  bool done = false;
  while(!done) {
    done = true;
    for(int i = 1; i < n; ++i) {
      if(a[i-1] > a[i]) { iswap(a, i-1, i); done = false; }
    }
  }
}
void expect_sort_iarray(int n, void (*f)(int m, int *a), char *msg) {
  int c = 0, *a = (int*)malloc(n * sizeof(int));
  srand(time(NULL));
  for(int i = 0; i < n; ++i) { a[i] = rand()%10000; }
  struct timespec tm1, tm2;
  clock_gettime(CLOCK_REALTIME, &tm1);
  (*f)(n, a);
  clock_gettime(CLOCK_REALTIME, &tm2);
  for(int i = 1; i < n; ++i) {
    if(a[i-1] <= a[i]) { continue; } // correct order
    if(++c < 5) {
      printf("  wrong order at %d: %d > %d\n", i-1, a[i-1], a[i]);
    } else if(c == 5) {
      printf("  more wrong place omitted.\n");
    }
  }
  double dt = (tm2.tv_sec-tm1.tv_sec) + 1e-9*(tm2.tv_nsec-tm1.tv_nsec);
  printf("%s time=%.4f %s\n", c==0?"OK":"NG", dt, msg); free(a);
}
int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  expect_sort_iarray(n, selectionsort, "selectionsort");
  expect_sort_iarray(n, insertionsort, "inserctionsort");
  expect_sort_iarray(n, bubblesort, "bubblesort");
  return 0;
}

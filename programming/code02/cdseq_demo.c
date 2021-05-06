// cdseq_demo.c -- cdseq demonstration.
#include <stdio.h>
#include "cdseq.h"
int main(void) {
  struct cdseq *s1 = cdseq_new(1, 2);
  struct cdseq *s2 = cdseq_new(0, 3);
  int i;
  for(i = 0; i < 6; ++i) {
    printf(" %2d", cdseq_get(s1));
    printf(" %2d", cdseq_get(s1));
    printf(" %2d", cdseq_get(s2));
  }
  printf("\n"); cdseq_free(s1); cdseq_free(s2);
  return 0;
}

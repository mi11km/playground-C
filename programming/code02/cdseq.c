// cdseq.c -- cdseq implementation.
#include <stdlib.h>
#include "cdseq.h"
struct cdseq { int value, diff; };
struct cdseq *cdseq_new(int s, int d) {
  struct cdseq *r = (struct cdseq*)malloc(sizeof(struct cdseq));
  r->value = s; r->diff = d; return r;
}
int cdseq_get(struct cdseq *r) {
  int v = r->value; r->value += r->diff; return v;
}
void cdseq_free(struct cdseq *r) {
  free(r);
}

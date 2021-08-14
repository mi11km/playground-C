// itbl2.c --- itbl impl with sorted arry of records.
#include <stdlib.h>
#include "itbl.h"
typedef struct ent { int key, val; } * entp;
struct itbl { int size, lim; entp arr; };
itblp itbl_new() {
  itblp p = (itblp)malloc(sizeof(struct itbl));
  p->arr = (entp)malloc(100 * sizeof(struct ent));
  p->size = 0; p->lim = 100; return p;
}
static void enlarge(itblp p) {
  entp a = (entp)malloc(p->lim * 2 * sizeof(struct ent));
  for(int i = 0; i < p->size; ++i) { a[i] = p->arr[i]; }
  free(p->arr); p->arr = a; p->lim *= 2;
}
static entp lookup2(itblp p, int k, int i, int j) {
  if(i > j) { return NULL; }
  int m = (i + j) / 2;
  if(p->arr[m].key == k)     { return p->arr + m; }
  else if(p->arr[m].key > k) { return lookup2(p, k, i, m-1); }
  else                       { return lookup2(p, k, m+1, j); }
}
void shiftup(itblp p) {
  entp a = p->arr;
  for(int i = p->size-1; i > 0 && a[i-1].key > a[i].key; --i) {
    struct ent x = a[i-1]; a[i-1] = a[i]; a[i] = x;
  }
}
void itbl_put(itblp p, int k, int v) {
  entp e = lookup2(p, k, 0, p->size-1);
  if(e != NULL) { e->val = v; return; }
  if(p->size + 1 >= p->lim) { enlarge(p); }
  p->arr[p->size].key = k; p->arr[p->size++].val = v; shiftup(p);
}
int itbl_get(itblp p, int k) {
  entp e = lookup2(p, k, 0, p->size-1);
  return e == NULL ? -1 : e->val;
}

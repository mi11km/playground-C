// itbl.c --- itbl impl with arry of records.
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
static entp lookup(itblp p, int k) {
  for(int i = 0; i < p->size; ++i) {
    if(p->arr[i].key == k) { return p->arr + i; }
  }
  return NULL;
}
void itbl_put(itblp p, int k, int v) {
  entp e = lookup(p, k);
  if(e != NULL) { e->val = v; return; }
  if(p->size + 1 >= p->lim) { enlarge(p); }
  p->arr[p->size].key = k; p->arr[p->size++].val = v;
}
int itbl_get(itblp p, int k) {
  entp e = lookup(p, k); return e == NULL ? -1 : e->val;
}

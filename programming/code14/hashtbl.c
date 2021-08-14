// hashtbl.c --- itbl impl w/ random rehashing.
#include <stdlib.h>
#include "itbl.h"

typedef struct ent {
    int key, val;
} *entp;
struct itbl {
    int size;
    entp arr;
};
#define INITSIZE 999983
#define REHASH 97

itblp itbl_new() {
    itblp p = (itblp) malloc(sizeof(struct itbl));
    p->arr = (entp) malloc(INITSIZE * sizeof(struct ent));
    p->size = INITSIZE;
    for (int i = 0; i < p->size; ++i) { p->arr[i].key = -1; }
    return p;
}

static int h1(itblp p, int n) { return n % p->size; }

static int h2(int n) { return n % REHASH + 3; }

void itbl_put(itblp p, int k, int v) {
    int i = h1(p, k), d = h2(k), c = 0;
    while (p->arr[i].key != k && p->arr[i].key != -1) {
        if (++c > p->size) { return; }
        i = (i + d) % p->size;
    }
    p->arr[i].key = k;
    p->arr[i].val = v;
}

int itbl_get(itblp p, int k) {
    int i = h1(p, k), d = h2(k), c = 0;
    while (p->arr[i].key != k) {
        if (++c > p->size || p->arr[i].key == -1) { return -1; }
        i = (i + d) % p->size;
    }
    return p->arr[i].val;
}

// railmap2.c -- search railroad paths (queue version)
#include <stdio.h>
#include <stdlib.h>
#include "iqueue.h"
#include "railmap.h"

int main(int argc, char *argv[]) {
  int start = atoi(argv[1]), goal = atoi(argv[2]);
  iqueuep s = iqueue_new(100);
  map[start].dist = 0; iqueue_enq(s, start);
  while(!iqueue_isempty(s)) {
    int i, n = iqueue_deq(s);
    struct node *p = map + n;
    printf("%d: %s, %d\n", n, p->name, p->dist);
    if(n == goal) { printf("GOAL.\n"); break; }
    for(i = 0; i < p->num; ++i) {
      int k = p->edge[i];
      if(map[k].dist < 0) {
        map[k].dist = p->dist+1; iqueue_enq(s, k);
      }
    }
  }
  return 0;
}

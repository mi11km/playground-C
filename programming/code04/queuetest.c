// queuetest.c -- demonstration of iqueue
#include <stdio.h>
#include <stdlib.h>
#include "iqueue.h"

void readenq(iqueuep q) {
  int c;
  printf("s> ");
  for(c = getchar(); c != '\n' && c != EOF; c = getchar()) {
    iqueue_enq(q, c);
  }
}
int main(void) {
  int c;
  iqueuep q = iqueue_new(200);
  readenq(q); readenq(q); readenq(q);
  while(!iqueue_isempty(q)) { putchar(iqueue_deq(q)); }
  putchar('\n');
  return 0;
}

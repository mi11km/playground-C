// slistdemo1.c --- single-linked list demonstration
#include <stdio.h>
#include <stdlib.h>
struct node { double data; struct node *next; };
typedef struct node *nodep;

nodep node_new(double d, nodep n) {
  nodep p = (nodep)malloc(sizeof(struct node));
  p->data = d; p->next = n; return p;
}
void plist(nodep p) {
  if(p == NULL) { printf("\n"); return; }
  printf(" %g", p->data); plist(p->next);
}
nodep mklist(int n, char *a[]) {
  if(n == 0) { return NULL; }
  return node_new(atof(*a), mklist(n-1, a+1));
}
void insert(nodep p, double d) {
  nodep q;
  if(p!=NULL) q = node_new(d, p->next);
  p->next = q;
}
void delete(nodep p) {
  nodep q = p->next;
  if(q!=NULL) p->next = q->next;
}
int main(int argc, char *argv[]) {
  nodep p = mklist(argc-1, argv+1); plist(p);
  insert(p, 6); plist(p);
  insert(p->next, 2); plist(p);
  delete(p->next); plist(p);
  return 0;
}

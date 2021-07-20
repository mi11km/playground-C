void plist(nodep p) {
  if(p == NULL) { printf("\n"); return; }
  printf(" %g", p->data); plist(p->next);
}
nodep mklist(int n, char *a[]) {
  if(n == 0) { return NULL; }
  return node_new(atof(*a), mklist(n-1, a+1));
}

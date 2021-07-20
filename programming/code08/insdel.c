void insert(nodep p, double d) {
  nodep q;
  if(p!=NULL) q = node_new(d, p->next);
  p->next = q;
}
void delete(nodep p) {
  nodep q = p->next;
  if(q!=NULL) p->next = q->next;
}

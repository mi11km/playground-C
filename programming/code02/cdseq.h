// cdseq.h --- constant difference sequence API.
struct cdseq *cdseq_new(int s, int d);
int cdseq_get(struct cdseq *r);
void cdseq_free(struct cdseq *r);

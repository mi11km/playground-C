// struct istack.h --- int type stack interface
#include <stdbool.h>

struct node;
typedef struct node *nodep;
struct istack;
typedef struct istack *istackp;

istackp istack_new(int size); // allocate new stack
bool istack_isempty(istackp p); // test if the stack is empty
void istack_push(istackp p, int v); // push a value
int istack_pop(istackp p);      // pop a value and return it

void print_stack(istackp p);
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct istack {
    int ptr;
    int *arr;
    int size;
};

typedef struct istack *istackp;

istackp istack_new(int size) {
    istackp p = (istackp) malloc(sizeof(struct istack));
    p->ptr = 0;
    p->arr = (int *) malloc(size * sizeof(int));
    p->size = size;
    return p;
}

bool istack_isempty(istackp p) { return p->ptr <= 0; }

void istack_push(istackp p, int v) { p->arr[p->ptr++] = v; }

int istack_pop(istackp p) { return p->arr[--(p->ptr)]; }

int istack_top(istackp p) { return p->arr[p->ptr - 1]; }

bool istack_full(istackp p) {
    if (p->size == p->ptr) {
        return true;
    }
    return false;
};

bool balance1(char *t) {
    istackp s = istack_new(200);
    for (int i = 0; t[i] != '\0'; ++i) {
        char c = t[i];
        if (c == '(' || c == '{') {
            istack_push(s, c);
        } else if (c == ')') {
            if (istack_isempty(s)) { return false; }
            int pop = istack_pop(s);
            if (pop != '(') { return false; }
        } else if (c == '}') {
            if (istack_isempty(s)) { return false; }
            int pop = istack_pop(s);
            if (pop != '{') { return false; }
        }
    }
    return istack_isempty(s);
}

int main(int argc, char *argv[]) {
    char *str = "H(ello, {w}orld{!)}";
    printf("%d\n", balance1(str));
    return 0;
}
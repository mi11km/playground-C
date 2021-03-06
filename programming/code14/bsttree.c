// bstree.c --- itbl impl with binary search tree.
#include <stdlib.h>
#include <stdio.h>
#include "itbl.h"

typedef struct ent *entp;
struct ent {
    int key, val;
    entp left, right;
};
struct itbl {
    entp root;
};

itblp itbl_new() {
    itblp p = (itblp) malloc(sizeof(struct itbl));
    p->root = NULL;
    return p;
}

static int get(entp p, int k) {
    if (p == NULL) { return -1; }
    if (k == p->key) { return p->val; }
    return get((k < p->key) ? p->left : p->right, k);
}

int itbl_get(itblp p, int k) {
    return get(p->root, k);
}

static entp put(entp p, int k, int v) {
    if (p == NULL) {
        p = (entp) malloc(sizeof(struct ent));
        p->left = p->right = NULL;
        p->key = k;
        p->val = v;
    } else if (k == p->key) {
        p->val = v;
    } else if (k < p->key) {
        p->left = put(p->left, k, v);
    } else if (k > p->key) {
        p->right = put(p->right, k, v);
    }
    return p;
}

void itbl_put(itblp p, int k, int v) {
    p->root = put(p->root, k, v);
}

static void pr(entp p) {
    if (p->left != NULL) {
        printf("(");
        pr(p->left);
        printf(") ");
    }
    printf("%d:%d", p->key, p->val);
    if (p->right != NULL) {
        printf(" (");
        pr(p->right);
        printf(")");
    }
}

void itbl_pr(itblp p) {
    if (p->root != NULL) {
        printf("(");
        pr(p->root);
        printf(")\n");
    }
}

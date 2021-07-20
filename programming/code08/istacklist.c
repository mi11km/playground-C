//
// Created by いけやままさふみ on 2021/06/13.
//

// istacklist.c --- int type stack impl. with array
#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

struct node {
    int data;
    struct node *next;
};

struct istack {
    nodep top;
};

istackp istack_new(int size) {
    istackp p = (istackp) malloc(sizeof(struct istack));
    p->top = NULL;
    return p;
}; // allocate new stack

bool istack_isempty(istackp p) {
    return p->top == NULL;
}; // test if the stack is empty

void istack_push(istackp p, int v) {
    nodep last_node = p->top;
    if (last_node == NULL) {
        last_node = (nodep) malloc(sizeof(nodep));
    } else {
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = (nodep) malloc(sizeof(nodep));
        last_node = last_node->next;
    }
    last_node->next = NULL;
    last_node->data = v;
}; // push a value

int istack_pop(istackp p) {
    nodep before_last_node = p->top;
    int result;
    if (before_last_node == NULL) {
        exit(1);
    } else if (before_last_node->next == NULL) {
        result = before_last_node->data;
        free(before_last_node);
        before_last_node = NULL;
    } else {
        while (before_last_node->next->next != NULL) {
            before_last_node = before_last_node->next;
        }
        result = before_last_node->next->data;
        free(before_last_node->next);
        before_last_node->next = NULL;
    }
    return result;
}; // pop a value and return it

void print_stack(istackp p) {
    nodep last = p->top;
    if (last == NULL) return;
    printf("[ ");
    while (last->next != NULL) {
        printf("%d ", last->data);
        last = last->next;
    }
    printf("]\n");
}
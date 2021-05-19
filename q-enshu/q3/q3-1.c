//
// Created by いけやままさふみ on 2021/05/20.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUF_SIZE 1024

#define STACKSIZE 128
typedef char elementtype;

typedef struct {
    int top;
    elementtype elements[STACKSIZE];
} stack;

void initstack(stack *s) {
    s->top = -1;
}

int stackempty(stack *s) {
    return s->top == -1;
}

void printstack(stack *s) {
    printf("[");
    for (int i = 0; i <= s->top; ++i) {
        printf("%c", s->elements[i]);
        if (i != s->top) printf(", ");
    }
    printf("]\n");
}

void push(stack *s, elementtype x) {
    s->top++;
    s->elements[s->top] = x;
}

elementtype pop(stack *s) {
    if (stackempty(s)) {
        exit(1);
    }
    s->top--;
    return s->elements[s->top + 1];
}

void test(void) {
    elementtype x;
    stack s;
    initstack(&s);

    char buf[MAX_BUF_SIZE], str[MAX_BUF_SIZE];
    int n = 0;

    while (fgets(buf, MAX_BUF_SIZE, stdin) != NULL) {
        if (strncmp(buf, "push ", 5) == 0) {
            // push
            x = buf[5]; // 6文字目が要素
            push(&s, x);
            continue;
        }
        if (strncmp(buf, "pop", 3) == 0) {
            // pop
            x = pop(&s);
            str[n] = x;
            n++;
            continue;
        }
        printf("Unknown command.\n");
    }

    printstack(&s);

    for (int i = 0; i < n; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main(void) {
    test();

    return 0;
}
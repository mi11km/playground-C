//
// Created by いけやままさふみ on 2020/11/01.
//

/*
#include <stdio.h>
char buf[128];

void update(int *p, int i) {
    *p = *p + i;
    if (*p > 99 || *p < -99) {
        *p = 0;
    }
    return;
}

int main() {
    int x = 0, i;
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        sscanf(buf, "%d", &i);
        update(&x, i);
        printf("%d\n", x);
    }
    return 0;
}

 -----
#include<stdio.h>

char buf[128];

struct zahyo {
    int x;
    int y;
};

void update(struct zahyo *p, int i, int j) {
    p->x += i;
    p->y += j;
    if (p->x * p->x + p->y * p->y >= 10000) {
        p->x = 0;
        p->y = 0;
    }
    return;
}

int main() {
    struct zahyo xy = {0, 0};
    int i, j;
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        sscanf(buf, "%d %d", &i, &j);
        update(&xy, i, j);
        printf("%d %d\n", xy.x, xy.y);
    }
    return 0;
}

 -----

#include<stdio.h>
#include <stdlib.h>

char buf[128];

#define MAXSTACK 128

typedef int elementtype;

struct stack {
    int top;
    elementtype contents[MAXSTACK];
};

void initstack(struct stack *p) {
    p->top = -1;
};

int stackempty(struct stack *p) {
    if (p->top == -1) {
        return 1;
    }
    return 0;
};

elementtype pop(struct stack *p) {
    if(p->top == -1) {
        printf("Underflow");
        exit(1);
    }
    p->top -= 1;
    return p->contents[p->top + 1];
};

void push(struct stack *p, elementtype e) {
    if (p->top == MAXSTACK-1) {
        printf("Overflow");
        exit(1);
    }
    p->top += 1;
    p->contents[p->top] = e;
};


int main() {
    struct stack s;
    int i, j;
    initstack(&s);
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        if (buf[0] == 'p') {
            pop(&s);
        } else {
            sscanf(buf, "%d", &i);
            push(&s, i);
        }
        for(j = 0; j <= s.top; j++) {
            printf("[%d]", s.contents[j]);
        }
        printf("\n");
    }
}

 -----
#include<stdio.h>
#include <stdlib.h>

#define MAXSTACK 512

typedef char elementtype;

struct stack {
    int top;
    elementtype contents[MAXSTACK];
};

void initstack(struct stack *p) {
    p->top = -1;
};

int stackempty(struct stack *p) {
    if (p->top == -1) {
        return 1;
    }
    return 0;
};

elementtype pop(struct stack *p) {
    if (p->top == -1) {
        printf("Underflow");
        exit(1);
    }
    p->top -= 1;
    return p->contents[p->top + 1];
};

void push(struct stack *p, elementtype e) {
    if (p->top == MAXSTACK - 1) {
        printf("Overflow");
        exit(1);
    }
    p->top += 1;
    p->contents[p->top] = e;
};

int isCloseBrackets(char *str) {
    struct stack s;
    initstack(&s);
    for (int i = 0; str[i] != '\0'; ++i) {
        switch (str[i]) {
            case '(':
            case '{':
            case '[':
            case '<':
                push(&s, str[i]);
                break;
            case ')':
            case '}':
            case ']':
            case '>':
                if ((str[i] == ')' && s.contents[s.top] == '(') ||
                    (str[i] == '}' && s.contents[s.top] == '{') ||
                    (str[i] == ']' && s.contents[s.top] == '[') ||
                    (str[i] == '>' && s.contents[s.top] == '<')) {
                    pop(&s);
                } else {
                    return 1;
                }
        }
    }
    if (stackempty(&s) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    char str[513];
    fgets(str, sizeof(str), stdin);
    if (isCloseBrackets((char *) &str) == 0) {
        printf("Good");
    } else {
        printf("Bad");
    }
    return 0;
}

 -----
#include<stdio.h>
#include <stdlib.h>

#define MAXSTACK 512
#define N 11

char buf[N + 2];
char canvas[N][N];

struct zahyo {
    int x, y;
};

typedef struct zahyo elementtype;

struct stack {
    int top;
    elementtype contents[MAXSTACK];
};

void initstack(struct stack *p) {
    p->top = -1;
};

int stackempty(struct stack *p) {
    if (p->top == -1) {
        return 1;
    }
    return 0;
};

elementtype pop(struct stack *p) {
    if (p->top == -1) {
        printf("Underflow");
        exit(1);
    }
    p->top -= 1;
    return p->contents[p->top + 1];
};

void push(struct stack *p, elementtype e) {
    if (p->top == MAXSTACK - 1) {
        printf("Overflow");
        exit(1);
    }
    p->top += 1;
    p->contents[p->top] = e;
};

int main() {
    int i, j;
    i = 0;
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        for (j = 0; j < N; ++j) {
            canvas[i][j] = buf[j];
        }
        ++i;
    }

    struct stack s;
    struct zahyo z = {5, 5}, z_r;
    initstack(&s);
    push(&s, z);
    canvas[z.x][z.y] = '.';

    while (stackempty(&s) == 0) {
        z = pop(&s);
        if (canvas[z.x + 1][z.y] == ' ') {
            z_r.x = z.x + 1;
            z_r.y = z.y;
            push(&s, z_r);
            canvas[z.x + 1][z.y] = '.';
        }
        if (canvas[z.x - 1][z.y] == ' ') {
            z_r.x = z.x - 1;
            z_r.y = z.y;
            push(&s, z_r);
            canvas[z.x - 1][z.y] = '.';
        }
        if (canvas[z.x][z.y + 1] == ' ') {
            z_r.x = z.x;
            z_r.y = z.y + 1;
            push(&s, z_r);
            canvas[z.x][z.y + 1] = '.';
        }
        if (canvas[z.x][z.y - 1] == ' ') {
            z_r.x = z.x;
            z_r.y = z.y - 1;
            push(&s, z_r);
            canvas[z.x][z.y - 1] = '.';
        }
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j)
            printf("%c", canvas[i][j]);
        printf("\n");
    }
    return 0;
}

-----
#include<stdio.h>
#include <stdlib.h>

#define MAXQUEUE 128

typedef int elementtype;

struct queue {
    int front;
    int rear;
    elementtype contents[MAXQUEUE];
};

void initqueue(struct queue *p) {
    p->front = 0;
    p->rear = 0;
};

int queueempty(struct queue *p) {
    if (p->front == p->rear) {
        return 0;
    }
    return 1;
};

elementtype getq(struct queue *p) {
    if (queueempty(p) == 0) {
        printf("Underflow");
        exit(1);
    }
    p->front++;
    if (p->front == MAXQUEUE) {
        p->front = 0;
        return p->contents[MAXQUEUE - 1];
    }
    return p->contents[p->front - 1];
};

void putq(struct queue *p, elementtype e) {
    if (p->rear + 1 == p->front || (p->rear == MAXQUEUE - 1 && p->front == 0)) {
        printf("Overflow");
        exit(1);
    }
    p->contents[p->rear] = e;
    p->rear++;
    if (p->rear == MAXQUEUE) {
        p->rear = 0;
    }
};


char buf[128];

int main() {
    struct queue q;
    int i, j;
    initqueue(&q);
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        if (buf[0] == 'g') {
            getq(&q);
        } else {
            sscanf(buf, "%d", &i);
            putq(&q, i);
        }
        for (j = q.front; j < q.rear; j++) {
            printf("[%d]", q.contents[j]);
        }
        printf("\n");
    }
}

 */
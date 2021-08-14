//
// Created by いけやままさふみ on 2020/11/13.
//

//#include<stdio.h>
//#include <stdlib.h>
//
//typedef int elementtype;
//
//struct node {
//    elementtype element;
//    struct node *next;
//};
//
//typedef struct node *list;
//
//list init_list() {
//    list l = (list) malloc(sizeof(list));
//    l->next = NULL;
//    return l;
//}
//
//int length(list l) {
//    int len = 0;
//    list next = l;
//    while (next->next != NULL) {
//        next = next->next;
//        len++;
//    }
//    return len;
//};
//
//void insert_by_abs_descending_order(elementtype e, list l) {
//    int i, len = length(l) + 1;
//    list last = l;
//    list add_node = (list) malloc(sizeof(list));
//    add_node->element = e;
//
//    for (i = 0; i < len; i++) {
//        if (last->next == NULL) {
//            add_node->next = NULL;
//            last->next = add_node;
//            break;
//        } else if (abs(last->next->element) <= abs(e)) {
//            if (last->next->element == e) {
//                break;
//            } else if (last->next->element > e && abs(last->next->element) == abs(e)) {
//                last = last->next;
//                i++;
//                if (last->next != NULL && last->next->element == e) {
//                    break;
//                }
//            }
//            add_node->next = last->next;
//            last->next = add_node;
//            break;
//        }
//        last = last->next;
//    }
//};
//
//void print_int_list(list l) {
//    list next = l;
//    while (next->next != NULL) {
//        next = next->next;
//        printf("%d\n", next->element);
//    }
//}
//
//
//int main() {
//    int i;
//    char buf[128];
//    list l = init_list();
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d", &i);
//        insert_by_abs_descending_order(i, l);
//    }
//    print_int_list(l);
//    return 0;
//}


// -----

//#include<stdio.h>
//#include <stdlib.h>
//
//typedef int elementtype;
//
//struct dlnode {
//    elementtype element;
//    struct dlnode *prev, *next;
//};
//
//struct dlnode *init_list() {
//    struct dlnode *d = (struct dlnode *) malloc(sizeof(struct dlnode *));
//    d->next = d;
//    d->prev = d;
//    return d;
//};
//
//void insert(struct dlnode *p, elementtype e) {
//    struct dlnode *last = (struct dlnode *) malloc(sizeof(struct dlnode));
//    last->element = e;
//    last->prev = p->prev;
//    last->next = p;
//    p->prev = last;
//    last->prev->next = last;
//};
//
//void delete(struct dlnode *p) {
//    p->prev->next = p->next;
//    p->next->prev = p->prev;
//    free(p);
//};
//
//void print_dllist(struct dlnode *d) {
//    struct dlnode *next = d;
//    while (next->next != d) {
//        next = next->next;
//        printf("[%d]", next->element);
//    }
//    next = d;
//    while (next->prev != d) {
//        next = next->prev;
//        printf("{%d}", next->element);
//    }
//    printf("\n");
//};
//
//void append_dllist(struct dlnode *d1, struct dlnode *d2) {
//    d2->next->prev = d1->prev;
//    d1->prev->next = d2->next;
//    d2->prev->next = d1;
//    d1->prev = d2->prev;
//    free(d2);
//};
//
//int main() {
//    char buf[128];
//    int i;
//    struct dlnode *d1, *d2;
//    d1 = init_list(), d2 = init_list();
//
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d", &i);
//        insert(d1, i);
//        insert(d2, i);
//    }
//    print_dllist(d1);
//    print_dllist(d2);
//
//    struct dlnode *next = d1;
//    while (next->next != d1) {
//        if (abs(next->next->element % 2) == 1) {
//            delete(next->next);
//        } else {
//            next = next->next;
//        }
//    }
//    next = d2;
//    while (next->next != d2) {
//        if (abs(next->next->element % 2) == 0) {
//            delete(next->next);
//        } else {
//            next = next->next;
//        }
//    }
//    print_dllist(d1);
//    print_dllist(d2);
//
//    append_dllist(d1, d2);
//    print_dllist(d1);
//    return 0;
//}

// ----

//list init_list() {
//    list l = (list) malloc(sizeof(list));
//    l->next = NULL;
//    return l;
//}
//
//void cons(elementtype e, list l) {
//    if (l->next == NULL) {
//        l->element = e;
//        l->next = l;
//        return;
//    }
//    list last = l;
//    while (last->next != l) {
//        last = last->next;
//    }
//    list add_node = (list) malloc(sizeof(list));
//    last->next = add_node;
//    add_node->element = e;
//    add_node->next = l;
//};
//
//
//void print_int_list(list l) {
//    if (l->next == NULL) {
//        return;
//    }
//    list next = l;
//    printf("[%d]", next->element);
//    while (next->next != l) {
//        next = next->next;
//        printf("[%d]", next->element);
//    }
//    printf("\n");
//}
//
//void print_start_with_max_int(list l) {
//    list max = l, next = l;
//    while (next->next != l) {
//        next = next->next;
//        if (max->element <= next->element) {
//            max = next;
//        }
//    }
//    print_int_list(max);
//}
//
//int main() {
//    int i;
//    char buf[128];
//    list l;
//    l = init_list();
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d", &i);
//        cons(i, l);
//    }
//    print_start_with_max_int(l);
//    return 0;
//}

// ----

//void insert(list l, elementtype e) {
//    list insert_list = (list) malloc(sizeof(list));
//    insert_list->element = e;
//    insert_list->next = l->next;
//    l->next = insert_list;
//};
//
//void delete(list l) {
//    if (l->next == NULL) {
//        return;
//    } else {
//        list r;
//        r = l->next->next;
//        free(l->next);
//        l->next = r;
//    }
//};
//
//int length(list l) {
//    int len = 0;
//    if (l->next == NULL) {
//        return len;
//    } else {
//        list next = l->next;
//        len++;
//        while (next->next != NULL) {
//            next = next->next;
//            len++;
//        }
//        return len;
//    }
//};
//
//void print_char_list(list l) {
//    if (l->next == NULL) {
//        return;
//    } else {
//        list next = l->next;
//        printf("%c", next->element);
//        while (next->next != NULL) {
//            next = next->next;
//            printf("%c", next->element);
//        }
//    }
//    printf("\n");
//};
//
//void sort_by_bracket(list l) {
//    int i;
//    list first, last, start, end;
//    first = l->next;
//    last = l;
//    start = l;
//
//    while (start->next != NULL && start != NULL) {
//        if (start->next->element == '(') {
//            end = start->next;
//            while (end->next->element != ')') {
//                if (end->next->element == '['){
//                    start->next = end->next;
//                } else {
//                    end = end->next;
//                }
//            }
//
//            if (start->next == end) {
//                start->next = end->next->next;
//            } else if (start == l) {
//                start->next = start->next->next;
//                end->next = end->next->next;
//                first = end->next;
//                last = end;
//            } else {
//                last->next = start->next->next;
//                start->next = end->next->next;
//                end->next = first;
//                last = end;
//            }
//        } else {
//            start = start->next;
//        }
//    }
//
//    last = l;
//    start = l;
//    for (i = 0; i < length(l); i++) {
//        last = last->next;
//    }
//    while (start->next != NULL && start != NULL) {
//        if (start->next->element == '[') {
//            end = start->next;
//            while (end->next->element != ']') {
//                end = end->next;
//            }
//
//            if (start->next == end) {
//                start->next = end->next->next;
//            } else {
//                last->next = start->next->next;
//                start->next = end->next->next;
//                end->next = NULL;
//                last = end;
//            }
//        } else {
//            start = start->next;
//        }
//    }
//}
//
//void replace_ahead(list last, list first, list start, list end, list l){
//    if (start->next == end) {
//        start->next = end->next->next;
//    } else if (start == l) {
//        start->next = start->next->next;
//        end->next = end->next->next;
//        first = end->next;
//        last = end;
//    } else {
//        last->next = start->next->next;
//        start->next = end->next->next;
//        end->next = first;
//        last = end;
//    }
//}
//
//void replace_rear(list last, list start, list end) {
//    if (start->next == end) {
//        start->next = end->next->next;
//    } else {
//        last->next = start->next->next;
//        start->next = end->next->next;
//        end->next = NULL;
//        last = end;
//    }
//}
//
//int main() {
//    char c, buf[128];
//    int i;
//    list l, r;
//    /* ※ここでリスト l を適切に初期化 */
//    l = (list) malloc(sizeof(list));
//    l->next = NULL;
//    r = l;
//
//    fgets(buf, sizeof(buf), stdin); /* ← 1 行目を buf に読み込み */
//    for (i = 0; (c = buf[i]) != '\n'; ++i) { /* ← 1 文字ずつ処理する for 文 */
//        /* ※ここで c をリスト l の末尾に挿入 */
//        r->next = cons(c, NULL);
//        r = r->next;
//    }
//    /* ※ここでリスト l の中身を出力 */
//    sort_by_bracket(l);
//    print_char_list(l);
//
//    return 0;
//}

// ---

//#include<stdio.h>
//#include <stdlib.h>
//
//typedef char elementtype;
//
//struct node {
//    elementtype element;
//    struct node *next;
//};
//
//typedef struct node *list;
//
//list cons(elementtype e, list l) {
//    if (l == NULL) {
//        l = (list) malloc(sizeof(list));
//        l->element = e;
//        l->next = NULL;
//        return l;
//    } else {
//        list last = (list) malloc(sizeof(list));
//        last->element = e;
//        last->next = l;
//        return last;
//    }
//};
//
//void insert(list l, elementtype e) {
//    list insert_list = (list) malloc(sizeof(list));
//    insert_list->element = e;
//    insert_list->next = l->next;
//    l->next = insert_list;
//};
//
//int length(list l) {
//    int len = 0;
//    if (l->next == NULL) {
//        return len;
//    } else {
//        list next = l->next;
//        len++;
//        while (next->next != NULL) {
//            next = next->next;
//            len++;
//        }
//        return len;
//    }
//};
//
//void print_char_list(list l) {
//    if (l->next == NULL) {
//        return;
//    } else {
//        list next = l->next;
//        printf("%c", next->element);
//        while (next->next != NULL) {
//            next = next->next;
//            printf("%c", next->element);
//        }
//    }
//    printf("\n");
//};
//
//int main() {
//    char c, buf[128];
//    int i;
//    list l, r;
//    /* ※ここでリスト l を適切に初期化 */
//    l = (list) malloc(sizeof(list));
//    l->next = NULL;
//    r = l;
//
//    fgets(buf, sizeof(buf), stdin); /* ← 1 行目を buf に読み込み */
//    for (i = 0; (c = buf[i]) != '\n'; ++i) { /* ← 1 文字ずつ処理する for 文 */
//        /* ※ここで c をリスト l の末尾に挿入 */
//        r->next = cons(c, NULL);
//        r = r->next;
//    }
//    /* ※ここでリスト l の中身を出力 */
//    print_char_list(l);
//
//    while (fgets(buf, sizeof(buf), stdin) != NULL) { /* ← 2 行目以降を順に buf に読み込み */
//        sscanf(buf, "%d %c", &i, &c);
//        /* ※ここでリスト l の i 番目に c を挿入 */
//        if (i <= length(l)) {
//            r = l;
//            for (int j = 0; j < i; j++) {
//                r = r->next;
//            }
//            insert(r, c);
//        } else {
//            r = l;
//            while (r->next != NULL) {
//                r = r->next;
//            }
//            r->next = cons(c, NULL);
//        }
//
//        /* ※ここでリスト l の中身を出力 */
//        print_char_list(l);
//    }
//    return 0;
//}

// ---

//#include<stdio.h>
//#include <stdlib.h>
//
//typedef int elementtype;
//
//struct node {
//    elementtype element;
//    struct node *next;
//};
//
//typedef struct node *list;
//
//list cons(elementtype e, list l) {
//    if (l == NULL) {
//        l = (list) malloc(sizeof(list));
//        l->element = e;
//        l->next = NULL;
//        return l;
//    } else {
//        list last = (list) malloc(sizeof(list));
//        last->element = e;
//        last->next = l;
//        return last;
//    }
//};
//
//int length(list l) {
//    int len = 0;
//    if (l->next == NULL) {
//        return len;
//    } else {
//        list next = l->next;
//        len++;
//        while (next->next != NULL) {
//            next = next->next;
//            len++;
//        }
//        return len;
//    }
//};
//
//void print_int_list(list l) {
//    if (l->next == NULL) {
//        return;
//    } else {
//        list next = l->next;
//        printf("[%d]", next->element);
//        while (next->next != NULL) {
//            next = next->next;
//            printf("[%d]", next->element);
//        }
//    }
//};
//
//int main() {
//    int i;
//    char buf[128];
//    list l, last;
//    /* ここで l を「頭」のある空リストとして適切に初期化する */
//    l = (list)malloc(sizeof(list));
//    l->next = NULL;
//    last = l;
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d", &i);
//        last->next = cons(i, NULL);
//        last = last->next;
//    }
//    printf("length=%d\n", length(l));
//    print_int_list(l);
//    return 0;
//}

// ---

//#include<stdio.h>
//#include <stdlib.h>
//
//typedef int elementtype;
//
//struct node {
//    elementtype element;
//    struct node *next;
//};
//
//typedef struct node *list;
//
//list cons(elementtype e, list l) {
//    if (l == NULL) {
//        l = (list) malloc(sizeof(list));
//        l->element = e;
//        l->next = NULL;
//        return l;
//    } else {
//        list first = (list) malloc(sizeof(list));
//        first->element = e;
//        first->next = l;
//        return first;
//    }
//};
//
//int length(list l) {
//    int len = 0;
//    if (l == NULL) {
//        return len;
//    } else {
//        list next = l->next;
//        len++;
//        while (next != NULL) {
//            next = next->next;
//            len++;
//        }
//        return len;
//    }
//};
//
//void print_int_list(list l) {
//    if (l == NULL) {
//        exit(1);
//    } else {
//        printf("[%d]", l->element);
//        list next = l->next;
//        while (next != NULL) {
//            printf("[%d]", next->element);
//            next = next->next;
//        }
//    }
//};
//
//int main() {
//    int i;
//    char buf[128];
//    list l = NULL;
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d", &i);
//        l = cons(i, l);
//    }
//    printf("length=%d\n", length(l));
//    print_int_list(l);
//    return 0;
//}
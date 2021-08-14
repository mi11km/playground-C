//
// Created by いけやままさふみ on 2021/01/25.
//

/* 1 */
//#include<stdio.h>
//#include<stdlib.h>
//
//char buf[128];
//
//struct student {
//    int id;
//    char name[32];
//    int score;
//};
//typedef struct student datatype;  /* ← 格納するデータは構造体 student */
//struct rb_node {
//    datatype data;
//    struct rb_node *left, *right;
//    int black;
//};
//
//struct rb_node *get_rbtree() {
//    struct rb_node *t;
//    char c;
//    /* ドットだけなら葉 (NULL) を返す */
//    if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.')
//        return NULL;
//    else {
//        /* ドットでなければ節点を表す構造体のアドレス t を用意 */
//        t = (struct rb_node *) malloc(sizeof(struct rb_node));
//        /* 色を表す文字を c に，学籍番号，名前，得点を t->data に格納 */
//        sscanf(buf, "[%c]%d,%[^,],%d", &c, &t->data.id, t->data.name, &t->data.score);
//        /* 色の文字が b なら 1，r なら 0 */
//        t->black = (c == 'b');
//        /* 左の子を t->left に，右の子を t->right に格納 */
//        t->left = get_rbtree();
//        t->right = get_rbtree();
//        /* t を返す */
//        return t;
//    }
//}
//
//struct rb_node *rotate_right(struct rb_node *t) {
//    if (t == NULL || t->left == NULL) return t;
//    struct rb_node *node = t, *pivot = t->left;
//    if (pivot->right != NULL) {
//        node->left = pivot->right;
//    } else {
//        node->left = NULL;
//    }
//    pivot->right = node;
//    return pivot;
//}
//
//struct rb_node *rotate_left(struct rb_node *t) {
//    if (t == NULL || t->right == NULL) return t;
//    struct rb_node *node = t, *pivot = t->right;
//    if (pivot->left != NULL) {
//        node->right = pivot->left;
//    } else {
//        node->right = NULL;
//    }
//    pivot->left = node;
//    return pivot;
//}
//
//void print_rbtree(struct rb_node *t) {
//    if (t == NULL) printf(".\n");
//    else {
//        printf("[%c]%d,%s,%d\n", t->black ? 'b' : 'r', t->data.id, t->data.name, t->data.score);
//        print_rbtree(t->left);
//        print_rbtree(t->right);
//    }
//}
//
//int main() {
//    struct rb_node *t;
//    char c;
//    scanf("%c ", &c);
//    t = get_rbtree();
//    if (c == 'R') t = rotate_right(t);
//    else if (c == 'L') t = rotate_left(t); /* L なら左回転 */
//    print_rbtree(t);
//    return 0;
//}

/* 2 */
//int is_red(struct rb_node *t) {
//    return (t != NULL && !t->black);
//}
//
//int black_node_num(struct rb_node *t) {
//    int num = 0;
//    while (t != NULL) {
//        if (!is_red(t)) num++;
//        t = t->left;
//    }
//    return num;
//}
//
//int is_rbtree(struct rb_node *t) {
//    if (t == NULL) return 1;
//    if (black_node_num(t->left) != black_node_num(t->right)) return 0;
//    if (is_red(t))
//        if (is_red(t->left) || is_red(t->right)) return 0;
//    if (is_rbtree(t->left) && is_rbtree(t->right)) return 1;
//    else return 0;
//}
//
//int main() {
//    struct rb_node *t = get_rbtree();
//    if (is_rbtree(t)) printf("Yes.\n");
//    else printf("No.\n");
//    return 0;
//}

/* 3 */
/* 根の子と孫に現れる赤親子を回転と色変えによって解消し，解消後の根の節点のアドレスを返す関数 */
//struct rb_node *resolve_red_pair(struct rb_node *t) {
//    if (is_red(t->left)) {
//        if (is_red(t->left->left)) {
//            if (is_red(t->right)) {
//                t->black = 0;
//                t->right->black = 1;
//                t->left->black = 1;
//                return t;
//            }
//            t->black = 0;
//            t->left->black = 1;
//            t = rotate_right(t);
//        } else if (is_red(t->left->right)) {
//            if (is_red(t->right)) {
//                t->black = 0;
//                t->right->black = 1;
//                t->left->black = 1;
//                return t;
//            }
//            t->left = rotate_left(t->left);
//            t->black = 0;
//            t->left->black = 1;
//            t = rotate_right(t);
//        }
//    }
//    if (is_red(t->right)) {
//        if (is_red(t->right->left)) {
//            if (is_red(t->left)) {
//                t->black = 0;
//                t->right->black = 1;
//                t->left->black = 1;
//                return t;
//            }
//            t->right = rotate_right(t->right);
//            t->black = 0;
//            t->right->black = 1;
//            t = rotate_left(t);
//        } else if (is_red(t->right->right)) {
//            if (is_red(t->left)) {
//                t->black = 0;
//                t->right->black = 1;
//                t->left->black = 1;
//                return t;
//            }
//            t->black = 0;
//            t->right->black = 1;
//            t = rotate_left(t);
//        }
//    }
//    return t;
//}
//
//int main() {
//    struct rb_node *t = get_rbtree();
//    t = resolve_red_pair(t);
//    print_rbtree(t);
//    return 0;
//}

/* 4 */
//struct rb_node *rb_insert_rec(struct rb_node *t, struct student d) {
//    if (t == NULL) {
//        t = (struct rb_node *) malloc(sizeof(struct rb_node));
//        t->left = NULL;
//        t->right = NULL;
//        t->data = d;
//        t->black = 0;
//        return t;
//    } else {
//        if (t->data.id > d.id) {
//            t->left = rb_insert_rec(t->left, d);
//        } else {
//            t->right = rb_insert_rec(t->right, d);
//        }
//        t = resolve_red_pair(t);
//        return t;
//    }
//}
//
//struct rb_node *rb_insert(struct rb_node *t, struct student d) {
//    t = rb_insert_rec(t, d);
//    t->black = 1;
//    return t;
//}
//
//int main() {
//    struct student d;
//    struct rb_node *t = NULL; /* 葉のみの赤黒木を用意 */
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d,%[^,],%d", &d.id, d.name, &d.score); /* 学生の番号を読取り */
//        t = rb_insert(t, d);                             /* そのデータを赤黒木に追加 */
//    }
//    print_rbtree(t);
//    return 0;
//}

/* 5 */
//struct rb_node *rb_update_rec(struct rb_node *t, struct student d) {
//    if (t == NULL) {
//        t = (struct rb_node *) malloc(sizeof(struct rb_node));
//        t->left = NULL;
//        t->right = NULL;
//        t->data = d;
//        t->black = 0;
//        return t;
//    } else {
//        if (t->data.id == d.id) {
//            t->data.score += d.score;
//            return t;
//        } else if (t->data.id > d.id) {
//            t->left = rb_update_rec(t->left, d);
//        } else {
//            t->right = rb_update_rec(t->right, d);
//        }
//        t = resolve_red_pair(t);
//        return t;
//    }
//}
//
//struct rb_node *rb_update(struct rb_node *t, struct student d) {
//    t = rb_update_rec(t, d);
//    t->black = 1;
//    return t;
//};
//
//int main() {
//    struct student d;
//    struct rb_node *t = NULL; /* 葉のみの赤黒木を用意 */
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d,%[^,],%d", &d.id, d.name, &d.score); /* 学生の番号を読取り */
//        t = rb_update(t, d);                                 /* そのデータで赤黒木を更新 */
//    }
//    print_rbtree(t);
//    return 0;
//}

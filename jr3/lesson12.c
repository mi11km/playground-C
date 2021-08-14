//
// Created by いけやままさふみ on 2021/01/19.
//

/*1*/
//#include<stdio.h>
//#include<stdlib.h>
//
//char buf[128]; /* 関数 get_avl で用いるグローバル変数 */
//struct student {
//    int id;
//    char name[32];
//    int score;
//};
//typedef struct student datatype; /* ← 格納するデータは構造体 student */
//struct avl_node {
//    datatype data;
//    struct avl_node *left, *right;
//    int height;
//};
//
//struct avl_node *get_avl() {
//    struct avl_node *t;
//    /* ドットだけなら葉 (NULL) を返す */
//    if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.')
//        return NULL;
//    else {
//        /* ドットでなければ節点を表す構造体のアドレス t を用意 */
//        t = (struct avl_node *) malloc(sizeof(struct avl_node));
//        /* 高さを t->height に，学籍番号，名前，得点を t->data に格納 */
//        sscanf(buf, "[%d]%d,%[^,],%d", &t->height, &t->data.id, t->data.name, &t->data.score);
//        /* 左の子を t->left に，右の子を t->right に格納 */
//        t->left = get_avl();
//        t->right = get_avl();
//        /* t を返す */
//        return t;
//    }
//}
//
//int height(struct avl_node *t) {
//    if (t == NULL) {
//        return 0;
//    } else {
//        int right_h = height(t->right);
//        int left_h = height(t->left);
//        if (right_h > left_h) return 1 + right_h;
//        else return 1 + left_h;
//    }
//};
//
//void put_height(struct avl_node *t) {
//    if (t != NULL) {
//        t->height = height(t);
//        put_height(t->right);
//        put_height(t->left);
//    }
//};
//
//struct avl_node *rotate_right(struct avl_node *t) {
//    if (t == NULL || t->left == NULL) return t;
//    struct avl_node *node = t, *pivot = t->left;
//    if (pivot->right != NULL) {
//        node->left = pivot->right;
//    } else {
//        node->left = NULL;
//    }
//    pivot->right = node;
//    put_height(pivot);
//    return pivot;
//}
//
//struct avl_node *rotate_left(struct avl_node *t) {
//    if (t == NULL || t->right == NULL) return t;
//    struct avl_node *node = t, *pivot = t->right;
//    if (pivot->left != NULL) {
//        node->right = pivot->left;
//    } else {
//        node->right = NULL;
//    }
//    pivot->left = node;
//    put_height(pivot);
//    return pivot;
//}
//
//void print_avl(struct avl_node *t) {
//    if (t == NULL)
//        printf(".\n");
//    else {
//        printf("[%d]%d,%s,%d\n", t->height, t->data.id, t->data.name, t->data.score);
//        print_avl(t->left);
//        print_avl(t->right);
//    }
//}
//
//int main() {
//    struct avl_node *t;
//    char c;
//    scanf("%c ", &c);
//    t = get_avl();
//    if (c == 'R')
//        t = rotate_right(t);
//    else if (c == 'L')
//        t = rotate_left(t);
//    print_avl(t);
//    return 0;
//}
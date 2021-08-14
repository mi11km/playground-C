//
// Created by いけやままさふみ on 2021/01/12.
//

/*1*/
//#include<stdio.h>
//#include<stdlib.h>
//
//char buf[128]; /* 関数 get_tree で用いるグローバル変数 */
//
//typedef int datatype;
//struct node {
//    datatype data;
//    struct node *left, *right;
//};
//
//struct node *get_tree() {
//    struct node *t;
//    /* 標準入力から buf に文字列を読み込み，先頭が . なら葉とみなして NULL を返す */
//    if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.')
//        return NULL;
//    else {
//        /* 先頭が . 以外なら，節点のためのメモリを確保 */
//        t = (struct node *) malloc(sizeof(struct node));
//        sscanf(buf, "%d ", &t->data); /* buf から数値として読み込み，メンバ data に保存 */
//        t->left = get_tree(); /* 以降の入力で，左の子の節点から下の木を生成 */
//        t->right = get_tree(); /* 左の木が生成できたら，右の子の節点から下の木を生成 */
//        return t;
//    }
//}
//
//void print_tree(struct node *t) {
//    if (t == NULL) {
//        printf("-");
//        return;
//    } else {
//        printf("%d", t->data);
//        printf("(");
//        print_tree(t->left);
//        printf(",");
//        print_tree(t->right);
//        printf(")");
//    }
//}
//
//int main() {
//    struct node *t = get_tree();
//    print_tree(t);
//    printf("\n");
//    return 0;
//}

/*2*/
//int size(struct node *t) {
//    if (t == NULL) {
//        return 0;
//    } else {
//        return 1 + size(t->left) + size(t->right);
//    }
//}
//
//int height(struct node *t) {
//    if (t == NULL) {
//        return 0;
//    } else {
//        int right_h = height(t->right);
//        int left_h = height(t->left);
//        if (right_h > left_h) return 1 + right_h;
//        else return 1 + left_h;
//    }
//}
//
//int sum(struct node *t) {
//    if (t == NULL) {
//        return 0;
//    } else {
//        return t->data + sum(t->left) + sum(t->right);
//    }
//}

/*3*/
//void print_preorder(struct node *t) {
//    if (t == NULL){
//        return;
//    } else {
//        printf("%c", t->data);
//        print_preorder(t->left);
//        print_preorder(t->right);
//    }
//}
//
//void print_inorder(struct node *t) {
//    if (t == NULL){
//        return;
//    } else {
//        print_inorder(t->left);
//        printf("%c", t->data);
//        print_inorder(t->right);
//    }
//}
//
//void print_postorder(struct node *t) {
//    if (t == NULL){
//        return;
//    } else {
//        print_postorder(t->left);
//        print_postorder(t->right);
//        printf("%c", t->data);
//    }
//}

/*4*/
//#include<stdio.h>
//#include<stdlib.h>
//
//char buf[128]; /* 関数 get_tree で用いるグローバル変数 */
//
//struct student {
//    int id;
//    char name[32];
//    int score;
//};
//typedef struct student datatype; /* ← 格納するデータは構造体 student */
//struct node {
//    datatype data;
//    struct node *left, *right;
//};
//
///* 葉を含む行きがけ順で表現された文字列を二分木に変換 */
//struct node *get_tree() {
//    struct node *t;
//    if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.')
//        return NULL;
//    else {
//        t = (struct node *) malloc(sizeof(struct node));
//        sscanf(buf, "%d,%[^,],%d", &t->data.id, t->data.name, &t->data.score);
//        t->left = get_tree();
//        t->right = get_tree();
//        return t;
//    }
//}
//
//void find_info(struct node *t, int id) {
//    while (t != NULL) {
//        if (t->data.id > id) {
//            t = t->left;
//        } else if (t->data.id < id) {
//            t = t->right;
//        } else if (t->data.id == id){
//            printf("%s,%d\n", t->data.name, t->data.score);
//            return;
//        }
//    }
//    printf("Not found.\n");
//}
//
//int main() {
//    int id;
//    struct node *t = get_tree();
//    scanf("%d ", &id);
//    find_info(t, id);
//    return 0;
//}

/*5*/
//#include<stdio.h>
//#include<stdlib.h>
//
//char buf[128]; /* 関数 get_tree で用いるグローバル変数 */
//
//struct student {
//    int id;
//    char name[32];
//    int score;
//};
//typedef struct student datatype; /* ← 格納するデータは構造体 student */
//struct node {
//    datatype data;
//    struct node *left, *right;
//};
//
///* 葉を含む行きがけ順で表現された文字列を二分木に変換 */
//struct node *get_tree() {
//    struct node *t;
//    if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.')
//        return NULL;
//    else {
//        t = (struct node *) malloc(sizeof(struct node));
//        sscanf(buf, "%d,%[^,],%d", &t->data.id, t->data.name, &t->data.score);
//        t->left = get_tree();
//        t->right = get_tree();
//        return t;
//    }
//}
//
//struct node *bst_insert(struct node *t, struct student d) {
//    struct node *end = (struct node *) malloc(sizeof(struct node));
//    end->data = d;
//    end->right = NULL;
//    end->left = NULL;
//    if (t == NULL) {
//        t = end;
//    } else {
//        struct node *parent, *tree = t;
//        while (tree != NULL) {
//            parent = tree;
//            if (tree->data.id > d.id) {
//                tree = tree->left;
//            } else if (tree->data.id < d.id) {
//                tree = tree->right;
//            }
//        }
//        if (parent->data.id > end->data.id) {
//            parent->left = end;
//        } else {
//            parent->right = end;
//        }
//    }
//    return t;
//}
//
//void print_bst(struct node *t) {
//    if (t == NULL) {
//        printf(".\n");
//        return;
//    } else {
//        printf("%d,%s,%d\n", t->data.id, t->data.name, t->data.score);
//        print_bst(t->left);
//        print_bst(t->right);
//    }
//}
//
//int main() {
//    struct node *t = get_tree();
//    struct student d;
//    scanf("%d,%[^,],%d ", &d.id, d.name, &d.score);
//    t = bst_insert(t, d);
//    print_bst(t);
//    return 0;
//}
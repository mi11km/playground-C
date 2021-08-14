//
// Created by いけやままさふみ on 2021/01/05.
//

/* 1 */
//#include <stdio.h>
//
//struct student {
//    int id;
//    char name[32];
//    int score;
//};
//
//int main() {
//    int i = 0, n, v;
//    char buf[128], c;
//    struct student st[1024];
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 1024) {
//        sscanf(buf, "%d%c", &v, &c);
//        if (c == ',') {
//            st[i].id = v;
//            sscanf(buf, "%*d,%[^,],%d", st[i].name, &st[i].score);
//            ++i;
//        }
//    }
//    n = i;
//    /* この時点で v に探索すべき得点が入っていて，n が読み込んだ要素の数である */
//    st[n].score = v;
//    i = 0;
//    while (st[i].score != v) {
//        i++;
//    }
//    if (i == n) {
//        printf("Not found.\n");
//    } else if (i < n) {
//        printf("%d,%s\n", st[i].id, st[i].name);
//    }
//    /* for 文や while 文において i<n のような添字による終了判定をしないこと */
//    return 0;
//}

/* 2 */
//#include <stdio.h>
//
//int count = 0; /* 関数 binary_search を呼んだ回数 */
//
//struct student {
//    int id;
//    char name[32];
//    int score;
//};
//
//int binary_search(struct student st[], int id, int l, int r) {
//    ++count;
//    /* ※ここを適切なプログラムで埋める */
//    if (r < l) {
//        return -1;
//    } else {
//        int m = l + (r - l) / 2;
//        if (st[m].id == id) {
//            return m;
//        } else if (st[m].id < id) {
//            return binary_search(st, id, m + 1, r);
//        } else {
//            return binary_search(st, id, l, m - 1);
//        }
//    }
//}
//
//int main() {
//    int i = 0, n, v;
//    char buf[128], c;
//    struct student st[1024];
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 1024) {
//        sscanf(buf, "%d%c", &v, &c);
//        if (c == ',') {
//            st[i].id = v;
//            sscanf(buf, "%*d,%[^,],%d", st[i].name, &st[i].score);
//            ++i;
//        }
//    }
//    n = i;
//    /* この時点で v に探索すべき学籍番号が入っていて，n が読み込んだ要素の数である */
//    i = binary_search(st, v, 0, n - 1);
//    if (i < 0) printf("Not found.\n");
//    else printf("%s,%d\n", st[i].name, st[i].score);
//    printf("%d\n", count);
//    return 0;
//}

/* 3 */
//#include<stdio.h>
//#define SIZE 101
//
//int hash(char *s) {
//    int i = 1;
//    int s_i = ((int) s[0]) % SIZE;
//    while (s[i] != '\0') {
//        s_i = (s_i * 128 + ((int)s[i])) % SIZE;
//        i++;
//    }
//    return s_i;
//}
//
//int main() {
//    char s[32];
//    scanf("%[^\n]", s);
//    printf("%d\n", hash(s));
//    return 0;
//}

/* 4 */
//#include<stdio.h>
//#include<stdlib.h>
//#define SIZE 101
//
//struct student {
//    int id;
//    char name[32];
//    int score;
//};
//
//struct node {
//    struct student data;
//    struct node *next;
//};
//
//int hash(char *s) {
//    int i = 1;
//    int s_i = ((int) s[0]) % SIZE;
//    while (s[i] != '\0') {
//        s_i = (s_i * 128 + ((int) s[i])) % SIZE;
//        i++;
//    }
//    return s_i;
//}
//
//void set_data(struct node *table[], struct student st) {
//    /* ※ここを適切なプログラムで埋める */
//    int i = hash(st.name);
//    struct node *p = table[i], *new = malloc(sizeof(struct node));
//    new->data = st;
//    new->next = p;
//    table[i] = new;
//}
//
//int main() {
//    int i;
//    char buf[128];
//    struct student st;
//    struct node *table[SIZE], *p;
//    /* ハッシュ表の配列の各要素を NULL で初期化 */
//    for (i = 0; i < SIZE; ++i) table[i] = NULL;
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d,%[^,],%d", &st.id, st.name, &st.score);
//        set_data(table, st);
//    }
//    for (i = 0; i < SIZE; ++i) {
//        p = table[i];
//        while (p != NULL) {
//            /* ハッシュ表に st を登録 */
//            st = p->data;
//            printf("(%d)%d,%s,%d\n", i, st.id, st.name, st.score);
//            p = p->next;
//        }
//    }
//    return 0;
//}

/* 5 */
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h> /* 関数 strcmp を使うために必要 */
//
//#define SIZE 101
//
//struct student {
//    int id;
//    char name[32];
//    int score;
//};
//
//struct node {
//    struct student data;
//    struct node *next;
//};
//
//int hash(char *s) {
//    int i = 1;
//    int s_i = ((int) s[0]) % SIZE;
//    while (s[i] != '\0') {
//        s_i = (s_i * 128 + ((int) s[i])) % SIZE;
//        i++;
//    }
//    return s_i;
//}
//
//void set_data(struct node *table[], struct student st) {
//    int i = hash(st.name);
//    struct node *p = table[i], *new = malloc(sizeof(struct node));
//    new->data = st;
//    new->next = p;
//    table[i] = new;
//}
//
//int find_score(struct node *table[], char *s) {
//    int i = hash(s);
//    struct node *p = table[i];
//    while (p != NULL) {
//        if (strcmp(p->data.name, s) == 0) {
//            return p->data.score;
//        }
//        p = p->next;
//    }
//    return -1;
//}
//
//int main() {
//    int i, v;
//    char buf[128], name[32];
//    struct student st;
//    struct node *table[SIZE];
//
//    for (i = 0; i < SIZE; ++i) table[i] = NULL;
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d,", &v);
//        /* 各行の最初の数値によって分岐 */
//        if (v > 0) {
//            sscanf(buf, "%d,%[^,],%d", &st.id, st.name, &st.score);
//            set_data(table, st);
//        } else
//            sscanf(buf, "0,%[^,\n]", name);
//    }
//    v = find_score(table, name);
//    if (v < 0) printf("Not found.\n");
//    else printf("%d\n", v);
//    return 0;
//}

/* 6 */
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h> /* 関数 strcmp を使うために必要 */
//
//#define SIZE 101
//
//struct student {
//    char name[32];
//    int score;
//};
//
//struct node {
//    struct student data;
//    struct node *next;
//};
//
//int hash(char *s) {
//    int i = 1;
//    int s_i = ((int) s[0]) % SIZE;
//    while (s[i] != '\0') {
//        s_i = (s_i * 128 + ((int) s[i])) % SIZE;
//        i++;
//    }
//    return s_i;
//}
//
//void set_data(struct node *table[], struct student st) {
//    int i = hash(st.name);
//    struct node *p = table[i];
//
//    if (p == NULL) {
//        struct node *new = malloc(sizeof(struct node));
//        new->data = st;
//        new->next = NULL;
//        table[i] = new;
//        return;
//    }
//
//    if (strcmp(p->data.name, st.name) == 0) {
//        p->data.score += st.score;
//        return;
//    }
//    while (p->next != NULL) {
//        p = p->next;
//        if (strcmp(p->data.name, st.name) == 0) {
//            p->data.score += st.score;
//            return;
//        }
//    }
//
//    struct node *new = malloc(sizeof(struct node));
//    new->data = st;
//    new->next = NULL;
//    p->next = new;
//}
//
//int main() {
//    int i;
//    char buf[128];
//    struct student st;
//    struct node *table[SIZE], *p;
//
//    for (i = 0; i < SIZE; ++i) table[i] = NULL;
//
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%[^,],%d", st.name, &st.score);
//        set_data(table, st);
//    }
//
//    for (i = 0; i < SIZE; ++i) {
//        p = table[i];
//        while (p != NULL) {
//            st = p->data;
//            printf("%s,%d\n", st.name, st.score);
//            p = p->next;
//        }
//    }
//    return 0;
//}

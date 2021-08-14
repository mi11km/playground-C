//
// Created by いけやままさふみ on 2021/02/05.
//

/* 7 */
// 5のメインだけ変える！
//int main() {
//    int eki, eki1, eki2, rosen, ekisu, i, kyori;
//    FILE *fp = fopen(ROSENZU, "r"); /* 路線図ファイルの読取り開始 */
//    fscanf(fp, "%d ", &ekisu);           /* 1行目の駅数を読取り */
//    struct node *adjlist[ekisu];
//    /* 隣接リスト表現を初期化.すべての頂点に対する隣接リストを空にする */
//    for (i = 0; i < ekisu; ++i) adjlist[i] = NULL;
//    while (fgets(buf, sizeof(buf), fp) != NULL) {
//        /* 隣り合う駅の情報を読取り */
//        sscanf(buf, "%d:%d:%d:%d ", &eki1, &eki2, &rosen, &kyori);
//        /* そのデータを隣接リスト表現のグラフに追加 */
//        add_edge(adjlist, eki1, eki2, rosen, kyori);
//    }
//    fclose(fp); /* 路線図ファイルの読取り終了 */
//
//    /* 駅名ファイル ekisen.txt を読み取る */
//    char *ekiname[SETMAX], *senname[SETMAX], *ename, *sname;
//    fp = fopen("./ekisen.txt","r");
//    while(fgets(buf,sizeof(buf),fp)!=NULL) {
//        ename = (char*) malloc(sizeof(char)*64);
//        sname = (char*) malloc(sizeof(char)*128);
//        sscanf(buf, "%[^:]:%d:%[^\n]*c", ename, &eki, sname);
//        ekiname[eki] = ename;
//        senname[eki] = sname;
//    }
//    fclose(fp);
//
//    scanf("%d %d ", &eki1, &eki2);
//    kyori = dijkstra_path(adjlist, eki1, eki2, ekisu);
//    /* 最短距離を出力 */
//    printf("%d:", kyori);
//    eki = eki2;
//    /* hop[eki]の数だけ前に戻って出力 */
//    for (i = 0; i < hop[eki2]; ++i) {
//        printf(" %s (%s) <-", ekiname[eki], senname[eki]);
//        eki = prev[eki];       /* さらに 1つ手前の駅へ */
//    }
//    /*プログラムが正しければ，ここでekiが開始駅eki1なっているはず(違っていたら異常終了)*/
//    if (eki != eki1) {
//        fprintf(stderr, "hop or prev is invalid.\n");
//        exit(1);
//    }
//    printf(" %s (%s)\n", ekiname[eki], senname[eki]); /* 出発駅の出力 */
//    return 0;
//}

/* 6 */
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define SETMAX 10600
//char buf[256];
//
//struct station {
//    int eki;
//    char name[64], rosen[64];
//};
//
//int main() {
//    int i = 0, ekisize, l, r, m;
//    struct station *ekidata[SETMAX], *st;
//    char ekiname[64];
//    FILE *fp = fopen("./ekisen.txt", "r");
//    while (fgets(buf, sizeof(buf), fp) != NULL && i < SETMAX) {
//        st = (struct station *) malloc(sizeof(struct station));
//        sscanf(buf, "%[^:]:%d:%[^\n]*c", st->name, &st->eki, st->rosen);
//        ekidata[i] = st;
//        ++i;
//    }
//    fclose(fp);
//    ekisize = i;
//    scanf("%[^\n]%*c", ekiname);
//    l = 0;
//    r = ekisize - 1;
//    /* ここから二分探索 */
//    while (l <= r) {
//        m = l + (r - l) / 2;
//        if (strcmp(ekidata[m]->name, ekiname) == 0) {
//            break;
//        } else if (strcmp(ekidata[m]->name, ekiname) < 0) {
//            l = m + 1;
//        } else {
//            r = m - 1;
//        }
//    }
//    if (r < l) { /* 駅名がない場合 */
//        fprintf(stderr, "%s: 駅名がありません\n", ekiname);
//        exit(1);
//    } else { /* 駅名がある場合 */
//        /* ※ここも適切なプログラムで埋める */
//        while (strcmp(ekidata[m]->name, ekiname) == 0) {
//            m--;
//        }
//        m++;
//        while (strcmp(ekidata[m]->name, ekiname) == 0) {
//            printf("%d:%s\n", ekidata[m]->eki, ekidata[m]->rosen);
//            m++;
//        }
//    }
//    return 0;
//}

/* 5 */
//int prev[SETMAX];             /* 各駅までの最短経路における 1つ前の駅を格納するグローバル変数 */
//int hop[SETMAX];              /* 各駅までの最短経路における駅の数を格納するグローバル変数 */
//
//int delete_min(struct set *p) {
//    if (p->size == 0) return -1;
//
//    int i, min_index = 0, min_element;
//    for (i = 0; i < p->size; ++i) {
//        if (dist[p->elements[min_index]] > dist[p->elements[i]]) {
//            min_index = i;
//        } else if (dist[p->elements[min_index]] == dist[p->elements[i]]) {
//            if (hop[p->elements[min_index]] > hop[p->elements[i]]) {
//                min_index = i;
//            } else if (hop[p->elements[min_index]] == hop[p->elements[i]]) {
//                if (prev[p->elements[min_index]] > prev[p->elements[i]]) {
//                    min_index = i;
//                }
//            }
//        }
//    }
//    min_element = p->elements[min_index];
//    p->elements[min_index] = p->elements[p->size - 1];
//    p->size--;
//    return min_element;
//}
//
//int dijkstra_path(struct node *adjlist[], int eki1, int eki2, int ekisu) {
//    for (int i = 0; i < ekisu; ++i) {
//        if (i == eki1) {
//            dist[i] = 0;
//            hop[i] = 0;
//        } else {
//            dist[i] = INT_MAX;
//            hop[i] = INT_MAX;
//        }
//    }
//
//    int cur = eki1;  /* 直前に最短距離を確定した駅を格納する変数 */
//    struct set *unknown = (struct set *) malloc(sizeof(struct set));  /* 0 から ekisu−1 までのうち eki1 を除くすべての整数が入った集合 */
//    init_set(unknown, ekisu, eki1);
//
//    struct node *adj_eki;
//    while (unknown->size != 0 && cur != eki2) {
//        adj_eki = adjlist[cur];
//        while (adj_eki != NULL) {
//            if (dist[adj_eki->eki] > (dist[cur] + adj_eki->kyori)) {
//                dist[adj_eki->eki] = dist[cur] + adj_eki->kyori;
//                hop[adj_eki->eki] = hop[cur] + 1;
//                prev[adj_eki->eki] = cur;
//            } else if (dist[adj_eki->eki] == (dist[cur] + adj_eki->kyori)) {
//                if (hop[adj_eki->eki] > hop[cur] + 1) {
//                    dist[adj_eki->eki] = dist[cur] + adj_eki->kyori;
//                    hop[adj_eki->eki] = hop[cur] + 1;
//                    prev[adj_eki->eki] = cur;
//                } else if (hop[adj_eki->eki] == hop[cur] + 1) {
//                    if (prev[adj_eki->eki] > cur) {
//                        dist[adj_eki->eki] = dist[cur] + adj_eki->kyori;
//                        hop[adj_eki->eki] = hop[cur] + 1;
//                        prev[adj_eki->eki] = cur;
//                    }
//                }
//            }
//            adj_eki = adj_eki->next;
//        }
//        cur = delete_min(unknown);
//    }
//
//    return dist[eki2];
//}
//
//int main() {
//    int eki, eki1, eki2, rosen, ekisu, i, kyori;
//    FILE *fp = fopen(ROSENZU, "r"); /* 路線図ファイルの読取り開始 */
//    fscanf(fp, "%d ", &ekisu);           /* 1行目の駅数を読取り */
//    struct node *adjlist[ekisu];
//    /* 隣接リスト表現を初期化.すべての頂点に対する隣接リストを空にする */
//    for (i = 0; i < ekisu; ++i) adjlist[i] = NULL;
//    while (fgets(buf, sizeof(buf), fp) != NULL) {
//        /* 隣り合う駅の情報を読取り */
//        sscanf(buf, "%d:%d:%d:%d ", &eki1, &eki2, &rosen, &kyori);
//        /* そのデータを隣接リスト表現のグラフに追加 */
//        add_edge(adjlist, eki1, eki2, rosen, kyori);
//    }
//    fclose(fp); /* 路線図ファイルの読取り終了 */
//    scanf("%d %d ", &eki1, &eki2);
//    kyori = dijkstra_path(adjlist, eki1, eki2, ekisu);
//    /* 最短距離を出力 */
//    printf("%d:", kyori);
//    eki = eki2;
//    /* hop[eki]の数だけ前に戻って出力 */
//    for (i = 0; i < hop[eki2]; ++i) {
//        printf(" %d <-", eki); /* 1つ手前の駅を出力 */
//        eki = prev[eki];       /* さらに 1つ手前の駅へ */
//    }
//    /*プログラムが正しければ，ここでekiが開始駅eki1なっているはず(違っていたら異常終了)*/
//    if (eki != eki1) {
//        fprintf(stderr, "hop or prev is invalid.\n");
//        exit(1);
//    }
//    printf(" %d\n", eki); /* 開始駅を出力 */
//    return 0;
//}


/* 4 */
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//#define ROSENZU "rosenzu.txt" /* 路線図データファイル */
//#define SETMAX 10600          /* 集合の要素数の最大値 (駅の数) */
//char buf[256];                /* 入力された文字列を格納するグローバル変数 */
//int dist[SETMAX];             /* 指定された駅から各駅までの最短距離を格納するグローバル変数 */
//
//struct node {
//    int eki, rosen, kyori;
//    struct node *next;
//};
//struct set {
//    int elements[SETMAX];
//    int size;
//};
//
//void init_set(struct set *p, int n, int e) {
//    int i, element = 0;
//    for (i = 0; i < n; ++i) {
//        if (i == e) element++;
//        p->elements[i] = element;
//        element++;
//    }
//    p->size = n - 1;
//}
//
//int delete_min(struct set *p) {
//    if (p->size == 0) return -1;
//
//    int i, min_index = 0, min_element;
//    for (i = 0; i < p->size; ++i) {
//        if (dist[p->elements[min_index]] > dist[p->elements[i]]) {
//            min_index = i;
//        }
//    }
//    min_element = p->elements[min_index];
//    p->elements[min_index] = p->elements[p->size - 1];
//    p->size--;
//    return min_element;
//}
//
//void add_edge(struct node *adjlist[], int eki1, int eki2, int rosen, int kyori) {
//    struct node *eki1_node = (struct node *) malloc(sizeof(struct node)),
//            *eki2_node = (struct node *) malloc(sizeof(struct node));
//    eki1_node->eki = eki1;
//    eki1_node->rosen = rosen;
//    eki1_node->kyori = kyori;
//    eki1_node->next = adjlist[eki2];
//    adjlist[eki2] = eki1_node;
//
//    eki2_node->eki = eki2;
//    eki2_node->rosen = rosen;
//    eki2_node->kyori = kyori;
//    eki2_node->next = adjlist[eki1];
//    adjlist[eki1] = eki2_node;
//}
//
//int dijkstra(struct node *adjlist[], int eki1, int eki2, int ekisu) {
//    for (int i = 0; i < ekisu; ++i) {
//        if (i == eki1) dist[i] = 0;
//        else dist[i] = INT_MAX;
//    }
//
//    int cur = eki1;  /* 直前に最短距離を確定した駅を格納する変数 */
//    struct set *unknown = (struct set *) malloc(sizeof(struct set));  /* 0 から ekisu−1 までのうち eki1 を除くすべての整数が入った集合 */
//    init_set(unknown, ekisu, eki1);
//
//    struct node *adj_eki;
//    while (unknown->size != 0 && cur != eki2) {
//        adj_eki = adjlist[cur];
//        while (adj_eki != NULL) {
//            if (dist[adj_eki->eki] > (dist[cur] + adj_eki->kyori)) {
//                dist[adj_eki->eki] = dist[cur] + adj_eki->kyori;
//            }
//            adj_eki = adj_eki->next;
//        }
//        cur = delete_min(unknown);
//    }
//
//    return dist[eki2];
//}
//
//int main() {
//    int eki1, eki2, rosen, ekisu, i, kyori;
//    FILE *fp = fopen(ROSENZU, "r");     /* 路線図ファイルを読む準備 */
//    fscanf(fp, "%d ", &ekisu);               /* 1行目の駅数を読取り */
//    struct node *adjlist[ekisu];
//    for (i = 0; i < ekisu; ++i) adjlist[i] = NULL;  /* 隣接リスト表現を初期化.すべての頂点に対する隣接リストを空にする */
//    while (fgets(buf, sizeof(buf), fp) != NULL) {
//        sscanf(buf, "%d:%d:%d:%d ", &eki1, &eki2, &rosen, &kyori);  /* 隣り合う駅の情報を読取り */
//        add_edge(adjlist, eki1, eki2, rosen, kyori);  /* そのデータを隣接リスト表現のグラフに追加 */
//    }
//    fclose(fp);
//    scanf("%d %d ", &eki1, &eki2);
//    printf("%d\n", dijkstra(adjlist, eki1, eki2, ekisu));
//    /* for(i=0;i<ekisu;++i)
//        if(dist[i] < INT_MAX)
//            printf("%d: %d\n", i, dist[i]); */
//    return 0;
//}


/* 3 */
//int delete_min(struct set *p) {
//    if (p->size == 0) return -1;
//
//    int i, min_index = 0, min_element;
//    for (i = 0; i < p->size; ++i) {
//        if (dist[p->elements[min_index]] > dist[p->elements[i]]){
//            min_index = i;
//        }
//    }
//    min_element = p->elements[min_index];
//    p->elements[min_index] = p->elements[p->size - 1];
//    p->size--;
//    return min_element;
//}


/* 2 */
//int delete_min_int(struct set *p) {
//    if (p->size == 0) return -1;
//
//    int i, min_index = 0, min_element;
//    for (i = 0; i < p->size; ++i) {
//        if (p->elements[min_index] > p->elements[i]) {
//            min_index = i;
//        }
//    }
//    min_element = p->elements[min_index];
//    p->elements[min_index] = p->elements[p->size - 1];
//    p->size--;
//    return min_element;
//}
//
//int main() {
//    int i, m;
//    struct set s; /* 入力される整数値を格納する集合 */
//    i = 0;        /* 添字 0 から格納していく */
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d ", &s.elements[i]); /* 入力された整数値を集合 s に格納 */
//        ++i;                                /* 添字を 1 つ増やす */
//    }
//    s.size = i;  /* ← この時点で i に要素の数が格納されているはず */
//    while (1) {
//        m = delete_min_int(&s);
//        if (m < 0) break;    /* m が負なら集合が空なので終了 */
//        printf("%d : ", m);
//        print_set(&s);       /* 最小値と集合を出力 */
//    }
//    return 0;
//}

/* 1 */
//#include <stdio.h>
//
//#define SETMAX 10600 /* 集合の要素数の最大値 (駅の数) */
//
//struct set {
//    int elements[SETMAX];
//    int size;
//};
//
//void init_set(struct set *p, int n, int e) {
//    int i, element = 0;
//    for (i = 0; i < n; ++i) {
//        if (i == e) element++;
//        p->elements[i] = element;
//        element++;
//    }
//    p->size = n - 1;
//}
//
//void print_set(struct set *p) {
//    int i;
//    printf("{");
//    for (i = 0; i < p->size; ++i) printf(" %d", p->elements[i]);
//    printf(" }\n");
//}
//
//int main() {
//    int n, e;
//    struct set s;            /* 集合 s を用意 */
//    scanf("%d %d ", &n, &e); /* 入力から n と e を読み込み */
//    init_set(&s, n, e);      /* s のアドレスと n と e を渡す */
//    print_set(&s);
//    return 0;
//}


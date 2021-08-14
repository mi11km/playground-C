//
// Created by いけやままさふみ on 2021/02/02.
//

/* 1 */
//#include <stdio.h>
//#include <stdlib.h>
//
//char buf[256];
//
//struct node {
//    int eki, rosen;
//    float kyori;
//    struct node *next;
//};
//
//void add_edge(struct node *adjlist[], int eki1, int eki2, int rosen, float kyori) {
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
///* 頂点数 n の隣接リスト表現を表示する関数 */
//void print_adjlist(struct node *adjlist[], int n) {
//    int i;
//    struct node *p;
//    for (i = 0; i < n; ++i) {
//        printf("%d:", i);
//        p = adjlist[i];
//        while (p != NULL) {
//            printf(" (%d,%d,%.3f)", p->eki, p->rosen, p->kyori);
//            p = p->next;
//        }
//        printf("\n");
//    }
//    return;
//}
//
//int main() {
//    int eki1, eki2, rosen, ekisu, i;
//    float kyori;
//    /* 頂点数 (駅の数) を ekisu に格納 */
//    scanf("%d ", &ekisu);
//    struct node *adjlist[ekisu];
//    /* 隣接リスト表現を初期化.すべての頂点に対する隣接リストを空にする */
//    for (i = 0; i < ekisu; ++i) adjlist[i] = NULL;
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        /* 隣り合う駅の情報を読取り */
//        sscanf(buf, "%d:%d:%d:%f ", &eki1, &eki2, &rosen, &kyori);
//        /* そのデータを隣接リスト表現のグラフに追加 */
//        add_edge(adjlist, eki1, eki2, rosen, kyori);
//    }
//    print_adjlist(adjlist, ekisu);
//    return 0;
//}

/* 2 */
//float two_hop_kyori(struct node *adjlist[], int eki) {
//    struct node *one_hop_eki = adjlist[eki], *two_hop_eki;
//    float distance = 0, max_distance = 0;
//    if (one_hop_eki == NULL) return distance;
//    while (one_hop_eki != NULL) {
//        distance = one_hop_eki->kyori;
//        two_hop_eki = adjlist[one_hop_eki->eki];
//        while (two_hop_eki != NULL) {
//            if (two_hop_eki->eki == eki) {
//                two_hop_eki = two_hop_eki->next;
//                continue;
//            }
//            distance += two_hop_eki->kyori;
//            if (distance > max_distance) max_distance = distance;
//            distance -= two_hop_eki->kyori;
//            two_hop_eki = two_hop_eki->next;
//        }
//        if (distance > max_distance) max_distance = distance;
//        one_hop_eki = one_hop_eki->next;
//    }
//    return max_distance;
//}

/* 3 */
//#include <stdio.h>
//#include <stdlib.h>
//
//char buf[256];
//
//int main() {
//    int ekisu;
//    scanf("%d ", &ekisu);
//    int adjmat[ekisu][ekisu]; /* ← 隣接行列を表す 2次元配列 */
//
//    int eki1, eki2, rosen, i, j;
//    float kyori;
//    for (i = 0; i < ekisu; i++) {
//        for (j = 0; j < ekisu; j++) {
//            adjmat[i][j] = 0;
//        }
//    }
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d:%d:%d:%f ", &eki1, &eki2, &rosen, &kyori);
//        adjmat[eki1][eki2] = 1;
//        adjmat[eki2][eki1] = 1;
//    }
//    for (i = 0; i < ekisu; i++) {
//        for (j = 0; j < ekisu; j++) {
//            printf("%d", adjmat[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

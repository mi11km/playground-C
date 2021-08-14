//
// Created by いけやままさふみ on 2020/11/30.
//

/* 1 */
//#include<stdio.h>
//
//#define DIGITS 126
//char buf[DIGITS + 2]; /* ← 改行文字とナル文字の 2文字分だけ多く buf を用意 */
//
//void printArrayNum(int len, int arr[DIGITS]) {
//    for (int i = len - 1; i >= 0; --i) printf("%d", arr[i]); /* ←arr[i]の数値を上の位から表示 */
//    printf("\n");
//}
//
//int main() {
//    int i, len1, len2, bigger, sum, r = 0;
//    int arr1[DIGITS] = {}; /* ←要素が全て 0 の配列を作るために {} と書く */
//    int arr2[DIGITS] = {};
//    int sumArr[DIGITS + 1] = {};
//
//    i = 0;
//    fgets(buf, sizeof(buf), stdin); /* ←改行までの文字列を buf に格納 */
//    while (buf[i] != '\n') ++i; /* ←buf の改行の位置を探す (入力の長さがわかる) */
//    len1 = i; /* ←改行の位置を len1 に保存 */
//    for (i = 0; i < len1; ++i) {
//        arr1[i] = (int) (buf[len1 - 1 - i] - '0'); /* ←buf[len1-1-i]を数値にしてarr[i]に格納 */
//    }
//
//    i = 0;
//    fgets(buf, sizeof(buf), stdin);
//    while (buf[i] != '\n') ++i;
//    len2 = i;
//    for (i = 0; i < len2; ++i) {
//        arr2[i] = (int) (buf[len2 - 1 - i] - '0');
//    }
//
//    if (len1 > len2) { bigger = len1; } else { bigger = len2; }
//    for (i = 0; i < bigger; i++) {
//        sum = arr1[i] + arr2[i] + r;
//        sumArr[i] = sum % 10;
//        if (sum > 9) {
//            r = (sum - sumArr[i]) / 10;
//            if (i == bigger - 1) {
//                bigger++;
//                sumArr[i+1] = r;
//                break;
//            }
//        } else {
//            r = 0;
//        }
//    }
//
//    printArrayNum(bigger, sumArr);
//
//    return 0;
//}

/* 2 */
//#include<stdio.h>
//
//#define DIGITS 126
//char buf[DIGITS + 2]; /* ← 改行文字とナル文字の 2文字分だけ多く buf を用意 */
//
//void printArrayNum(int len, int arr[DIGITS]) {
//    for (int i = len - 1; i >= 0; --i) printf("%d", arr[i]); /* ←arr[i]の数値を上の位から表示 */
//    printf("\n");
//}
//
//int main() {
//    int i, len1, len2, r = 0, multLen;
//    int arr1[DIGITS] = {};
//    int arr2[DIGITS] = {};
//    int multArr[252] = {};
//
//    i = 0;
//    fgets(buf, sizeof(buf), stdin);
//    while (buf[i] != '\n') ++i;
//    len1 = i;
//    for (i = 0; i < len1; ++i) {
//        arr1[i] = (int) (buf[len1 - 1 - i] - '0');
//    }
//
//    i = 0;
//    fgets(buf, sizeof(buf), stdin);
//    while (buf[i] != '\n') ++i;
//    len2 = i;
//    for (i = 0; i < len2; ++i) {
//        arr2[i] = (int) (buf[len2 - 1 - i] - '0');
//    }
//
//    if ((len1 == 1 && arr1[0] == 0) || (len2 == 1 && arr2[0] == 0)) {
//        printf("0\n");
//        return 0;
//    }
//
//
//    for (i = 0; i < len1; i++) {
//        for (int j = 0; j < len2; j++) {
//            multArr[i + j] += arr1[i] * arr2[j];
//        }
//    }
//
//    multLen = len1 + len2 -1;
//    for (i = 0; i < multLen; i++) {
//        multArr[i] += r;
//        if (multArr[i] > 9) {
//            r = multArr[i];
//            multArr[i] %= 10;
//            r = (r - multArr[i]) / 10;
//            if (i == multLen - 1) {
//                multLen++;
//                multArr[i+1] = r;
//                break;
//            }
//        } else {
//            r = 0;
//        }
//    }
//
//    printArrayNum(multLen, multArr);
//
//    return 0;
//}

/* 3, 4 */
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
//
//void print_int_list(list l) {
//    list next = l;
//    while (next->next != NULL) {
//        next = next->next;
//        printf("%d", next->element);
//    }
//    printf("\n");
//}
//
//void reverse(list l) {
//    list last, r = l;
//    for (int i = 0; i < length(l) - 1; i++) {
//        last = l;
//        while (last->next->next != NULL) {
//            last = last->next;
//        }
//        last->next->next = r->next;
//        r->next = last->next;
//        r = last->next;
//        last->next = NULL;
//    }
//}
//
//void push(list l, elementtype e) {
//    list addedNode = (list) malloc(sizeof(list));
//    list last = l;
//    while (last->next != NULL) {
//        last = last->next;
//    }
//    addedNode->element = e;
//    addedNode->next = NULL;
//    last->next = addedNode;
//}
//
//void insert(list l, elementtype e) {
//    list addedNode = (list) malloc(sizeof(list));
//    addedNode->element = e;
//    addedNode->next = l->next;
//    l->next = addedNode;
//}
//
//void locate_insert_or_add(list l, elementtype e, int n) {
//    list n_list = l;
//    for (int i = 0; i < n; i++) {
//        n_list = n_list->next;
//    }
//    if (n_list->next != NULL) {
//        n_list = n_list->next;
//        n_list->element += e;
//    } else {
//        push(l, e);
//    }
//}
//
//int locate_element(list l, int n) {
//    list n_list = l;
//    for (int i = 0; i < n + 1; i++) {
//        n_list = n_list->next;
//    }
//    return n_list->element;
//}
//
//void mult(list l1, list l2, list m) {
//    int r;
//    list l = m;
//
//    if ((l1->next->element == 0 && l1->next->next == NULL) || (l2->next->element == 0 && l2->next->next == NULL)) {
//        push(m, 0);
//        return;
//    }
//
//    for (int i = 0; i < length(l1); i++) {
//        for (int j = 0; j < length(l2); j++) {
//            r = locate_element(l1, i) * locate_element(l2, j);
//            locate_insert_or_add(m, r, i+j);
//        }
//    }
//
//    r = 0;
//    while (l->next != NULL) {
//        l = l->next;
//        l->element += r;
//        if (l->element > 9) {
//            r = l->element;
//            l->element %= 10;
//            r = (r - l->element) / 10;
//            if (l->next == NULL) {
//                push(m, r);
//                break;
//            }
//        }
//    }
//}
//
//int main() {
//    int d;
//    char c;
//    list l1 = init_list();
//    list l2 = init_list();
//    list m = init_list();
//    while ((c = getchar()) != '\n') { /* ←読み込んだ数値を c に入れて，改行文字まで以下を繰り返す */
//        d = (int) c - '0'; /* ← 読み込んだ数字を int 型として d に格納 */
//        insert(l1, d);
//    }
//    while ((c = getchar()) != '\n') { /* ←読み込んだ数値を c に入れて，改行文字まで以下を繰り返す */
//        d = (int) c - '0'; /* ← 読み込んだ数字を int 型として d に格納 */
//        insert(l2, d);
//    }
//
//    mult(l1, l2, m);
//
//    reverse(m);
//    print_int_list(m);
//    return 0;
//}
//
//void add(list l1, list l2, list sum) {
//    int max, a1, a2, d, r = 0;
//    if (length(l1) > length(l2)) {
//        max = length(l1);
//    } else {
//        max = length(l2);
//    }
//
//    for (int i = 0; i < max; i++) {
//        if (l1->next == NULL) {
//            a1 = 0;
//        } else {
//            l1 = l1->next;
//            a1 = l1->element;
//        }
//        if (l2->next == NULL) {
//            a2 = 0;
//        } else {
//            l2 = l2->next;
//            a2 = l2->element;
//        }
//        d = a1 + a2 + r;
//        if (d > 9) {
//            r = d;
//            d %= 10;
//            r = (r - d) / 10;
//        } else {
//            r = 0;
//        }
//        insert(sum, d);
//    }
//    if (r != 0) {
//        insert(sum, r);
//    }
//}
//
//

//
// Created by いけやままさふみ on 2020/12/09.
//

/* 2 */
//#include<stdio.h>
//
//int count = 0;
//char kijun;
//
//struct point {
//    int x, y;
//};
//
//int compare(struct point p1, struct point p2) {
//    ++count;
//    int d1, d2;
//    switch (kijun) {
//        case 'X':
//            if (p1.x > p2.x) {
//                return 1;
//            } else if (p1.x < p2.x) {
//                return -1;
//            } else {
//                if (p1.y > p2.y) {
//                    return 1;
//                } else if (p1.y < p2.y) {
//                    return -1;
//                } else {
//                    return 0;
//                }
//            }
//        case 'Y':
//            if (p1.y > p2.y) {
//                return 1;
//            } else if (p1.y < p2.y) {
//                return -1;
//            } else {
//                if (p1.x > p2.x) {
//                    return 1;
//                } else if (p1.x < p2.x) {
//                    return -1;
//                } else {
//                    return 0;
//                }
//            }
//        default:
//            d1 = p1.x * p1.x + p1.y * p1.y;
//            d2 = p2.x * p2.x + p2.y * p2.y;
//            if (d1 > d2) {
//                return 1;
//            } else if (d1 < d2) {
//                return -1;
//            } else {
//                if (p1.x > p2.x) {
//                    return 1;
//                } else if (p1.x < p2.x) {
//                    return -1;
//                } else {
//                    if (p1.y > p2.y) {
//                        return 1;
//                    } else if (p1.y < p2.y) {
//                        return -1;
//                    } else {
//                        return 0;
//                    }
//                }
//            }
//    }
//}
//
///* 構造体 point を要素にもつ配列 a の m 番目から n 番目の要素について，m 番目の要素より小さいものを前に，大きなものを後ろに移す関数 */
//int partition(struct point a[], int m, int n) {
//    struct point pivot = a[m], tmp;
//    int l = m + 1, r = n;
//    while (1 == 1) {
//        while (l < n && (compare(pivot, a[l]) == 1)) {
//            l++;
//        }
//        while (m < r && (compare(a[r], pivot)) == 1) {
//            r--;
//        }
//        if (l < r) {
//            tmp = a[l];
//            a[l] = a[r];
//            a[r] = tmp;
//        } else {
//            break;
//        }
//        l++;
//        r--;
//    }
//    a[m] = a[r];
//    a[r] = pivot;
//    return r;
//}
//
///* 配列 a の m 番目から n 番目までを，クイックソートアルゴリズムにより，指定された規準で昇順に整列する関数 */
//void quicksort(struct point a[], int m, int n) {
//    if (m < n) {
//        int p = partition(a, m, n);
//        quicksort(a, m, p - 1);
//        quicksort(a, p + 1, n);
//    }
//}
//
//int main() {
//    char buf[128];
//    struct point p, arr[128];
//    int i = 0, n;
//    scanf("%c ", &kijun);
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
//        sscanf(buf, "%d %d", &p.x, &p.y);
//        arr[i] = p;
//        ++i;
//    }
//    n = i;
//    quicksort(arr, 0, n - 1);
//    printf("%d\n", count);
//    for (i = 0; i < n; ++i)
//        printf("%d %d\n", arr[i].x, arr[i].y);
//    return 0;
//}

/* 4 */
//#include<stdio.h>
//
//int count = 0;
//char kijun;
//
//struct point {
//    int x, y;
//};
//
//int compare(struct point p1, struct point p2) {
//    ++count;
//    int d1, d2;
//    switch (kijun) {
//        case 'X':
//            if (p1.x > p2.x) {
//                return 1;
//            } else if (p1.x < p2.x) {
//                return -1;
//            } else {
//                if (p1.y > p2.y) {
//                    return 1;
//                } else if (p1.y < p2.y) {
//                    return -1;
//                } else {
//                    return 0;
//                }
//            }
//        case 'Y':
//            if (p1.y > p2.y) {
//                return 1;
//            } else if (p1.y < p2.y) {
//                return -1;
//            } else {
//                if (p1.x > p2.x) {
//                    return 1;
//                } else if (p1.x < p2.x) {
//                    return -1;
//                } else {
//                    return 0;
//                }
//            }
//        default:
//            d1 = p1.x * p1.x + p1.y * p1.y;
//            d2 = p2.x * p2.x + p2.y * p2.y;
//            if (d1 > d2) {
//                return 1;
//            } else if (d1 < d2) {
//                return -1;
//            } else {
//                if (p1.x > p2.x) {
//                    return 1;
//                } else if (p1.x < p2.x) {
//                    return -1;
//                } else {
//                    if (p1.y > p2.y) {
//                        return 1;
//                    } else if (p1.y < p2.y) {
//                        return -1;
//                    } else {
//                        return 0;
//                    }
//                }
//            }
//    }
//}
//
///* 構造体 point を要素にもつ配列 a について，前半 (m 番目から h 番目まで) と後半 (h+1 番目から n 番目まで)
// * がそれぞれ昇順に整列されているときに，それらを組み合わせて全体 (m 番目の要素から n 番 目まで) が昇順に整列されている状態にする関数
// * */
//void merge(struct point a[], int m, int n, int h) {
//    int first = m, last = h + 1, i = 0;
//    struct point tmp[n - m - 1];
//
//    while (first <= h || last <= n) {
//        if (first > h && last <= n) {
//            tmp[i] = a[last];
//            last++;
//            i++;
//            continue;
//        } else if (first <= h && last > n) {
//            tmp[i] = a[first];
//            first++;
//            i++;
//            continue;
//        } else if (compare(a[first], a[last]) == 1) {
//            tmp[i] = a[last];
//            last++;
//            i++;
//            continue;
//        } else {
//            tmp[i] = a[first];
//            first++;
//            i++;
//        }
//    }
//    first = m;
//    for (int j = 0; j < i; j++) {
//        a[first] = tmp[j];
//        first++;
//    }
//}
//
///* 配列 a の m 番目から n 番目までを，マージソートアルゴリズムにより，指定された規準で昇順に整列する関数 */
//void merge_sort(struct point a[], int m, int n) {
//    int h;
//    if (m < n) {
//        h = (m + n) / 2;
//        merge_sort(a, m, h);
//        merge_sort(a, h+1, n);
//        merge(a, m, n, h);
//    }
//}
//
//int main() {
//    char buf[128];
//    struct point p, arr[128];
//    int i = 0, n;
//    scanf("%c ", &kijun);
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
//        sscanf(buf, "%d %d", &p.x, &p.y);
//        arr[i] = p;
//        ++i;
//    }
//    n = i;
//    merge_sort(arr, 0, n - 1);
//    printf("%d\n", count);
//    for (i = 0; i < n; ++i)
//        printf("%d %d\n", arr[i].x, arr[i].y);
//    return 0;
//}

/* 5 */
///* 構造体 point を要素にもつ配列 a の m 番目から n 番目の要素について，
// * ランダムに選んだ要素より小さいものをそれより前に，大きなものを後ろに移す関数 */
//int partition(struct point a[], int m, int n) {
//    int rand_num = m + rand() % (n - m + 1);
//    struct point pivot = a[rand_num], tmp;
//    int l = m, r = n;
//    while (1 == 1) {
//        while (l < n && (compare(pivot, a[l]) == 1)) {
//            l++;
//        }
//        while (m < r && (compare(a[r], pivot)) == 1) {
//            r--;
//        }
//        if (l < r) {
//            if (l == rand_num) {
//                rand_num = r;
//            } else if (r == rand_num) {
//                rand_num = l;
//            }
//            tmp = a[l];
//            a[l] = a[r];
//            a[r] = tmp;
//        } else {
//            break;
//        }
//    }
//    a[rand_num] = a[r];
//    a[r] = pivot;
//    return r;
//}

/* 6 うまくいってない！ */
//#include<stdio.h>
//#include <stdlib.h>
//
//int count = 0;
//char kijun;
//
//struct point {
//    int x, y;
//};
//typedef struct point elementtype;
//
//struct node {
//    elementtype element;
//    struct node *next;
//};
//typedef struct node *list;
//
//int compare(struct point p1, struct point p2) {
//    ++count;
//    int d1, d2;
//    switch (kijun) {
//        case 'X':
//            if (p1.x > p2.x) {
//                return 1;
//            } else if (p1.x < p2.x) {
//                return -1;
//            } else {
//                if (p1.y > p2.y) {
//                    return 1;
//                } else if (p1.y < p2.y) {
//                    return -1;
//                } else {
//                    return 0;
//                }
//            }
//        case 'Y':
//            if (p1.y > p2.y) {
//                return 1;
//            } else if (p1.y < p2.y) {
//                return -1;
//            } else {
//                if (p1.x > p2.x) {
//                    return 1;
//                } else if (p1.x < p2.x) {
//                    return -1;
//                } else {
//                    return 0;
//                }
//            }
//        default:
//            d1 = p1.x * p1.x + p1.y * p1.y;
//            d2 = p2.x * p2.x + p2.y * p2.y;
//            if (d1 > d2) {
//                return 1;
//            } else if (d1 < d2) {
//                return -1;
//            } else {
//                if (p1.x > p2.x) {
//                    return 1;
//                } else if (p1.x < p2.x) {
//                    return -1;
//                } else {
//                    if (p1.y > p2.y) {
//                        return 1;
//                    } else if (p1.y < p2.y) {
//                        return -1;
//                    } else {
//                        return 0;
//                    }
//                }
//            }
//    }
//}
//
//void split(list l1, list l2) {
//    list p1 = l1, p2 = l1;
//    while (p2 != NULL && p2->next != NULL) {
//        p2 = p2->next->next;
//        p1 = p1->next;
//    }
//    l2->next = p1->next;
//    p1->next = NULL;
//}
//
//void merge(list l1, list l2) {
//    list l1_last = l1, l2_last = l2, tmp;
//
//    int r = compare(l1_last->next->element, l2_last->next->element);
//    if (r == 1) {
//        tmp = l1_last->next;
//        l1_last->next = l2_last->next;
//        l1_last = tmp;
//    } else if (r == -1 || r == 0) {
//        l1_last = l1_last->next;
//    }
//    tmp = l2_last;
//    l2_last = l2_last->next;
//    free(tmp);
//
//    while (l1_last != NULL && l2_last != NULL) {
//        if (l1_last != NULL && l2_last == NULL) {
//            continue;
//        } else if (l1_last == NULL && l2_last != NULL) {
//            continue;
//        }
//
//        if (r == 1) {
//            while (r == 1) {
//                tmp = l2_last;
//                l2_last = l2_last->next;
//                if (l2_last == NULL) {
//                    break;
//                }
//                r = compare(l1_last->element, l2_last->element);
//            }
//            tmp->next = l1_last;
//        }
//
//        if (r == -1) {
//            while (r == -1) {
//                tmp = l1_last;
//                l1_last = l1_last->next;
//                if (l1_last == NULL) {
//                    break;
//                }
//                r = compare(l1_last->element, l2_last->element);
//            }
//            tmp->next = l2_last;
//        }
//
//        if (r == 0) {
//            while (r == 0) {
//                tmp = l1_last;
//                l1_last = l1_last->next;
//                if (l1_last == NULL) {
//                    break;
//                }
//                r = compare(l1_last->element, l2_last->element);
//            }
//            tmp->next = l2_last;
//        }
//    }
//
//}
//
//void merge_sort(list l) {
//    if (l->next->next != NULL) {
//        list l2 = (list) malloc(sizeof(struct node));
//        split(l, l2);
//        merge_sort(l);
//        merge_sort(l2);
//        merge(l, l2);
//    }
//}
//
//int main() {
//    char buf[128];
//    struct point p;
//    list l, last;
//    scanf("%c ", &kijun);
//    last = l = (list) malloc(sizeof(struct node));
//    while (fgets(buf, sizeof(buf), stdin) != NULL) {
//        sscanf(buf, "%d %d", &p.x, &p.y);
//        last = last->next = (list) malloc(sizeof(struct node));
//        last->element = p;
//    }
//    last->next = NULL;
//
//    merge_sort(l);
//
//    printf("%d\n", count);
//    while ((l = l->next) != NULL) {
//        p = l->element;
//        printf("%d %d\n", p.x, p.y);
//    }
//    return 0;
//}
//
//
//void make_list(list l) {
//    int x[5] = {731, 488, 488, 722, 722};
//    int y[5] = {-745, -524, -524, 65, 65};
//    struct point p;
//    list last = l;
//    for (int i = 0; i < 5; i++) {
//        p.x = x[i];
//        p.y = y[i];
//        last = last->next = (list) malloc(sizeof(struct node));
//        last->element = p;
//    }
//    last->next = NULL;
//}
//void print_list(list l) {
//    struct point p;
//    list tmp = l;
//    while ((tmp = tmp->next) != NULL) {
//        p = tmp->element;
//        printf("%d %d\n", p.x, p.y);
//    }
//}
//
////struct point p;
////list l = (list) malloc(sizeof(struct node));
////make_list(l);
////kijun = 'X';
//

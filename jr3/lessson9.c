//
// Created by いけやままさふみ on 2020/12/16.
//

/* 1 */
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
///* 構造体 point を要素にもつ配列 a のうち，先頭 n 個 (0 番目から n-1 番目まで)
// * がヒープになっていれば 1 を返し，ヒープでなければ 0 を返す関数 */
//int is_heap(struct point a[], int n) {
//    int r1, r2, g = n % 2;
//    if (g == 0) {
//        for (int i = 0; 2 * i + 1 < n; i++) {
//            r1 = compare(a[i], a[2 * i + 1]);
//            if (2 * i + 2 < n) {
//                r2 = compare(a[i], a[2 * i + 2]);
//            } else {
//                r2 = 1;
//            }
//            if (r1 == -1 || r2 == -1) {
//                return 0;
//            }
//        }
//    } else {
//        for (int i = 0; 2 * i + 2 < n; i++) {
//            r1 = compare(a[i], a[2 * i + 1]);
//            r2 = compare(a[i], a[2 * i + 2]);
//            if (r1 == -1 || r2 == -1) {
//                return 0;
//            }
//        }
//    }
//    return 1;
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
//    if (is_heap(arr, n)) printf("Yes.\n");
//    else printf("No.\n");
//    return 0;
//}

/* 2 */
///* 構造体 point を要素にもつ配列 a について，m+1 番目から n 番目までがヒープの条件を満たしているときに，
// * m 番目の要素を適切な位置に挿入して m 番目から n 番目までがヒープの条件を満たしているようにする関数 */
//void pushdown(struct point a[], int m, int n) {
//    int i;
//    struct point tmp;
//    if (2 * m + 2 <= n) {
//        if (compare(a[2 * m + 1], a[2 * m + 2]) == 1) {
//            i = 2 * m + 1;
//        } else {
//            i = 2 * m + 2;
//        }
//        if (compare(a[i], a[m]) == 1) {
//            tmp = a[i];
//            a[i] = a[m];
//            a[m] = tmp;
//            pushdown(a, i, n);
//        }
//    } else if (2 * m + 1 == n) {
//        if (compare(a[2 * m + 1], a[m]) == 1) {
//            tmp = a[2 * m + 1];
//            a[2 * m + 1] = a[m];
//            a[m] = tmp;
//        }
//    } else if (2 * m + 1 > n) {
//        return;
//    }
//}

/* 3 */
//#include<stdio.h>
//#include <stdlib.h>
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
///* 構造体 point を要素にもつ配列 a について，m+1 番目から n 番目までがヒープの条件を満たしているときに，
// * m 番目の要素を適切な位置に挿入して m 番目から n 番目までがヒープの条件を満たしているようにする関数 */
//void pushdown(struct point a[], int m, int n) {
//    int i;
//    struct point tmp;
//    if (2 * m + 2 <= n) {
//        if (compare(a[2 * m + 1], a[2 * m + 2]) == 1) {
//            i = 2 * m + 1;
//        } else {
//            i = 2 * m + 2;
//        }
//        if (compare(a[i], a[m]) == 1) {
//            tmp = a[i];
//            a[i] = a[m];
//            a[m] = tmp;
//            pushdown(a, i, n);
//        }
//    } else if (2 * m + 1 == n) {
//        if (compare(a[2 * m + 1], a[m]) == 1) {
//            tmp = a[2 * m + 1];
//            a[2 * m + 1] = a[m];
//            a[m] = tmp;
//        }
//    } else if (2 * m + 1 > n) {
//        return;
//    }
//}
//
///* 配列 a の先頭 n 個の要素 (0 番目から n-1 番目まで) を，ヒープソートアルゴリズムにより，指定された規準で昇順に整列する関数 */
//void heap_sort(struct point a[], int n) {
//    struct point tmp;
//    for (int k = n / 2 - 1; k >= 0; --k) {
//        pushdown(a, k, n - 1);
//    }
//    for (int k = n - 1; k >= 1; --k) {
//        tmp = a[0];
//        a[0] = a[k];
//        a[k] = tmp;
//        pushdown(a, 0, k-1);
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
//    heap_sort(arr, n);
//    printf("%d\n", count);
//    for (i = 0; i < n; ++i)
//        printf("%d %d\n", arr[i].x, arr[i].y);
//    return 0;
//}

/* 4 */
//#include <stdio.h>
//
//struct point {
//    int x, y;
//};
//
//void bucket_sort(struct point a[], int n) {
//    struct point b[n];
//    int i, c[100] = {};  // (1)
//
//    for (i = 0; i < n; ++i) {
//        c[a[i].x]++;  // (2)
//        b[i] = a[i];  // (4)
//    }
//
//    for (i = 1; i < 100; ++i) {
//        c[i] = c[i] + c[i - 1];  // (3)
//    }
//
//    for (i = n - 1; i >= 0; --i) {
//        c[b[i].x]--;
//        a[c[b[i].x]] = b[i];
//    }
//}
//
//int main() {
//    char buf[128];
//    struct point p, arr[128];
//    int i = 0, n;
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
//        sscanf(buf, "%d %d", &p.x, &p.y);
//        arr[i] = p;
//        ++i;
//    }
//    n = i;
//    bucket_sort(arr, n);
//    for (i = 0; i < n; ++i)
//        printf("%d %d\n", arr[i].x, arr[i].y);
//    return 0;
//}

/* 5 */

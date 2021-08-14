//
// Created by いけやままさふみ on 2020/12/03.
//

/* 1 */
//#include<stdio.h>
//
//int max_index(int a[], int n) {
//    int max_i = 0, max_n = a[0];
//    for (int i = 0; i < n - 1; i++) {
//        if (max_n <= a[i + 1]) {
//            max_i = i + 1;
//            max_n = a[i + 1];
//        }
//    }
//    return max_i;
//}
//
//int main() {
//    char buf[128];
//    int arr[128], i = 0;
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128)
//        sscanf(buf, "%d", &arr[i++]);
//    printf("%d\n", max_index(arr, i));
//    return 0;
//}


/* 2 */
//#include<stdio.h>
//
//struct point {
//    int x, y;
//};
//
//int compare_by(struct point p1, struct point p2, char c) {
//    int d1, d2;
//    switch (c) {
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
//int max_index_by(struct point a[], int n, char c) {
//    struct point max_p = a[0];
//    int max_i = 0;
//    for (int i = 0; i < n - 1; i++) {
//        if (compare_by(max_p, a[i + 1], c) == -1 || compare_by(max_p, a[i + 1], c) == 0) {
//            max_p = a[i + 1];
//            max_i = i + 1;
//        }
//    }
//    return max_i;
//}
//
//int main() {
//    char c, buf[128];
//    struct point p, arr[128];
//    int i = 0;
//    scanf("%c ", &c);
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
//        sscanf(buf, "%d %d", &p.x, &p.y);
//        arr[i] = p;
//        ++i;
//    }
//    printf("%d\n", max_index_by(arr, i, c));
//    return 0;
//}


/* 3 */
//#include<stdio.h>
//
//int count = 0;
//
//struct point {
//    int x, y;
//};
//
//int compare_by(struct point p1, struct point p2, char c) {
//    ++count;
//    int d1, d2;
//    switch (c) {
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
//int max_index_by(struct point a[], int n, char c) {
//    struct point max_p = a[0];
//    int max_i = 0, r;
//    for (int i = 0; i < n - 1; i++) {
//        r = compare_by(max_p, a[i + 1], c);
//        if (r == -1 || r == 0) {
//            max_p = a[i + 1];
//            max_i = i + 1;
//        }
//    }
//    return max_i;
//}
//
//void selection_sort(struct point a[], int n, char c) {
//    int i;
//    struct point tmp;
//    for (int k = n; k > 1; k--) {
//        i = max_index_by(a, k, c);
//        tmp = a[i];
//        a[i] = a[k - 1];
//        a[k - 1] = tmp;
//    }
//}
//
//int main() {
//    char c, buf[128];
//    struct point p, arr[128];
//    int i = 0, n;
//    scanf("%c ", &c);
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
//        sscanf(buf, "%d %d", &p.x, &p.y);
//        arr[i] = p;
//        ++i;
//    }
//    n = i;
//    selection_sort(arr, n, c);
//    printf("%d\n", count);
//    for (i = 0; i < n; ++i)
//        printf("%d %d\n", arr[i].x, arr[i].y);
//    return 0;
//}

/* 4 */
//#include<stdio.h>
//
//struct point {
//    int x, y;
//};
//
//int compare_by(struct point p1, struct point p2, char c) {
//    int d1, d2;
//    switch (c) {
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
//void insert_by(struct point a[], int n, char c) {
//    int p;
//    struct point tmp;
//    for (int i = n - 2; i >= 0; i--) {
//        p = compare_by(a[i], a[i + 1], c);
//        if (p == 1) {
//            tmp = a[i];
//            a[i] = a[i + 1];
//            a[i + 1] = tmp;
//        } else {
//            break;
//        }
//    }
//};
//
//int main() {
//    char c, buf[128];
//    struct point p, arr[128];
//    int i = 0, n;
//    scanf("%c ", &c);
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
//        sscanf(buf, "%d %d", &p.x, &p.y);
//        arr[i] = p;
//        ++i;
//    }
//    n = i;
//    insert_by(arr, n, c);
//    for (i = 0; i < n; ++i)
//        printf("%d %d\n", arr[i].x, arr[i].y);
//    return 0;
//}

/* 5 */
//#include<stdio.h>
//
//int count = 0;
//
//struct point {
//    int x, y;
//};
//
//int compare_by(struct point p1, struct point p2, char c) {
//    ++count;
//    int d1, d2;
//    switch (c) {
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
//void insert_by(struct point a[], int n, char c) {
//    int p;
//    struct point tmp;
//    for (int i = n - 2; i >= 0; i--) {
//        p = compare_by(a[i], a[i + 1], c);
//        if (p == 1) {
//            tmp = a[i];
//            a[i] = a[i + 1];
//            a[i + 1] = tmp;
//        } else {
//            break;
//        }
//    }
//}
//
//void insertion_sort(struct point a[], int n, char c) {
//    for (int k = 2; k <= n; k++) {
//        insert_by(a, k, c);
//    }
//}
//
//int main() {
//    char c, buf[128];
//    struct point p, arr[128];
//    int i = 0, n;
//    scanf("%c ", &c);
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
//        sscanf(buf, "%d %d", &p.x, &p.y);
//        arr[i] = p;
//        ++i;
//    }
//    n = i;
//    insertion_sort(arr, n, c);
//    printf("%d\n", count);
//    for (i = 0; i < n; ++i)
//        printf("%d %d\n", arr[i].x, arr[i].y);
//    return 0;
//}

/* 6 */
//#include<stdio.h>
//
//int count = 0;
//
//struct point {
//    int x, y;
//};
//
//int compare_by(struct point p1, struct point p2, char c) {
//    ++count;
//    int d1, d2;
//    switch (c) {
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
//void bubble_sort(struct point a[], int n, char c) {
//    int p;
//    struct point tmp;
//    for (int k = n - 2; k >= 0; k--) {
//        for (int l = 0; l <= k; l++) {
//            p = compare_by(a[l], a[l + 1], c);
//            if (p == 1) {
//                tmp = a[l];
//                a[l] = a[l + 1];
//                a[l + 1] = tmp;
//            }
//        }
//    }
//}
//
//int main() {
//    char c, buf[128];
//    struct point p, arr[128];
//    int i = 0, n;
//    scanf("%c ", &c);
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
//        sscanf(buf, "%d %d", &p.x, &p.y);
//        arr[i] = p;
//        ++i;
//    }
//    n = i;
//    bubble_sort(arr, n, c);
//    printf("%d\n", count);
//    for (i = 0; i < n; ++i)
//        printf("%d %d\n", arr[i].x, arr[i].y);
//    return 0;
//}

/* 7 */
//#include<stdio.h>
//
//struct point {
//    int x, y;
//};
//
//struct point_loc {
//    int loc;
//    struct point p;
//};
//
//int compare_by(struct point p1, struct point p2, char c) {
//    int d1, d2;
//    switch (c) {
//        case 'x':
//            if (p1.x > p2.x) {
//                return 1;
//            } else if (p1.x < p2.x) {
//                return -1;
//            } else {
//                return 0;
//            }
//        case 'y':
//            if (p1.y > p2.y) {
//                return 1;
//            } else if (p1.y < p2.y) {
//                return -1;
//            } else {
//                return 0;
//            }
//        default:
//            d1 = p1.x * p1.x + p1.y * p1.y;
//            d2 = p2.x * p2.x + p2.y * p2.y;
//            if (d1 > d2) {
//                return 1;
//            } else if (d1 < d2) {
//                return -1;
//            } else {
//                return 0;
//            }
//    }
//}
//
//int max_index_by(struct point_loc a[], int n, char c) {
//    struct point_loc max_p = a[0];
//    int max_i = 0, r;
//    for (int i = 0; i < n - 1; i++) {
//        r = compare_by(max_p.p, a[i + 1].p, c);
//        if (r == -1) {
//            max_p = a[i + 1];
//            max_i = i + 1;
//        } else if (r == 0) {
//            if (max_p.loc < a[i + 1].loc) {
//                max_p = a[i + 1];
//                max_i = i + 1;
//            }
//        }
//    }
//    return max_i;
//}
//
//void selection_sort(struct point_loc a[], int n, char c) {
//    int i;
//    struct point_loc tmp;
//    for (int k = n; k > 1; k--) {
//        i = max_index_by(a, k, c);
//        tmp = a[i];
//        a[i] = a[k - 1];
//        a[k - 1] = tmp;
//    }
//}
//
//void stable_selection_sort(struct point a[], int n, char c) {
//    struct point_loc arr[n];
//    for (int i = 0; i < n; i++) {
//        arr[i].loc = i;
//        arr[i].p = a[i];
//    }
//
//    selection_sort(arr, n, c);
//
//    for (int i = 0; i < n; i++) {
//        a[i] = arr[i].p;
//    }
//}
//
//int main() {
//    char c, buf[128];
//    struct point p, arr[128];
//    int i = 0, n;
//    scanf("%c ", &c);
//    while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
//        sscanf(buf, "%d %d", &p.x, &p.y);
//        arr[i] = p;
//        ++i;
//    }
//    n = i;
//    stable_selection_sort(arr, n, c);
//    for (i = 0; i < n; ++i)
//        printf("%d %d\n", arr[i].x, arr[i].y);
//    return 0;
//}
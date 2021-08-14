// test_itbl.c --- unit test for itable.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "itbl.h"

void expect_itbl(int n) {
    struct timespec tm1, tm2, tm3;
    itblp t = itbl_new();
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) { a[i] = rand(); }
    clock_gettime(CLOCK_REALTIME, &tm1);
    for (int i = 0; i < n; ++i) { itbl_put(t, a[i], a[i] + 1); }
    clock_gettime(CLOCK_REALTIME, &tm2);
    for (int i = 0; i < n; ++i) { itbl_get(t, a[i]); }
    clock_gettime(CLOCK_REALTIME, &tm3);
    int c = 0;
    for (int i = 0; i < n; ++i) {
        int v = itbl_get(t, a[i]);
        if (v == a[i] + 1) { continue; }
        if (++c < 5) {
            printf(" NG: #\%d get[%d] == %d, expected %d\n", i, a[i], v, a[i] + 1);
        } else if (c == 5) {
            printf("more wrong value omitted.\n");
        }
    }
    double dt1 = (tm2.tv_sec - tm1.tv_sec) + 1e-9 * (tm2.tv_nsec - tm1.tv_nsec);
    double dt2 = (tm3.tv_sec - tm2.tv_sec) + 1e-9 * (tm3.tv_nsec - tm2.tv_nsec);
    printf("%s size=%d tput=%.4f tget=%.4f %s\n", c == 0 ? "OK" : "NG", n, dt1, dt2);
    free(a);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    for (int i = 1; i < argc; ++i) { expect_itbl(atoi(argv[i])); }
    return 0;
}

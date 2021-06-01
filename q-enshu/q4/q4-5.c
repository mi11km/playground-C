#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int buffer[256];

int *p;
int N;
bool *used;

void perm(int *numbers, int n, int k) {
    if (n == k) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", buffer[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        used[i] = true;
        buffer[k] = numbers[i];
        perm(numbers, n, k + 1);
        used[i] = false;
    }
}

int main(int argc, char *argv[]) {
    N = atoi(argv[1]);
    p = malloc((N + 1) * sizeof(int));
    used = malloc((N + 1) * sizeof(bool));
    for (int i = 1; i <= N; i++) {
        p[i] = i;
        used[i] = false;
    }

    perm(p + 1, N, 0);
    return 0;
}
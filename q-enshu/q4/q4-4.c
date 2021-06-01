#include <stdio.h>
#include <stdlib.h>

int combination(int n, int r) {
    /* combination関数を呼ぶ処理を記述*/
    if (r == 0 || r == n) return 1;
    if (r == 1) return n;
    return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main(int argc, char *argv[]) {
    printf("%d\n", combination(atoi(argv[1]), atoi(argv[2])));
    return 0;
}
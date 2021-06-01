#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    /* fib関数を呼ぶ処理を記述*/
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char *argv[]) {
    int num = atoi(argv[1]);

    int i;
    for (i = 1; i <= num; i++)
        printf("%d ", fib(i));
    printf("\n");

    return 0;
}
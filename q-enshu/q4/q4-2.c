#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    /* factorial関数を呼ぶ処理を記述*/
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(int argc, char *argv[]){
    printf("%d\n", factorial(atoi(argv[1])));
    return 0;
}
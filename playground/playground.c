//
// Created by いけやままさふみ on 2020/10/14.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int gcd(int a, int b) {
    int r;
    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

void playground() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a < b) {
        swap(&a, &b);
    }
    printf("%d", gcd(a, b));

    int total = 10;
    int nums[total], i, j, tmp;
    for (i = 0; i < total; i++) {
        scanf("%d", &nums[i]);
    }
    for (i = 0; i < total; i++) {
        for (j = i + 1; j < total; j++) {
            if (nums[i] < nums[j]) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    printf("%d", nums[1]);


    int n;
    scanf("%d", &n);
    printf("%d\n", n + 1);

    char str[128];
    fgets(str, 128, stdin);
    printf("%s", str);

    double y = 0.0;
    for (int i = 0; i < 10; i++) { y += 0.1; };
    if (y == 1.0) {
        printf("yes %f\n", y);
    } else {
        printf("no %f\n", y);
    }
}

// binを2進数8桁で標準出力する
void printBin(int bin) {
    for (int i = 31; i >= 0; i--) {
        // i+1桁目を右シフトで一番右に持ってきて、一番右以外をマスク処理で0にする
        printf("%d", (bin >> i) & 0x01);
    }
    printf("b\n");
}






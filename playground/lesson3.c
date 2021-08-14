//
// Created by いけやままさふみ on 2020/10/22.
//


/* &x.a は &(x.a) と同じ意味 */

/*
struct golden power_golden2(struct golden x, int n) {
    struct golden z;
    if (n == 0) {
        z.a = 1;
        z.b = 0;
        return z;
    }
    z = mult_golden(x, power_golden2(x, n - 1));
    return z;
}

int mult_counter = 0;
int add_counter = 0;

// double_golden: 第 1引数を 2倍した数を返す関数
struct golden double_golden(struct golden x) {
    struct golden y;
    y.a = x.a * 2;
    y.b = x.b * 2;
    return y;
}

 */

//#include <stdio.h>
//#include <math.h>
//
//struct golden {
//    long long int a;
//    long long int b;
//};
//
///* add_golden: 第 1引数と第 2引数の和を返す関数 */
//struct golden add_golden(struct golden x, struct golden y) {
//    struct golden z;
//    z.a = x.a + y.a;
//    z.b = x.b + y.b;
//    return z;
//}
//
///* compare_golden: 第1引数と第2引数を比較する関数 */
//int compare_golden(struct golden x, struct golden y) {
//    struct golden z;
//    double num;
//    if (x.a == y.a && x.b == y.b) {
//        return 0;
//    }
//    y.a = -y.a;
//    y.b = -y.b;
//    z = add_golden(x, y);
//    num = z.a + z.b * ((1 + sqrt(5)) / 2);
//    printf("%f\n", num);
//    if (num > 0) {
//        return 1;
//    } else {
//        return -1;
//    }
//}
//
//int main() {
//    struct golden x, y;
//    int n = 1;
//    scanf("%lld %lld", &x.a, &x.b);
//    scanf("%lld %lld", &y.a, &y.b);
//    n = compare_golden(x, y);
//    printf("%d\n", n);
//    return 0;
//}
//
//
///* mult_golden: 第 1引数と第 2引数の積を返す関数 */
//struct golden mult_golden(struct golden x, struct golden y) {
////    mult_counter += 5;
////    add_counter += 3;
//    struct golden z;
//    z.a = x.a * y.a + x.b * y.b;
//    z.b = x.a * y.b + x.b * y.a + x.b * y.b;
//    return z;
//}
//
///* power_golden: 第 1引数の第 2引数乗を返す関数 */
//struct golden power_golden(struct golden x, int n) {
//    struct golden z;
//    if (n == 0) {
//        z.a = 1;
//        z.b = 0;
//        return z;
//    } else if (n % 2 == 1) {
//        z = mult_golden(x, power_golden(x, n - 1));
//        return z;
//    } else {
//        struct golden i;
//        i = power_golden(x, n / 2);
//        z = mult_golden(i, i);
//    }
//    return z;
//}
//
///* nth_fibonacci_sequence: 第1引数番目のフィボナッチ数列を返す関数 */
//long long int nth_fibonacci_sequence(int n) {
//    struct golden f;
//    f.a = 1;
//    f.b = -1;
//    f = power_golden(f, n - 1);
//    return f.a;
//}
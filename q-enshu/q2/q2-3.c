#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float log_float(float f) {
    int   *iPtr;
    int   exp;
    float log2 = 0.301, result;

    iPtr = (int *)&f;
    exp = (*iPtr >> 23) & 0xFF;

    result = (exp - 127) * log2;
    return result;
}

double log_double(double d) {
    long *iPtr;
    long  exp;
    double log2 = 0.301, result;

    iPtr = (long *)&d;
    exp = (*iPtr >> 52) & 0x7FF;

    result = (exp - 1023) * log2;
    return result;
}


int main(int argc, char *argv[]) {
    float  f, f_exp;
    double d, d_exp;

    f = atof(argv[1]);
    d = atof(argv[2]);

    f_exp = log_float(f);
    d_exp = log_double(d);

    printf("%.3f,%.3lf\n", f_exp, d_exp);
    return 0;
}



/*
 * ポインタ型変数のキャストを行ってもポインタが示すアドレスの値もサイズも変わらない。
 * 変わるのはそのアドレスに格納されているデータの覗き方(参照する型)が変わるだけ！！
 * */

//#include <stdio.h>
//
//int main(int argc, char *argv[]) {
//    float float_num = 0x02;
//    printf("p: %p, v: %f\n", &float_num, float_num);
//    int *iPtr, integer;
//    iPtr = (int*) &float_num;
//    integer = *iPtr;
//
//    printf("iPtr: %p, integer: %d\n", iPtr, integer);
//    return 0;
//}
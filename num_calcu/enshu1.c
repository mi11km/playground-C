//
// Created by いけやままさふみ on 2020/10/30.
//

/*
#include <stdio.h>
#include <string.h>

#define DOUBLE_BITS ( 64 )

// Get the i-th bit of a double variable x
// The highest bit (i.e., the sign) is 63
int bit(const double x, const int i) {
    unsigned long v;
    memcpy (&v, &x, sizeof(double));
    return (v >> i) & 1;
}

int main(void) {
    double x = 0.1;

    for (int i = DOUBLE_BITS - 1; i >= 0; i--) {
        int b = bit(x, i);
        // Print the i-th bit while inserting spaces
        // to separate the sign, mantissa, and exponent
        printf("%d%s", b, (i == 63 || i == 52) ? " " : "");
    }
    printf("\n");

    return 0;
}

-----

#include <stdio.h>
#include <math.h>

#define __USE_BSD


double f(double x) { return sin(x); }

int main(void) {
    double x = M_PI / 4.0;
    double h = 1.0;
    const double min = 0.00000000000001;

    while (h > min) {
        double dfdx = (f(x + h / 2.0) - f(x - h / 2.0)) / h;
        double relerr = fabs(dfdx - cos(x)) / fabs(cos(x));
        printf("%1.14f %1.14f %1.14f\n", h, dfdx, relerr);
        h = h * 0.1;
    }

    return 0;
}

-----

#include <stdio.h>
#include <math.h>

#define Epsilon ( 1e-14 )

double f(double x) { return sin(x) - x; }

double dfdx(double x) { return cos(x) - 1; }

//double f(double x) { return x * x - 2 * x + 1; }
//
//double dfdx(double x) { return 2 * x - 2; }

double g(double x) { return x * x - 3 * x + 2; }

double dgdx(double x) { return 2 * x - 3; }

double newton_method(double ( *f )(double), double ( *dfdx )(double), double initial_value, double epsilon) {
    double x = initial_value;

    int i = 0;
    while (fabs(f(x)) > epsilon) {
        fprintf(stderr, "%d %1.16f\n", i, x);
        x = x - f(x) / dfdx(x);
        i++;
    }

    return x;
}

int main(void) {
    double x = newton_method(f, dfdx, 100.1, Epsilon);
    printf("answer = %1.16f\n", x);

//    double y = newton_method(g, dgdx, 1.1, Epsilon);
//    printf("answer = %1.16f\n", y);

    return 0;
}

-----
 #include <stdio.h>
#include <math.h>

#define Epsilon ( 1e-14 )

double f(double x) { return x * x * x - 7 * x * x + 6 * x; } // solutions are 6, 1, 0
double dfdx(double x) { return 3 * x * x - 14 * x + 6; }

double secant_method(double ( *f )(double), double initial_value, double epsilon) {
    double xn = initial_value;
    double xn_1 = 5.0;
    double s;

    int i = 0;
    while (fabs(f(xn)) > epsilon) {
        fprintf(stderr, "secant %d %1.16f %1.16f\n", i, xn, xn_1);
        s = xn;
        xn = xn - (f(xn) * (xn - xn_1)) / (f(xn) - f(xn_1));
        xn_1 = s;
        i++;
    }

    return xn;
}

double newton_method(double ( *f )(double), double ( *dfdx )(double),
                     double initial_value, double epsilon) {
    double x = initial_value;

    int i = 0;
    while (fabs(f(x)) > epsilon) {
        fprintf(stderr, "newton %d %1.16f\n", i, x);
        x = x - f(x) / dfdx(x);
        i++;
    }

    return x;
}

int main(void) {
    double x = secant_method(f, 7.0, Epsilon); // find x = 6.0 while starting at 7.0
    printf("secant answer = %1.16f\n", x);

    double y = newton_method(f, dfdx, 7.0, Epsilon);
    printf("newton answer = %1.16f\n", y);

    return 0;
}


*/
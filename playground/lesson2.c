//
// Created by いけやままさふみ on 2020/10/20.
//

int NthFibonacciSequenceDividedBy2718(int n) {
    int d = 2718;
    int r_0 = 0 % d;
    int r_1 = 1 % d;
    int r_n;

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int r_n_1 = r_1;
        int r_n_2 = r_0;

        while (n != 1) {
            r_n = (r_n_1 % d + r_n_2 % d) % d;
            r_n_2 = r_n_1;
            r_n_1 = r_n;
            n--;
        }
        return r_n;
    }
}
//

int CalFac(int num) {
    int answer = 1;
    for (int i = 2; i <= num; i++) {
        answer *= i;
    }
    return answer;
}

int CombinationDividedBy2718(int n, int k) {
    int d = 2718;
    int r_n_C_k = 1 % d;

    if (k == 0 || k == n) {
        return r_n_C_k;
    } else if (0 < k && k < n) {
        int r_n_1_C_k = 1 % d;
        int r_n_1_C_k_1 = k % d;
        //(CalFac(k) / (CalFac(k) * CalFac(n - 2)))

        for (int i = k + 1; i < n; i++) {
            r_n_1_C_k = (r_n_1_C_k + r_n_1_C_k_1) % d;
            r_n_1_C_k_1 = r_n_1_C_k;
            r_n_1_C_k = r_n_C_k;
        }

        return r_n_C_k;
    }
}

int IndexDividedBy2718(int a, int b) {
    const int d = 2718;
    const int r_1 = a % d;

    int r = 1 % d;
    int even_r = (r_1 * r_1) % d;
    int odd_r = even_r;

    if (a == 1 || b == 0) {
        return r;
    } else if (b == 1) {
        return r_1;
    } else if (b == 2) {
        return even_r;
    }

    for (int i = 3; i <= b; i++) {
        if (i % 2 == 1) {
            r = (odd_r * r_1) % d;
        } else if (i % 2 == 0) {
            r = (even_r * even_r) % d;
            odd_r = r;
            even_r = (even_r * r_1) % d;
        }
    }
    return r;
}


#include <cstdio>

int phi(int n) {
    int m = 1;
    for (int i = 2; n > 1; ++i) {
        if (n % i == 0) {
            m *= i - 1;
            n /= i;
            while (n % i == 0) {
                m *= i;
                n /= i;
            }
        }
    }
    return m;
}

int powMod(int a, int b, int m) {
    int c = 1 % m;
    while (b > 0) {
        if ((b & 1) != 0) {
            c = c * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return c;
}

int gao(int b) {
    if (b == 1) {
        return 0;
    } else {
        int d = phi(b);
        return powMod(2, d + gao(d), b);
    }
}

int gao(int n, int b) {
    if (n == 1) {
        return 2;
    } else if (n == 2) {
        return 4;
    } else if (n == 3) {
        return 16;
    } else if (n == 4) {
        return 65536;
    } else {
        int d = phi(b);
        return powMod(2, d + gao(n - 1, d), b);
    }
}

int main() {
    int T, t, n, m, x, y;

    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &t);
        x = gao(t);
        for (int ri = 1; ; ++ri) {
            scanf("%d%d", &n, &m);
            if (n == 0) {
                break;
            } else if (n == 1) {
                y = 2 * m % t;
            } else if (n == 2) {
                y = powMod(2, m, t);
            } else if (n == 3) {
                if (m < 32) {
                    y = gao(m, t) % t;
                } else {
                    y = x;
                }
            } else {
                if (m == 1) {
                    y = 2 % t;
                } else if (m == 2) {
                    y = 4 % t;
                } else if (n == 4 && m == 3) {  // WA
                    y = gao(4, t) % t;
                } else {
                    y = x;
                }
            }
            printf("Case %d: %d\n", ri, y);
        }

        if (T > 0) {
            puts("");
        }
    }

    return 0;
}

/*
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
2131952     2010-03-29 21:03:19     Accepted    2595    C++     10  176     watashi@Zodiac
*/

// 2012-09-07 01:30:52 | Accepted | 2595 | C++ | 0 | 180 | watashi | Source

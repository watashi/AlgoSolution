#include <cmath> // auto fix CE
#include <cstdio>

long long f[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
long long p[] = {2, 3, 5, 7, 11, 13};

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long phi(long long n) {
    long long m = 1;
    for (int i = 0; n > 1; ++i) {
        if (n % p[i] == 0) {
            m *= p[i] - 1;
            n /= p[i];
            while (n % p[i] == 0) {
                m *= p[i];
                n /= p[i];
            }
        }
    }
    return m;
}

long long powMod(long long a, long long b, long long m) {
    long long c = 1 % m;
    while (b > 0) {
        if ((b & 1) != 0) {
            c = c * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return c;
}

long long gao(long long a, long long b) {
    if (b == 1) {
        return 0;
    } else {
        long long d = phi(b);
        return powMod(a, d + gao(a, d), b);
    }
}

int main() {
    bool blank = false;
    long long a, b;

    while (scanf("%lld%lld", &a, &b) != EOF) {
        if (blank) {
            puts("");
        } else {
            blank = true;
        }
        printf("%lld\n", gao(a, f[b]));
    }

    return 0;
}

/*
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
2130779     2010-03-28 22:49:39     Accepted    2674    C++     0   176     watashi@Zodiac
*/

// 2012-09-07 15:43:13 | Accepted | 2674 | C++ | 0 | 180 | watashi | Source

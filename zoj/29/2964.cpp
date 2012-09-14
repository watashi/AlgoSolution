#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

long long phi(long long n) {
    long long ret = 1;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ret *= i - 1;
            n /= i;
            while (n % i == 0) {
                ret *= i;
                n /= i;
            }
        }
    }
    if (n > 1) {
        ret *= n - 1;
    }
    return ret;
}

long long pow(long long a, long long p, long long z) {
    long long ret = 1;
    while (p > 0) {
        if (p & 1) {
            ret = (ret * a) % z;
        }
        p >>= 1;
        a = (a * a) % z;
    }
    return ret;
}

int main() {
    int re;
    long long a, z, t, l;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%lld%lld", &a, &z);
        t = phi(z); // if (z == 1) { 2 3 4 }
        // fprintf(stderr, "%lld\n", t);
        l = t;
        for (long long i = 1; i * i <= t; ++i) {
            if (t % i == 0) {
                if (pow(a, i, z) == 1) {
                    l = min(l, i);
                }
                if (pow(a, t / i, z) == 1) {
                    l = min(l, t / i);
                }
            }
        }
        // l + 1, 2l + 1, 3l + 1
        printf("%lld\n", 6 * l + 3);
    }

    return 0;
}

// Run ID   Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
// 1831455  2009-04-12 19:00:24     Accepted    2964    C++     150     176     watashi@Zodiac

// 2012-09-07 01:50:25 | Accepted | 2964 | C++ | 140 | 180 | watashi | Source

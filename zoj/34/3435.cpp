#include <cmath>
#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 1000001;

int p[MAXN];

void init() {
    p[1] = 1;
    for(int i = 2; i < MAXN; ++i) {
        if (!p[i]) {
            for (int j = i; j < MAXN; j += i) {
                p[j] = i;
            }
        }
    }
    for (int i = 2; i < MAXN; ++i) {
        p[i] = (i / p[i] % p[i] == 0 ? 0 : -p[i / p[i]]);
    }
    partial_sum(p, p + MAXN, p);
}

long long gao(long long x, long long y) {
    if (x > y) {
        return gao(y, x);
    }

    long long ret = 0;
    for (long long i = x, j; i > 0; i = j) {
        long long xx = x / i, yy = y / i;
        j = max(x / (xx + 1), y / (yy + 1));
        ret += xx * yy * (p[i] - p[j]);
    }
    return ret;
}

long long gao(long long x, long long y, long long z) {
    if (x > y) {
        return gao(y, x, z);
    }
    if (x > z) {
        return gao(z, y, x);
    }

    long long ret = 0;
    for (long long i = x, j; i > 0; i = j) {
        long long xx = x / i, yy = y / i, zz = z / i;
        j = max(max(x / (xx + 1), y / (yy + 1)), z / (zz + 1));
        ret += xx * yy * zz * (p[i] - p[j]);
    }
    return ret;
}

int main() {
    long long x, y, z;
    long long ans;

    init();
    while (scanf("%lld%lld%lld", &x, &y, &z) != EOF) {
        --x;
        --y;
        --z;
        ans = 3;
        ans += gao(x, y);
        ans += gao(y, z);
        ans += gao(z, x);
        ans += gao(x, y, z);
        printf("%lld\n", ans);
    }

    return 0;
}

// Run ID   Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
// 375  2010-11-10 00:22:04     Accepted    I   C++     260     4084    watashi@Zodiac  Source

// 2012-09-07 15:54:50 | Accepted | 3435 | C++ | 260 | 4084 | watashi | Source

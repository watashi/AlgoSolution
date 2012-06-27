#include <cstdio>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

long long y[808], z[808];

void gao(int m, int n, long long ret[]) {
    if (m == 1) {
        copy(y, y + n + 1, ret);
    } else if (m % 2 != 0) {
        long long tmp[n + 1];
        gao(m - 1, n, tmp);
        for (int i = 0; i <= n; ++i) {
            ret[i] = 0;
            for (int j = 0; j <= i; ++j) {
                ret[i] = (ret[i] + tmp[j] * y[i - j]) % MOD;
            }
        }
    } else {
        long long tmp[n + 1];
        gao(m / 2, n, tmp);
        for (int i = 0; i <= n; ++i) {
            ret[i] = 0;
            for (int j = 0; j <= i; ++j) {
                ret[i] = (ret[i] + tmp[j] * tmp[i - j]) % MOD;
            }
        }
    }
}

int main() {
    int re;
    int m, n, d;
    long long c[100], x, xx;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%lld%d", &m, &n, &x, &d);
        for (int i = 0; i <= d; ++i) {
            scanf("%lld", &c[i]);
        }

        xx = 0;
        for (int i = 0; i <= n; ++i) {
            y[i] = 0;
            for (int j = d; j >= 0; --j) {
                y[i] = (y[i] * xx + c[j]) % MOD;
            }
            xx = (xx + x) % MOD;
        }
        gao(m, n, z);
        printf("%lld\n", z[n]);
    }

    return 0;
}


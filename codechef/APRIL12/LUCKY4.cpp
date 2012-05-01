#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 64;
const int MAXD = 12;
const llint INF = 1000000007LL;

inline llint add(llint lhs, llint rhs) {
    return min(INF, lhs + rhs);
}

inline llint mul(llint lhs, llint rhs) {
    return min(INF, lhs * rhs);
}

llint cc[MAXN][MAXN], p2[MAXD], p8[MAXD], p10[MAXD];

void init() {
    for (int i = 0; i < MAXN; ++i) {
        cc[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            cc[i][j] = cc[i - 1][j - 1] + cc[i - 1][j];
        }
    }
    p2[0] = p8[0] = p10[0] = 1;
    for (int i = 1; i < MAXD; ++i) {
        p2[i] = p2[i - 1] * 2;
        p8[i] = p8[i - 1] * 8;
        p10[i] = p10[i - 1] * 10;
    }
}

llint s[MAXD], dp[MAXN][MAXD];
int d[MAXN];

int lucky(int d) {
    return d == 4 || d == 7 ? 1 : 0;
}

int luckys(int n) {
    return n == 0 ? 0 : luckys(n / 10) + lucky(n % 10);
}

void stat(llint n, int t, int c) {
    if (t == 0) {
        ++s[c];
    } else {
        --t;
        int d = n / p10[t];
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j <= t; ++j) {
                s[c + j + lucky(i)] += cc[t][j] * p2[j] * p8[t - j];
            }
        }
        stat(n % p10[t], t, c + lucky(d));
    }
}

void stat(llint n) {
    int m = 0;
    while (p10[m] <= n) {
        ++m;
    }
    fill(s, s + MAXD, 0);
    stat(n, m, 0);
    --s[0];
}

llint calc(int i, int last, llint m) {
    llint ret = 0;
    stat(m);
    for (int j = 0; j < MAXD; ++j) {
        if (i == 0 || (d[i - 1] == 1) == (last == j)) {
            llint tmp = 0;
            for (int k = 0; k < MAXD; ++k) {
                if ((d[i] == 1) == (j == k)) {
                    tmp = add(tmp, dp[i + 1][k]);
                }
            }
            ret = add(ret, mul(tmp, s[j]));
        }
    }
    return ret;
}

int main() {
    int re, n;
    llint m, k;

    init();
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%lld%lld", &n, &m, &k);
        --k;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d", &d[i]);
        }
        d[n - 1] = 0;

        stat(m);
        fill(dp[0], dp[n + 1], 0);
        dp[n][MAXD - 1] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < MAXD; ++j) {
                for (int k = 0; k < MAXD; ++k) {
                    if ((d[i] == 1) == (j == k)) {
                        dp[i][j] = add(dp[i][j], dp[i + 1][k]);
                    }
                }
                dp[i][j] = mul(dp[i][j], s[j]);
            }
        }

        // printf("%lld\n", accumulate(dp[0], dp[0] + MAXD, 0LL));
        if (k >= accumulate(dp[0], dp[0] + MAXD, 0LL)) {
            puts("-1");
            continue;
        } else {
            llint last = -1;
            for (int i = 0; i < n; ++i) {
                llint lo = 1, hi = m + 1;
                while (lo < hi) {
                    llint mi = (lo + hi) / 2;
                    if (calc(i, last, mi) <= k) {
                        lo = mi + 1;
                    } else {
                        hi = mi;
                    }
                }
                k -= calc(i, last, hi - 1);
                last = luckys(hi);
                printf("%lld%c", hi, i == n - 1 ? '\n' : ' ');
            }
        }
    }

    return 0;
}


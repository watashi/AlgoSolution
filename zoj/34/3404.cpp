#include <cstdio>
#include <cassert>

const int MAXN = 218;

const long long MOD = 1000000007LL;

long long p[MAXN][MAXN];
long long c[MAXN][MAXN];
long long dp[MAXN][MAXN];

void init() {
    for (int i = 0; i < MAXN; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD) {
                c[i][j] -= MOD;
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] = (dp[i][j] + c[j][k] * dp[i - 1][k]) % MOD;
            }
        }
//      printf("%lld\n", dp[i][i]);
    }
    for (int i = 0; i < MAXN; ++i) {
        p[i][0] = 1;
        for (int j = 1; j < MAXN; ++j) {
            p[i][j] = (p[i][j - 1] * i) % MOD;
        }
    }
}

int main() {
    int re, n, m, a, b;
    bool mark[MAXN];
    int s[MAXN], t[MAXN];
    long long ans;

    init();
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            mark[i] = false;
            s[i] = t[i] = -1;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            assert(t[a] == -1);
            t[a] = b;
            assert(s[b] == -1);
            s[b] = a;
        }

        m = n;
        ans = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != -1) {
                continue;
            }
            int k = 0;
            for (int j = i; j != -1; j = t[j]) {
                mark[j] = true;
                ++k;
            }
//          printf("m = %d; k = %d; %lld %lld\n", m, k, c[m][k], dp[k][k]);
            ans = (ans * c[m][k]) % MOD;
            ans = (ans * dp[k][k]) % MOD;
            m -= k;
        }

        for (int i = 0; i < n; ++i) {
            if (mark[i]) {
                continue;
            }
            int k = 0;
            for (int j = i; k == 0 || j != i; j = t[j]) {
                mark[j] = true;
                ++k;
            }
            ans = (ans * c[m][k]) % MOD;
            ans = (ans * p[k][k]) % MOD;
            m -= k;
        }

        assert(m == 0);
        printf("%lld\n", ans);
    }

    return 0;
}

// 2012-09-07 15:52:17 | Accepted | 3404 | C++ | 100 | 1292 | watashi | Source

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 11;

long long ans[MAXN][MAXN];
long long dp[MAXN + 1][MAXN + 1][1 << MAXN];

void gao(int n) {
    int m = 1 << n;

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                dp[i][j + 1][k ^ (1 << j)] += dp[i][j][k];
                if (j + 1 < n && (k & (3 << j)) == 0) {
                    dp[i][j + 2][k] += dp[i][j][k];
                }
            }
        }
        for (int k = 0; k < m; ++k) {
            dp[i + 1][0][k] = dp[i][n][k];
        }
        ans[i + 1][n] = dp[i][n][0];
    }
}

int main() {
    int n, m;

    for (int i = 1; i <= MAXN; ++i) {
        gao(i);
    }
    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        printf("%lld\n", ans[min(n, m)][max(n, m)]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//251   2010-06-24 16:53:39     Accepted    1008    C++     30  2484    anotherpeg  Source

// 2012-09-30 23:37:55 | Accepted | 1100 | C++ | 10 | 2484 | watashi | Source

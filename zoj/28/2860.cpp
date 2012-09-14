#include <cstdio>

int a[1024];
int dp[1024][1024];
short pre[1024][1024];

int main() {
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF) {
        a[0] = 0;
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &a[i]);
        }
        a[m + 1] = n;
        ++m;
        for (int i = 0; i + 2 <= m; ++i) {
            dp[i][i + 2] = a[i + 2] - a[i];
            pre[i][i + 2] = i + 1;
        }
        for (int j = 3; j <= m; ++j) {
            for (int i = 0; i + j <= m; ++i) {
                dp[i][i + j] = 0x7fffffff;
                for (int k = pre[i][i + j - 1]; k <= pre[i + 1][i + j]; ++k) {
                    if (dp[i][i + j] > dp[i][k] + dp[k][i + j]) {
                        dp[i][i + j] = dp[i][k] + dp[k][i + j];
                        pre[i][i + j] = k;
                    }
                }
                dp[i][i + j] += a[i + j] - a[i];
            }
        }
        printf("%d\n", dp[0][m]);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1814335   2009-04-02 03:54:41     Accepted    2860    C++     270     6324    watashi@Zodiac

// 2012-09-07 01:43:23 | Accepted | 2860 | C++ | 240 | 6328 | watashi | Source

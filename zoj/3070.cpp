#include <cstdio>
#include <cstring>

int a[101];
int dp[101][1 << 5][5];

int main()
{
    int n, m, ans;

    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        memset(dp[0], 0, sizeof(dp[0]));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            --a[i];
            memcpy(dp[i + 1], dp[i], sizeof(dp[i + 1]));
            for (int j = 0; j < (1 << m); j++) {
                for (int k = 0; k < m; k++) {
                    if ((j & (1 << k)) == 0) {
                        continue;
                    }
                    else if (a[i] == k) {
                        // dp[i + 1][j][k] >?= dp[i][j][k] + 1;
                        if (dp[i][j][k] + 1 > dp[i + 1][j][k]) {
                            dp[i + 1][j][k] = dp[i][j][k] + 1;
                        }
                    }
                    else if ((j & (1 << a[i])) == 0) {
                        // dp[i + 1][j ^ (1 << a[i])][a[i]] >?= dp[i][j][k] + 1;
                        if (dp[i][j][k] + 1 > dp[i + 1][j ^ (1 << a[i])][a[i]]) {
                            dp[i + 1][j ^ (1 << a[i])][a[i]] = dp[i][j][k] + 1;
                        }
                    }
                }
            }
        }
        ans = 0;
        for (int k = 0; k < m; k++) {
            // ans >?= dp[n][(1 << m) - 1][k];
            if (dp[n][(1 << m) - 1][k] > ans) {
                ans = dp[n][(1 << m) - 1][k];
            }
        }
        ans = n - ans;
        printf("%d\n", ans);
    }

    return 0;
}

//1750226   2009-01-28 15:45:06       Accepted      3070    C++     0   240     watashi@Zodiac

// 2012-09-07 01:59:53 | Accepted | 3070 | C++ | 0 | 244 | watashi | Source

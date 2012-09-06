#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

int n, m;
int mp[101][101], in[101][101], dp[101][101];

int main(void)
{
    while(scanf("%d%d", &n, &m) != EOF && m + n > 0) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &mp[i][j]);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &in[i][j]);
        fill(dp[0] + 1, dp[0] + n + 1, numeric_limits<int>::min() / 2);
        dp[0][1] = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                dp[i][j] = numeric_limits<int>::min() / 2;
                for (int k = 1; k <= n; k++)
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] - mp[k][j]);
                dp[i][j] += in[i][j];
            }
        printf("%d\n", *max_element(dp[m] + 1, dp[m] + n + 1));
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2769996 2008-03-04 17:11:16 Accepted 2846 C++ 00:00.02 552K ¤ï¤¿¤·

// 2012-09-07 01:42:47 | Accepted | 2846 | C++ | 0 | 300 | watashi | Source

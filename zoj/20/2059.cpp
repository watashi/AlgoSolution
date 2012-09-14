#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;

int dp[101][2002];

int main(void)
{
    int n, s, t;

    while(scanf("%d", &n) != EOF && n >= 0) {
        dp[0][0] = 0;
        s = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &t);
            for (int j = 0; j <= s; j++)
                dp[i][j] = dp[i - 1][j];
            fill(dp[i] + s + 1, dp[i] + s + t + 1, numeric_limits<int>::min());
            for (int j = 0; j <= s; j++)
                dp[i][j + t] = max(dp[i][j + t], dp[i - 1][j]);
            for (int j = 0; j < t && j <= s; j++)
                dp[i][t - j] = max(dp[i][t - j], dp[i - 1][j] + j);
            for (int j = t; j <= s; j++)
                dp[i][j - t] = max(dp[i][j - t], dp[i - 1][j] + t);
            s += t;
        }
        if(dp[n][0] == 0) puts("Sorry");
        else printf("%d\n", dp[n][0]);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2771813 2008-03-05 22:13:38 Accepted 2059 C++ 00:00.12 1228K ¤ï¤¿¤·

// 2012-09-07 01:11:40 | Accepted | 2059 | C++ | 40 | 968 | watashi | Source

#include <cstdio>

double dp[1001][1001];

int main(void)
{
    int re, n;

    for (int i = 0; i <= 1000; i++)
        dp[0][i] = dp[i][0] = 0.0;
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) / 2.0 + 1.0;
    scanf("%d", &re);
    while(re--) {
        scanf("%d", &n);
        printf("%.2lf\n", dp[n][n]);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2813273 2008-03-31 13:07:52 Accepted 2949 C++ 00:00.04 8220K わたし

/*
数学方法：
ans := 0;
for n := N to 2 * N - 1 do
    ans := ans + n * p(n);
其中p(n)表示扔n次的概率
p(n) = 2 * (0.5 * C(N - 1, n - 1) / n!);
//p(n)可有p(n - 1)推
*/

// 2012-09-07 01:49:25 | Accepted | 2949 | C++ | 20 | 8008 | watashi | Source

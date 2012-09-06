#include <cstdio>

double dp[128][32];

int main(void)
{
    int n, m, c;
    char buf[16], pre;

    while (scanf("%d", &n) != EOF) {
        m = 0;
        c = n;
        pre = 'K';
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        while (scanf("%s", buf) != EOF) {
            if (buf[0] == 'E') {
                break;
            }
            ++m;
            for (int i = 0; i <= n; i++) {
                dp[m][i] = 0;
            }
            if (buf[0] == 'W') {
                if (pre == 'W') {
                    ++c;
                }
                else {
                    pre = 'W';
                    c = 0;
                }
                if (c >= n) {
                    dp[m][n] = 1;
                }
                else {
                    for (int i = c + 1; i <= n; i++) {
                        dp[m][i] = dp[m - 1][i - 1] * (n + 1 - i) / (n - c) + dp[m - 1][i] * (i - c) / (n - c);
                    }
                }
            }
            else {
                if (pre == 'K') {
                    ++c;
                }
                else {
                    pre = 'K';
                    c = 0;
                }
                if (c >= n) {
                    dp[m][0] = 1;
                }
                else {
                    for (int i = n - c - 1; i >= 0; i--) {
                        dp[m][i] = dp[m - 1][i + 1] * (i + 1) / (n - c) + dp[m - 1][i] * (n - c - i) / (n - c);
                    }
                }
            }
        }
        printf("%.2lf\n", dp[m][0]);
    }

    return 0;
}

//27581     2008-07-08 16:19:41       Accepted      1021    C++     0   288     watashi     Source

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3040708   2008-08-18 16:25:54     Accepted    3022    C++     00:00.00    424K    Re:ReJudge

// 2012-09-07 01:55:54 | Accepted | 3022 | C++ | 0 | 212 | watashi | Source

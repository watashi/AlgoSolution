#include <cstdio>

static long long c[12][12];
static long long dp[12];

struct RunBeforeMain
{
    RunBeforeMain()
    {
        c[0][0] = 1;
        for (int i = 1; i <= 11; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
        dp[0] = 1;
        for (int i = 1; i <= 11; i++) {
            dp[i] = 1;
            for (int j = 1; j <= i; j++) {
                dp[i] += c[i][j] * dp[i - j];
            }
        }
        //puts("gao");
    }
} __run_me;

int main(void)
{
    int re, n;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++) {
        scanf("%d", &n);
        printf("%d %d %lld\n", ri, n, dp[n] - 1);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3021753 2008-08-04 21:34:20 Accepted 2775 C++ 00:00.00 436K Re:ReJudge
//

// 2012-09-07 01:39:14 | Accepted | 2775 | C++ | 0 | 180 | watashi | Source

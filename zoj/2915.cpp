#include <cstdio>
#include <cstring>

char buf[55];
int t, m, n, q, l;
long long cnt[55];
long long dp[6][55];

int main(void)
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &m, &n, &q);
        memset(cnt, 0, sizeof(cnt));
        while(m--) {
            scanf("%s", buf);
            ++cnt[strlen(buf)];
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= 50; j++)
                for (int k = 0; k <= j; k++)
                    dp[i][j] += cnt[j - k] * dp[i - 1][k];
        while(q--) {
            scanf("%d", &l);
            printf("%lld\n", dp[n][l]);
        }
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2756986 2008-02-21 18:23:27 Accepted 2915 C++ 00:00.01 392K ¤ï¤¿¤·

// 2012-09-07 01:47:04 | Accepted | 2915 | C++ | 0 | 184 | watashi | Source

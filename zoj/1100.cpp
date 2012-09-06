#include <cstdio>

static const int bin[12] = {
    1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048
};

static bool mp[2222][2222];

void genmp(int src)
{
    static bool mk[12][2222];

    for (int i = 0; i <= 11; i++)
        for (int j = 0; j < bin[i]; j++)
            mk[i][j] = false;
    mk[0][0] = true;

    src += bin[11];
    for (int i = 0; i < 11; i++) {
        if (src & bin[i]) {
            for (int j = 0; j < bin[i]; j++ )
                if(mk[i][j])
                    mk[i + 1][j] = true;
        }
        else if (src & bin[i + 1]) {
            for (int j = 0; j < bin[i]; j++)
                if(mk[i][j])
                    mk[i + 1][j | bin[i]] = true;
        }
        else {
            for (int j = 0; j < bin[i]; j++)
                if(mk[i][j]) {
                    mk[i + 2][j] = true;
                    mk[i + 1][j | bin[i]] = true;
                }
        }
    }
    src -= bin[11];

    for (int j = 0; j < bin[11]; j++)
        mp[src][j] = mk[11][j];
}

int main(void)
{
    static long long dp[12][2222];
    int m, n, mask;

    for (int i = 0; i < bin[11]; i++)
        genmp(i);
    while(scanf("%d%d", &m, &n) != EOF && m > 0 && n > 0) {
        for (int i = 0; i <= m; i++)
            for (int j = 0; j < bin[n]; j++)
                dp[i][j] = 0;
        dp[0][0] = 1;
        mask = (bin[11] - 1) ^ (bin[n] - 1);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < bin[n]; j++)
                for (int k = 0; k < bin[n]; k++) {
                    if(mp[j | mask][k])
                        dp[i + 1][k] += dp[i][j];
                }
        printf("%lld\n", dp[m][0]);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2834796   2008-04-09 21:43:08     Accepted    1100    C++     00:01.60    5448K   わたし

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//18442     2008-04-16 20:28:28     Accepted    1008    C++     670     5564    watashi

// 2012-09-07 00:36:51 | Accepted | 1100 | C++ | 720 | 5236 | watashi | Source

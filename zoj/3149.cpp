#include <cstdio>
#include <algorithm>

using namespace std;

const long long ov = 1234567890LL;

long long Cnt(int n)
{
    long long ret = 0;

    for (int i = 0; i < n; i++) {
        ret += i;
        if(ret > ov)
            break;
    }

    return ret;
}

long long Dp(int n, int k)
{
    static long long dp[64];

    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = i;
        for (int j = max(0, i - k); j < i; j++)
            dp[i] += dp[j];
        if(dp[i] > ov)
            return dp[i];
    }

    return dp[n - 1];
}

int main(void)
{
    int n, k;

    while(scanf("%d%d", &n, &k) != EOF && n > 0) {
        if(k == 0)
            printf("%lld\n", min(n - 1LL, ov + 1LL));
        else if(k == 1)
            printf("%lld\n", Cnt(n));
        else
            printf("%lld\n", Dp(n, k));
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1748030   2009-01-24 17:28:57     Accepted    3149    C++     0   176     watashi@Zodiac

// 2012-09-07 02:03:40 | Accepted | 3149 | C++ | 0 | 180 | watashi | Source

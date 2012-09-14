#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 1024;
const long long MOD = 1000000007;

long long dp[MAXN][MAXN];

int main() {
    int n;
    char s[MAXN];

    while (scanf("%s", s) != EOF) {
        n = strlen(s);
        fill(dp[0], dp[n + 1], 0LL);
        dp[0][0] = 1LL;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 0LL;
            copy(dp[i - 1], dp[i - 1] + i, dp[i] + 1);
            if (s[i - 1] == 'D') {
                reverse(dp[i] + 1, dp[i] + i + 1);
            }
            partial_sum(dp[i], dp[i] + i + 1, dp[i]);
            if (s[i - 1] == 'D') {
                reverse(dp[i], dp[i] + i + 1);
            } else if (s[i - 1] == '?') {
                fill(dp[i], dp[i] + i + 1, dp[i][i]);
            }
            transform(dp[i], dp[i] + i + 1, dp[i], bind2nd(modulus<long long>(), MOD));
        }
        printf("%lld\n", accumulate(dp[n], dp[n] + n + 1, 0LL) % MOD);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2675328   2011-10-02 20:09:33     Accepted    3543    C++     1470    8372    watashi     Source

// 2012-09-07 16:04:56 | Accepted | 3543 | C++ | 1450 | 8372 | watashi | Source

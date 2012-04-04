#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const long long MOD = 1000000007;

long long dp[MAXN][MAXN * 26];

int main() {
    int re, n, m;
    char s[MAXN];

    scanf("%d", &re);
    dp[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 0; j < MAXN * 26; ++j) {
            for (int k = 0; k <= j && k < 26; ++k) {
                dp[i][j] += dp[i - 1][j - k];
            }
            dp[i][j] %= MOD;
        }
    }
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%s", s);
        n = strlen(s);
        m = 0;
        for (int i = 0; i < n; ++i) {
            m += s[i] - 'a';
        }
        printf("%d\n", (int)((dp[n][m] + MOD - 1) % MOD));
    }

    return 0;
}


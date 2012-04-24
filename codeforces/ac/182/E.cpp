#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 218;
const int MAXM = 3200;
const long long MOD = 1000000007LL;

int a[MAXN], b[MAXN];
long long dp[MAXM][MAXN];

int main() {
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        ++dp[a[i]][i];
        if (a[i] != b[i]) {
            a[n + i] = b[i];
            b[n + i] = a[i];
            ++dp[a[n + i]][n + i];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < n + n; ++j) {
            if (dp[i][j] == 0) {
                continue;
            }
            dp[i][j] %= MOD;
            for (int k = 0; k < n + n; ++k) {
                if (j % n != k % n && a[k] == b[j]) {
                    dp[i + a[k]][k] += dp[i][j];
                }
            }
        }
    }
    printf("%d\n", (int)(accumulate(dp[m], dp[m] + n + n, 0LL) % MOD));

    return 0;
}


#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 4096;
const int SEC_OF_DAY = 86400;

int t[MAXN], d[MAXN], dp[MAXN];

int main() {
    int n, m, ans;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", t + i, d + i);
    }
    t[n] = SEC_OF_DAY + 1;
    ans = t[m] - 1;
    fill(dp, dp + m + 1, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= 0; --j) {
            dp[j] = max(dp[j], t[i]) + d[i];
            if (j > 0 && dp[j] > dp[j - 1]) {
                dp[j] = dp[j - 1];
            }
            ans = max(ans, t[min(i + m - j + 1, n)] - dp[j]);
        }
    }
    printf("%d\n", ans);

    return 0;
}


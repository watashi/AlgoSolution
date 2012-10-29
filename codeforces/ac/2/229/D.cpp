#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 5050;
const int INF = 1000000007;

int a[MAXN];
int s[MAXN];
int dp[MAXN][MAXN];

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    partial_sum(a, a + n, s);
    fill(dp[0], dp[n], INF);
    for (int i = 0; i < n; ++i) {
        dp[i][0] = -INF;
        dp[i][1] = s[i];
        for (int j = 0, k = 0; j < i; ++j) {
            while (dp[j][k] <= s[i] - s[j]) {
                ++k;
            }
            if (k > 1 && dp[j][k - 1] <= s[i] - s[j]) {
                dp[i][k] = min(dp[i][k], s[i] - s[j]);
            }
        }
        for (int j = n; j >= 0; --j) {
            dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        }
    }
    printf("%d\n", (dp[n - 1] + n + 1) - find(dp[n - 1], dp[n], INF));

    return 0;
}


#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int l, n;
    int a[108];
    int t[26][26];
    int dp[108][26];
    int pre[108][26];
    char ans[108];

    while (scanf("%d%d", &l, &n) != EOF) {
        for (int i = 1; i < l; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &t[i][j]);
            }
        }
        fill(dp[0], dp[0] + n, 0);
        for (int i = 1; i < l; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = 0x7fffffff;
                for (int k = 0; k < n; ++k) {
                    if (dp[i][j] > dp[i - 1][k] + abs(a[i] - t[k][j])) {
                        dp[i][j] = dp[i - 1][k] + abs(a[i] - t[k][j]);
                        pre[i][j] = k;
                    }
                }
            }
        }
        int k = min_element(dp[l - 1], dp[l - 1] + n) - dp[l - 1];
        fprintf(stderr, "%d\n", dp[l - 1][k]);
        ans[l] = '\0';
        for (int i = l - 1; i >= 0; --i) {
            ans[i] = 'a' + k;
            k = pre[i][k];
        }
        puts(ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1816410   2009-04-03 11:12:21     Accepted    2565    C++     0   176     watashi@Zodiac

// 2012-09-07 01:28:59 | Accepted | 2565 | C++ | 0 | 180 | watashi | Source

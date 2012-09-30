#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 128;

int main() {
    int re, n, m;
    int a[MAXN], b[MAXN], dp[MAXN][MAXN];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            dp[i + 1][0] = 0;
        }
        for (int j = 0; j < m; ++j) {
            scanf("%d", &b[j]);
            dp[0][j + 1] = 0;
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int pi = i - 2, pj = j - 2;
                while (pi >= 0 && a[pi] != b[j - 1]) {
                    --pi;
                }
                while (pj >= 0 && b[pj] != a[i - 1]) {
                    --pj;
                }
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (pi >= 0 && pj >= 0 && a[i - 1] != b[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[pi][pj] + 1);
                }
            }
        }
        printf("%d\n", 2 * dp[n][m]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//272   2010-06-25 23:08:53     Accepted    1031    C++     10  180     anotherpeg  Source

// 2012-09-30 23:40:28 | Accepted | 1425 | C++ | 0 | 180 | watashi | Source

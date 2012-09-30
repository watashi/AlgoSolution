#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 256;

int main() {
    int ri = 0, n, ans, sum[MAXN];
    int dp[MAXN][MAXN];
    char buf[MAXN][MAXN];

    sum[0] = 0;
    for (int i = 1; i < MAXN; ++i) {
        sum[i] = sum[i - 1] + i + i - 1;
    }
    while (scanf("%d", &n) != EOF && n > 0) {
        for (int i = n - 1; i >= 0; --i) {
            scanf("%s", buf[i]);
        }
        ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < i + i + 1; j += 2) {
                if (buf[i][j] == '#') {
                    dp[i][j] = 0;
                } else if (buf[i - 1][j - 1] == '-' && 0 <= j - 2 && j < i + i - 1) {
                    dp[i][j] = min(dp[i - 1][j - 2], dp[i - 1][j]) + 1;
                } else {
                    dp[i][j] = 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < i + i + 1; j += 2) {
                if (buf[i][j] == '#') {
                    dp[i][j] = 0;
                } else if (i + 1 < n && buf[i + 1][j + 1] == '-') {
                    dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 2]) + 1;
                } else {
                    dp[i][j] = 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        printf("Triangle #%d\nThe largest triangle area is %d.\n\n", ++ri, sum[ans]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//296   2010-06-27 07:12:35     Accepted    1021    C++     0   180     anotherpeg  Source

// 2012-09-30 23:39:18 | Accepted | 1245 | C++ | 0 | 180 | watashi | Source

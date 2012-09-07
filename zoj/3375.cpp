#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 16;

/*
int gao(int a, int b, int x, int y) {
    static int dp[60][60];
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            // PV = j * b, TV = i * a
            if (i < x) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + j * b);
            }
            if (j < y) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + i * a);
            }
        }
    }
    return dp[x][y];
}
*/

int a[MAXN], b[MAXN], x[MAXN], y[MAXN];
int d[MAXN];
int dp[1 << MAXN];

int main() {
    int n;
    int pv, tv;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &a[i], &b[i], &x[i], &y[i]);
            // d[i] = gao(a[i], b[i], x[i], y[i]);
            d[i] = x[i] * y[i] * max(a[i], b[i]);   // greedy
        }
        fill(dp, dp + (1 << n), 0);
        for (int i = 1; i < (1 << n); ++i) {
            pv = tv = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    pv += b[j] * y[j];
                    tv += a[j] * x[j];
                }
            }
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    dp[i] = max(dp[i],
                        dp[i ^ (1 << j)] +
                        (pv - b[j] * y[j]) * x[j] +
                        (tv - a[j] * x[j]) * y[j] +
                        d[j]);
                }
            }
        }
        printf("%d\n", dp[(1 << n) - 1]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1095  2010-07-27 15:49:16     Accepted    1137    C++     400     724     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//216   2010-08-12 15:06:06     Accepted    furan   C++     190     432     watashi@Zodiac  Source

// 2012-09-07 15:50:12 | Accepted | 3375 | C++ | 200 | 436 | watashi | Source

#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cstring>

unsigned dp[9][1 << 18];
unsigned ans[9][9];

// b
// a
//
//  9 8 7 6 5
// - 3 2 1 0
//
//  9 8 7 6 -
// 4 3 2 1 0

void init(const int n) {
    const int m = n + 1, mm = (1 << m) - 1;
    int a, b, s;

    memset(dp, 0, sizeof(dp));
    dp[1][(1 << (m + m)) - 2] = 1;
    for (int i = 1; i <= 8; ++i) {
        for (int j = 0; j < (1 << (m + m)); ++j) {
            if (dp[i][j] == 0) {
                continue;
            }

            a = j >> m;
            b = j & mm;
            if (b != 0 && b == (b & (
                    (a & (a << 1)) |            // 2
                    (a & (b << 1)) |            // 4.1
                    ((a << 1) & (b >> 1))       // 4.2
                    ))) {
                ans[n][i] += dp[i][j];
            }

            if (i == 8) {
                continue;
            }

            s = (i & 1) ? (1 << m) : (1 << n);
            for (int c = 1; c < s; ++c) {
                if (b == (b & (
                        (a & (a << 1)) |                // 2
                        (a & c & ~(c << 1)) |           // 3.1
                        ((a << 1) & (c << 1) & ~c) |    // 3.2
                        (a & (b << 1)) |                // 4.1
                        ((a << 1) & (b >> 1))           // 4.2
                        ))) {
                    if (i & 1) {
                        dp[i + 1][(b << n) ^ c] += dp[i][j];
                    } else {
                        dp[i + 1][(b << m) ^ (c << 1)] += dp[i][j];
                    }
                }
            }
        }
    }
}

int main() {
    int m, n;

    for (int i = 1; i <= 8; ++i) {
        init(i);
    }
    while (scanf("%d%d", &m, &n) != EOF) {
        printf("%u\n", ans[m][n]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//508   2010-07-08 13:35:30     Accepted    asc11b  C++     1070    9396    anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//172   2010-07-08 14:37:24     Accepted    asc11b  C++     850     9392    watashi@Zodiac  Source

// 2012-09-07 15:48:57 | Accepted | 3363 | C++ | 720 | 9396 | watashi | Source

#include <cmath> // auto fix CE
#include <cstdio>
#include <cmath> // auto fix CE
#include <cstdlib>
#include <cmath> // auto fix CE
#include <cassert>
#include <cmath> // auto fix CE
#include <algorithm>

using namespace std;

const int MAXR = 9;
const int MAXM = 52;
const int INF = 1000000000;

int isqrt[100];

void init() {
    for (int i = 0; i < 10; ++i) {
        for (int j = i * i; j < (i + 1) * (i + 1); ++j) {
            isqrt[j] = i;
        }
    }
}

int dp[2][MAXM][MAXM];

int main() {
    int l, r, n, p;
    int pre, cur;

    init();
    while (scanf("%d%d%d", &l, &r, &n) != EOF) {
        assert(0 <= l && l < MAXM);
        assert(0 <= r && r < MAXM);
        assert(1 <= n && n < 1024);

        cur = 0;
        fill(dp[cur][0], dp[cur][MAXM], INF);
        dp[cur][l][r] = 0;

        for (int k = 0; k < n; ++k) {
            scanf("%d", &p);
            pre = cur;
            cur = 1 - pre;
            fill(dp[cur][0], dp[cur][MAXM], INF);
            for (int i = 0; i < MAXM; ++i) {
                for (int j = 0; j < MAXM; ++j) {
                    if (dp[pre][i][j] == INF) {
                        continue;
                    }
                    for (int k = p; k < p + MAXR && k < MAXM; ++k) {
                        dp[cur][k][j] = min(dp[cur][k][j], dp[pre][i][j] + isqrt[abs(i - k)]);
                    }
                    for (int k = p; k > p - MAXR && k >= 0; --k) {
                        dp[cur][i][k] = min(dp[cur][i][k], dp[pre][i][j] + isqrt[abs(j - k)]);
                    }
                }
            }
        }

        printf("%d\n", *min_element(dp[cur][0], dp[cur][MAXM]));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1248  2010-07-31 20:33:31     Accepted    1149    C++     1130    200     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//695   2011-01-30 15:43:05     Accepted    G   C++     930     200     watashi@ArcOfDream  Source

// 2012-09-07 15:58:38 | Accepted | 3463 | C++ | 920 | 200 | watashi | Source

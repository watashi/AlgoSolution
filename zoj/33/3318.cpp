#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 32;
const int INF = 0x01010101;

int dijkstra(int n, int s, int t, bool e[MAXN][MAXN]) {
    static int d[MAXN], q[MAXN];
    memset(d, 0x01, sizeof(d));
    d[s] = 0;
    q[0] = s;
    for (int i = 0, k = 1; i < k; ++i) {
        s = q[i];
        for (int j = 0; j < n; ++j) {
            if (e[s][j] && d[j] == INF) {
                d[j] = d[s] + 1;
                q[k++] = j;
            }
        }
    }
    return d[t];
}

int main() {
    int re, n, m, s, t, r, a, b;
    bool w[MAXN][MAXN][MAXN];
    bool e[MAXN][MAXN];
    int f[MAXN][MAXN];
    int dp[MAXN];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d%d", &n, &m, &s, &t);
        --s;
        --t;
        memset(w, false, sizeof(w));
        memset(dp, 0xff, sizeof(dp));
        for (int i = 0; i < m; ++i) {
            scanf("%d", &r);
            for (int j = 0; j < r; ++j) {
                scanf("%d%d", &a, &b);
                w[i][a - 1][b - 1] = w[i][b - 1][a - 1] = true;
            }
        }
        for (int i = 0; i < m; ++i) {
            memset(e, true, sizeof(e));
            for (int j = i; j < m; ++j) {
                if (j == i || f[i][j] < INF) {
                    for (int x = 0; x < n; ++x) {
                        for (int y = 0; y < n; ++y) {
                            e[x][y] &= w[j][x][y];
                        }
                    }
                    f[i][j + 1] = dijkstra(n, s, t, e);
                } else {
                    f[i][j + 1] = INF;
                }
            }
        }
        memset(dp, 0x01, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = min(dp[i], dp[j] + f[j][i] * (i - j) + 1);
            }
        }
        printf("%d\n", dp[m] - 1);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2159746   2010-04-13 21:16:58     Accepted    3318    C++     40  216     watashi@Zodiac

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2159758   2010-04-13 21:20:18     Accepted    3318    C++     40  176     watashi@Zodiac

// 2012-09-07 02:07:26 | Accepted | 3318 | C++ | 40 | 180 | watashi | Source

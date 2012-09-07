#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 1024;
const int MAXM = 24;
const int INF = 1000000007;

int n, m, v[MAXN];
vector<int> e[MAXN];
int d[MAXN], dp[MAXN][MAXM];

void gao(int s, int p) {
    e[s].erase(remove(e[s].begin(), e[s].end(), p), e[s].end());
    d[s] = 0;
    dp[s][0] = 0;
    fill(dp[s] + 1, dp[s] + 1 + m, INF);
    for (vector<int>::const_iterator t = e[s].begin(); t != e[s].end(); ++t) {
        gao(*t, s);
        d[s] += d[*t] + 1;
        for (int j = m; j >= 0; --j) {
            dp[s][j] += dp[*t][0];
            for (int k = j - 1; k >= 0; --k) {
                dp[s][j] = min(dp[s][j], dp[s][k] + dp[*t][j - k]);
            }
            for (int k = 1; k <= d[*t] + 1 && k <= j; ++k) {    // !!!
                dp[s][j] = min(dp[s][j], dp[s][j - k]);
            }
        }
    }
    transform(dp[s], dp[s] + 1 + m, dp[s], bind2nd(plus<int>(), v[s]));
}

int gao() {
    int y = INF;

    gao(0, -1);
    y = min(y, dp[0][m]);
    if (m > 0) {
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= n - d[i] - 1 && j <= m; ++j) { // !!!
                y = min(y, dp[i][m - j]);
            }
        }
    }

    return y;
}

int main() {
    int a, b;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
            e[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &a, &b);
            --a;
            --b;
            e[a].push_back(b);
            e[b].push_back(a);
        }

        printf("%d ", gao());
        for (int i = 0; i < n; ++i) {
            v[i] = -v[i];
        }
        printf("%d\n", -gao());
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//748   2011-04-27 04:57:21     Accepted    G   C++     40  296     watashi@ArcOfDream  Source

// 2012-09-07 16:03:06 | Accepted | 3506 | C++ | 40 | 296 | watashi | Source

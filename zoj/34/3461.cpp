#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 16;
const int MAXM = 1 << MAXN;
const int INF = 1 << 20;

int sum[MAXM], mst[MAXM], dp[MAXM];
vector<pair<int, int> > e[MAXN];

int partialTransfer(int n, int m) {
    int ret = 0;
    static bool mark[MAXN];
    static int mind[MAXN];

    for (int i = 0; i < n; ++i) {
        if ((1 << i) & m) {
            mark[i] = false;
            mind[i] = INF;
        } else {
            mark[i] = true;
            mind[i] = 0;
        }
    }

    mind[__builtin_ctz(m)] = 0;
    for (int i = n - __builtin_popcount(m); i < n; ++i) {
        int k = -1;
        for (int j = 0; j < n; ++j) {
            if (!mark[j] && (k == -1 || mind[j] < mind[k])) {
                k = j;
            }
        }
        mark[k] = true;
        ret += mind[k];
        for (vector<pair<int, int> >::const_iterator it = e[k].begin(); it != e[k].end(); ++it) {
            if (!mark[it->first] && it->second < mind[it->first]) {
                mind[it->first] = it->second;
            }
        }
    }

    return min(INF, ret);
}

int main() {
    int n, m, a, b, c, w[MAXN];

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &w[i]);
            e[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            e[a].push_back(make_pair(b, c));
            e[b].push_back(make_pair(a, c));
        }

        m = 1 << n;
        sum[0] = 0;
        for (int k = 1; k < m; ++k) {
            sum[k] = sum[k & (k - 1)] + w[__builtin_ctz(k)];
        }
        // mst[0] = 0;
        for (int k = 1; k < m; ++k) {
            mst[k] = sum[k] == 0 ? partialTransfer(n, k) : INF;
        }

        dp[0] = 0;
        fill(dp + 1, dp + m, INF);
        for (int k = 1; k < m; ++k) {
            if (sum[k] != 0) {
                continue;
            }
            for (int i = k; i != 0; i = (i - 1) & k) {
                dp[k] = min(dp[k], dp[k ^ i] + mst[i]);
            }
        }

        if (dp[m - 1] == INF) {
            puts("Impossible");
        } else {
            printf("%d\n", dp[m - 1]);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//690   2011-01-30 14:25:37     Accepted    E   C++     120     948     watashi@ArcOfDream  Source

// 2012-09-07 15:58:25 | Accepted | 3461 | C++ | 120 | 948 | watashi | Source

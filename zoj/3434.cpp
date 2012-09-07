#include <vector>
#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN = 22;
const int MAXM = 100100;
const int MAXL = 1 << 20;

vector<int> p[MAXL];

bool ok[MAXL];
long long dp[MAXL];

int main() {
    int re;
    int n, m, l, a, b;
    long long ans;

    for (int i = 2; i < MAXL; ++i) {
        if (p[i].empty()) {
            for (int j = i; j < MAXL; j += i) {
                p[j].push_back(i);
            }
        }
    }

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d", &n, &m, &l);

        fill(ok, ok + l + 1, false);
        ok[0] = true;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            for (int j = a; j <= l; ++j) {
                ok[j] |= ok[j - a];
            }
        }

        fill(dp, dp + l + 1, 0);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &b);
            ++dp[b];
        }
        for (int i = 2; i <= l; ++i) {
            for (int j = 0; j < (int)p[i].size(); ++j) {
                dp[i] += dp[i / p[i][j]];
            }
        }

        ans = 0;
        for (int i = 1; i <= l; ++i) {
            if (ok[i]) {
                // printf("%d %lld\n", i, dp[i]);
                ans += dp[i];
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}

// Run ID   Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
// 374  2010-11-10 00:18:09     Accepted    H   C++     1950    45972   watashi@Zodiac  Source

// 2012-09-07 15:54:44 | Accepted | 3434 | C++ | 1900 | 45972 | watashi | Source

#include <queue>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10086;
const int MAXM = 512;
const int INF = 0x7fffffff / 3;

int t[MAXN], d[MAXM][MAXM];
vector<pair<int, int> > e[MAXM];

int main() {
    int ri = 0;
    int n, m, l, q, a, b, c, ans;

    while (scanf("%d%d%d", &n, &m, &l) == 3) {
        assert(0 < n && n <= 10000);
        assert(0 < m && m <= 500);
        assert(0 < l && l <= 10000);
        fprintf(stderr, "%d %d %d\n", n, m, l);
        for (int i = 0; i < n; ++i) {
            assert(scanf("%d", &t[i]) == 1);
            assert(1 <= t[i] && t[i] <= m);
            --t[i];
        }
        for (int i = 0; i < m; ++i) {
            e[i].clear();
        }
        for (int i = 0; i < l; ++i) {
            assert(scanf("%d%d%d", &a, &b, &c) == 3);
            assert(1 <= a && a <= m);
            assert(1 <= b && b <= m);
            assert(0 <= c && c <= 500);
            --a;
            --b;
            e[a].push_back(make_pair(b, c));
            e[b].push_back(make_pair(a, c));
        }

        for (int i = 0; i < m; ++i) {
            fill(d[i], d[i] + m, INF);
            d[i][i] = 0;

            priority_queue<pair<int, int> > q;
            q.push(make_pair(-d[i][i], i));
            while (!q.empty()) {
                int y = -q.top().first;
                int x = q.top().second;
                q.pop();
                if (y != d[i][x]) {
                    continue;
                }
                // printf("%d -> %d: %d\n", i, x, y);
                for (vector<pair<int, int> >::const_iterator it = e[x].begin(); it != e[x].end(); ++it) {
                    if (d[i][it->first] > y + it->second) {
                        d[i][it->first] = y + it->second;
                        q.push(make_pair(-d[i][it->first], it->first));
                    }
                }
            }
        }

        scanf("%d", &q);
        printf("Case #%d\n", ++ri);
        for (int i = 0; i < q; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            assert(1 <= a && a <= n);
            assert(1 <= b && b <= n);
            assert(1 <= c && c <= n);
            a = t[a - 1];
            b = t[b - 1];
            c = t[c - 1];
            ans = INF;
            for (int j = 0; j < m; ++j) {
                ans = min(ans, d[j][a] + d[j][b] + d[j][c]);
            }
            printf("Line %d: ", i + 1);
            if (ans < INF) {
                printf("The minimum cost for this line is %d.\n", ans);
            } else {
                puts("Impossible to connect!");
            }
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//577   2010-07-16 19:42:36     Accepted    1066    C++     1940    1516    anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//274   2010-08-30 17:42:03     Accepted    A   C++     1470    1516    watashi@Zodiac  Source

// 2012-09-07 15:51:28 | Accepted | 3396 | C++ | 1430 | 1512 | watashi | Source

#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, int> Edge;

const int MAXN = 128;
const int INF = 1000000007;

int r, c, x[6], y[6], z[6];
int dp[1 << 6];
vector<Edge> e[MAXN];

inline int id(int i, int j) { return i * (c + 1) + j; }
inline int row(int i) { return i / (c + 1); }
inline int col(int i) { return i % (c + 1); }

void gao(int m, int n, int s) {
    static int d[MAXN][1 << 6];
    priority_queue<pair<int, int> > pq;

    fill(d[0], d[m], INF);
    d[s][0] = 0;
    pq.push(make_pair(0, (s << 6) ^ 0));
    while (!pq.empty()) {
        int x = pq.top().second >> 6;
        int y = pq.top().second & 0x3f;
        int z = -pq.top().first;
        pq.pop();
        if (z != d[x][y]) {
            continue;
        }
        for (vector<Edge>::const_iterator it = e[x].begin(); it != e[x].end(); ++it) {
            int xx = it->first.first;
            int yy = y ^ it->first.second;
            int zz = z + it->second;
            if (d[xx][yy] > zz) {
                d[xx][yy] = zz;
                pq.push(make_pair(-zz, (xx << 6) ^ yy));
            }
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        dp[i] = min(dp[i], d[s][i]);
    }
}

int main() {
    int n, m, f, ans;

    while (scanf("%d%d", &r, &c) != EOF) {
        m = (r + 1) * (c + 1);
        for (int k = 0; k < m; ++k) {
            e[k].clear();
        }
        for (int i = 0; i <= r; ++i) {
            for (int j = 0; j < c; ++j) {
                scanf("%d", &f);
                e[id(i, j)].push_back(make_pair(make_pair(id(i, j + 1), 0), f));
                e[id(i, j + 1)].push_back(make_pair(make_pair(id(i, j), 0), f));
            }
            if (i == r) {
                break;
            }
            for (int j = 0; j <= c; ++j) {
                scanf("%d", &f);
                e[id(i, j)].push_back(make_pair(make_pair(id(i + 1, j), 0), f));
                e[id(i + 1, j)].push_back(make_pair(make_pair(id(i, j), 0), f));
            }
        }

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &z[i], &x[i], &y[i]);
            for (int k = 0; k < m; ++k) {
                for (vector<Edge>::iterator it = e[k].begin(); it != e[k].end(); ++it) {
                    if (row(k) == row(it->first.first) &&
                        row(k) <= x[i] &&
                        min(col(k), col(it->first.first)) == y[i]) {
                        it->first.second ^= 1 << i;
                    }
                }
            }
        }


        fill(dp, dp + (1 << n), INF);
        for (int k = 0; k < m; ++k) {
            gao(m, n, k);
        }

        ans = INF;
        for (int i = (1 << n); i >= 0; --i) {
            f = dp[i];
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    if (z[j] < 0) {
                        f = INF;
                    } else {
                        f -= z[j];
                    }
                } else if (z[j] == 0) {
                    f = INF;
                }
            }
            ans = min(ans, f);
            for (int j = i; j > 0; j = (j - 1) & i) {
                dp[i ^ j] = min(dp[i ^ j], dp[i] + dp[j]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//712   2011-02-10 00:46:50     Accepted    J   C++     1750    212     watashi@ArcOfDream  Source

// 2012-09-07 15:59:57 | Accepted | 3476 | C++ | 1730 | 212 | watashi | Source

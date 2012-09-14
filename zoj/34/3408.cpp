#include <vector> // auto fix CE
#include <utility> // auto fix CE
#include <vector> // auto fix CE
#include <queue>
#include <vector> // auto fix CE
#include <utility> // auto fix CE
#include <vector> // auto fix CE
#include <cstdio>
#include <vector> // auto fix CE
#include <utility> // auto fix CE
#include <vector> // auto fix CE
#include <algorithm>

using namespace std;

const int MAXN = 10086;
const int INF = 1000000000;
const long long MOD = 10000000000LL;

inline long long add(long long lhs, long long rhs) {
    lhs += rhs;
    if (lhs >= MOD) {
        lhs -= MOD;
    }
    return lhs;
}

inline long long mul(long long lhs, long long rhs) {
    long long lhs2 = lhs % 100000;
    long long rhs2 = rhs % 100000;
    return ((lhs / 100000 * rhs2 + rhs / 100000 * lhs2) * 100000 + lhs2 * rhs2) % MOD;
}

bool spfa(int n, int s, vector<pair<int, int> > e[MAXN], int mind[MAXN]) {
    static bool mark[MAXN];
    static int d[MAXN], sd;
    deque<int> q;

    fill(mind, mind + n, INF);
    fill(mark, mark + n, false);
    fill(d, d + n, 0);
    mind[s] = 0;
    mark[s] = true;
    q.push_front(s);
    sd = 0;

    while (!q.empty()) {
        while (d[q.front()] * (int)q.size() > sd) { /* LLL */
            q.push_back(q.front());
            q.pop_front();
        }
        s = q.front();
        mark[s] = false;
        q.pop_front();
        sd -= d[s];
        for (vector<pair<int, int> >::const_iterator i = e[s].begin(); i != e[s].end(); ++i) {
            if (mind[i->first] > mind[s] + i->second) {
                mind[i->first] = mind[s] + i->second;
                if (mark[i->first]) {
                    sd -= d[i->first];
                } else {
                    mark[i->first] = true;
                    if (q.empty() || d[i->first] <= d[q.front()]) { /* SLF */
                        q.push_front(i->first);
                    } else {
                        q.push_back(i->first);
                    }
                }
                d[i->first] = d[s] + 1;
                sd += d[i->first];
            }
        }
    }

    return true;
}

template<typename T>
struct Indexer {
    const T* const p;
    Indexer(const T* p) : p(p) { }
    bool operator()(int lhs, int rhs) { return p[lhs] < p[rhs]; }
};

int main() {
    int n, m, q, a, b, c;
    int mind[MAXN], ord[MAXN];
    long long s[MAXN], t[MAXN];
    vector<pair<int, int> > e[MAXN];

    while (scanf("%d%d%d", &n, &m, &q) != EOF) {
        for (int i = 0; i < n; ++i) {
            ord[i] = i;
            e[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            e[a].push_back(make_pair(b, c));
        }

        spfa(n, 0, e, mind);

        sort(ord, ord + n, Indexer<int>(mind));
        fill(s, s + n, 0);
        s[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (vector<pair<int, int> >::const_iterator j = e[ord[i]].begin(); j != e[ord[i]].end(); ++j) {
                if (mind[j->first] == mind[ord[i]] + j->second) {
                    s[j->first] = add(s[j->first], s[ord[i]]);
                }
            }
        }

        reverse(ord, ord + n);
        fill(t, t + n, 1);
        for (int i = 0; i < n; ++i) {
            for (vector<pair<int, int> >::const_iterator j = e[ord[i]].begin(); j != e[ord[i]].end(); ++j) {
                if (mind[j->first] == mind[ord[i]] + j->second) {
                    t[ord[i]] = add(t[ord[i]], t[j->first]);
                }
            }
        }

        for (int i = 0; i < q; ++i) {
            scanf("%d", &a);
            printf("%010lld\n", mind[a] == INF ? 0LL : mul(s[a], t[a]));
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//933   2010-07-22 21:41:28     Accepted    1112    C++     130     1020    anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//316   2010-10-05 22:25:26     Accepted    C   C++     80  1020    watashi@Zodiac  Source

// 2012-09-07 15:52:42 | Accepted | 3408 | C++ | 70 | 1020 | watashi | Source

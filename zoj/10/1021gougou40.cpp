#include <algorithm> // auto fix CE
#include <set>
#include <algorithm> // auto fix CE
#include <list>
#include <algorithm> // auto fix CE
#include <queue>
#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <utility>
// #include <cassert>

using namespace std;

const int MAXN = 64;

list<pair<int, int> > e[MAXN];

int main() {
    int re, n, m, a, b;
    set<int> sy;
    int x[MAXN], y[MAXN], z[MAXN], h[MAXN], xx, yy, zz;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            e[i].clear();
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
            z[i] += y[i];
            h[i] = -1;
        }
        scanf("%d", &m);
        sy.clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &xx, &yy, &zz);
            zz += xx;
            a = b = -1;
            for (int j = 0; j < n; ++j) {
                if (y[j] <= yy && yy <= z[j]) {
                    if (x[j] == xx - 1) {
                        a = j;
                    } else if (x[j] == zz) {
                        b = j;
                    }
                }
            }
            sy.insert(yy);
            e[a].push_back(make_pair(yy, b));
            e[b].push_back(make_pair(yy, a));
        }
        scanf("%d%d", &xx, &yy);
        sy.insert(yy);
        if (y[xx - 1] <= yy && yy <= z[xx - 1]) {
            e[xx - 1].push_back(make_pair(yy, -2));
        }
        for (int i = 0; i < n; ++i) {
            for (set<int>::const_iterator j = sy.lower_bound(y[i]); j != sy.end() && *j < z[i]; ++j) {
                e[i].push_back(make_pair(*j, i));
            }
            e[i].push_back(make_pair(z[i], i));
            e[i].push_back(make_pair(y[i], -1));    // <- 水是会溢出的！！！
            e[i].sort();
            e[i].reverse();
            while (!e[i].empty() && e[i].front().first > z[i]) {
                e[i].pop_front();
            }
            while (!e[i].empty() && e[i].back().first < y[i]) {
                e[i].pop_back();
            }
        }

        bool flag = false;
        priority_queue<pair<int, int> > pq;
        zz = 0;
        h[0] = z[0];
        pq.push(make_pair(h[0], 0));
        while (!pq.empty()) {
            b = pq.top().first;
            a = pq.top().second;
            pq.pop();
            if (a == -1) {
                break;
            } else if (a == -2) {
                flag = true;
                break;
            }
            zz += h[a] - b;
            h[a] = b;
            // printf("@%d %d->%d\n", zz, a, b);

            // assert(e[a].empty() || e[a].front().first >= h[a]);
            while (!e[a].empty() && e[a].front().first == h[a]) {
                b = e[a].front().second;
                if (b < 0) {
                    // printf("\tadd [yy=%d, %d]\n", e[a].front().first, e[a].front().second);
                    pq.push(e[a].front());
                } else if (h[b] == -1) {
                    // printf("\tadd [%d, %d]\n", z[b], b);
                    h[b] = z[b];
                    pq.push(make_pair(h[b], b));
                }
                e[a].pop_front();
            }
            if (!e[a].empty()) {
                // printf("\tup [%d, %d]\n", e[a].front().first, a);
                pq.push(make_pair(e[a].front().first, a));
            }
        }

        if (flag) {
            printf("%d\n", zz);
        } else {
            puts("No Solution");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//352   2010-07-02 05:49:15     Accepted    1001    C++     10  180     anotherpeg  Source

// 2012-09-30 23:37:04 | Accepted | 1021 | C++ | 0 | 180 | watashi | Source

#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <utility>
#include <iterator>
#include <algorithm>

using namespace std;

const int MAXN = 16384;

int a[MAXN << 1];
set<int> e[MAXN];

void add(int v, int l, int r, int p = 1, int pl = 0, int pr = MAXN) {
    // printf("%d %d %d %d %d %d\n", v, l, r, p, pl, pr);
    if (a[p] >= 0) {
        if (e[v].count(a[p]) == 0) {
            e[v].insert(a[p]);
            e[a[p]].insert(v);
        }
        if (p < MAXN) {
            a[p * 2] = a[p * 2 + 1] = a[p];
        }
    }
    if (a[p] != -2 && pl == l && pr == r) {
        a[p] = v;
    } else {
        int pm = (pl + pr) / 2;
        if (r <= pm) {
            add(v, l, r, p * 2, pl, pm);
        } else if (pm <= l) {
            add(v, l, r, p * 2 + 1, pm, pr);
        } else {
            add(v, l, pm, p * 2, pl, pm);
            add(v, pm, r, p * 2 + 1, pm, pr);
        }
        if (a[p * 2] == a[p * 2 + 1]) {
            a[p] = a[p * 2];
        } else {
            a[p] = -2;
        }
    }
}

int c[MAXN];
pair<int, pair<int, int> > b[MAXN];

int main() {
    int re, n, ans;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            e[i].clear();
            scanf("%d%d%d", &b[i].second.first, &b[i].second.second, &b[i].first);
            if (b[i].second.first > b[i].second.second) {
                swap(b[i].second.first, b[i].second.second);
            }
        }
        sort(b, b + n);

        memset(a, 0xff, sizeof(a));
        for (int i = 0; i < n; ++i) {
            add(i, b[i].second.first * 2, b[i].second.second * 2 + 1);
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if ((c[i] = e[i].size()) <= 5) {
                q.push(i);
            }
        }
        ans = 0;
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            for (set<int>::const_iterator i = e[s].begin(); i != e[s].end(); ++i) {
                e[*i].erase(s);
                if (e[*i].size() == 5) {
                    q.push(*i);
                }
                for (set<int>::const_iterator j = i; ++j != e[s].end(); ) {
                    if (e[*i].count(*j) > 0) {
                        ++ans;
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//369   2010-07-06 15:21:18     Accepted    1028    C++     250     1996    anotherpeg  Source

// 2012-09-30 23:40:08 | Accepted | 1391 | C++ | 190 | 1996 | watashi | Source

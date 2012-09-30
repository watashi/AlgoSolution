#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 218;

map<int, int> mp;

int getId(int i) {
    if (mp.count(i) > 0) {
        return mp[i];
    } else {
        int t = mp.size();
        return mp[i] = t;
    }
}

int m, ans;
int mark[MAXN][MAXN];
int x[MAXN], y[MAXN];
vector<pair<double, int> > e[MAXN];
vector<int> v;

bool ok(double a, double b) {
    if (b > a) {
        return b < a + M_PI;
    } else {
        return b < a - M_PI;
    }
}

int gao(int a, int b) {
    int ret = 0;
    double d;
    vector<pair<double, int> >::const_iterator it = e[b].begin();

    if (e[b].size() > 1) {
        while (it->second != a) {
            ++it;
        }
        d = it->first;
        ++it;
        if (it == e[b].end()) {
            it = e[b].begin();
        }
        if (mark[b][it->second] == -1) {
            mark[b][it->second] = mark[a][b] + 1;
            ret = gao(b, it->second);
        } else if (mark[b][it->second] != -2 && mark[a][b] + 1 - mark[b][it->second] == m) {
            ret = m;
        }
    }

    if (ret > 0) {
        if (ok(d, it->first)) {
            ++ans;
            ret = 0;
        } else {
            --ret;
        }
    }
    mark[a][b] = -2;

    return ret;
}

int main() {
    int re, n, a, b;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            getId(i);
        }
        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            a = getId(a);
            scanf("%d%d%d", &x[a], &y[a], &m);
            for (int j = 0; j < n; ++j) {
                mark[i][j] = -1;
            }
            for (int j = 0; j < m; ++j) {
                scanf("%d", &b);
                b = getId(b);
                e[a].push_back(make_pair(0.0, b));
            }
        }
        scanf("%d", &m);

        for (int i = 0; i < n; ++i) {
            for (vector<pair<double, int> >::iterator j = e[i].begin(); j != e[i].end(); ++j) {
                j->first = atan2(y[j->second] - y[i], x[j->second] - x[i]);
            }
            sort(e[i].begin(), e[i].end());
        }
        ans = 0;
        for (int i = 0; i < n; ++i) {
            for (vector<pair<double, int> >::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
                if (mark[i][j->second] == -1) {
                    mark[i][j->second] = 0;
                    gao(i, j->second);
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//346   2010-06-29 04:19:35     Accepted    1002    C++     10  368     anotherpeg  Source

// 2012-09-30 23:37:10 | Accepted | 1030 | C++ | 0 | 368 | watashi | Source

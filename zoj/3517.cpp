#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <numeric>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 10086;

map<string, int> mp;

int getId(const string& s) {
    if (mp.count(s) == 0) {
        mp.insert(make_pair(s, (int)mp.size()));
    }
    return mp[s];
}

int m, p[MAXN], q[MAXN];
vector<int> c[MAXN], u[MAXN], d[MAXN];

void gaod(int v) {
    d[v].clear();
    if (c[v].empty()) {
        d[v].push_back(0);
    } else {
        for (int i = 0; i < (int)c[v].size(); ++i) {
            gaod(c[v][i]);
        }
    }
    if (p[v] != -1) {
        static int a[MAXN], b[MAXN];
        int x = transform(d[v].begin(), min(d[v].begin() + m, d[v].end()), a,
            bind2nd(minus<int>(), q[v])) - a;
        int y = copy(d[p[v]].begin(), d[p[v]].end(), b) - b;
        d[p[v]].clear();
        merge(a, a + x, b, b + y,
            insert_iterator<vector<int> >(d[p[v]], d[p[v]].end()));
        if ((int)d[p[v]].size() > m + m) {
            d[p[v]].resize(m + m);
        }
    }
}

void gaou(int v) {
    u[v].clear();
    if (p[v] != -1) {
        static int a[MAXN], b[MAXN];
        int x = transform(d[v].begin(), min(d[v].begin() + m, d[v].end()), a,
            bind2nd(minus<int>(), q[v])) - a;
        int y = set_difference(d[p[v]].begin(), d[p[v]].end(), a, a + x, b) - b;
        merge(u[p[v]].begin(), u[p[v]].end(), b, b + y,
            insert_iterator<vector<int> >(u[v], u[v].end()));
        if ((int)u[v].size() > m) {
            u[v].resize(m);
        }
        transform(u[v].begin(), u[v].end(), u[v].begin(), bind2nd(minus<int>(), q[v]));
    }
    for (int i = 0; i < (int)c[v].size(); ++i) {
        gaou(c[v][i]);
    }
}

int main() {
    int n, x, y, z, ans;
    char buf[80];

    while (scanf("%d%d", &n, &m) != EOF) {
        mp.clear();
        for (int i = 0; i < n; ++i) {
            p[i] = -1;
            c[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            scanf("%s", buf);
            x = getId(buf);
            scanf("%s", buf);
            y = getId(buf);
            scanf("%d", &z);
            p[x] = y;
            q[x] = z;
            c[y].push_back(x);
        }

        x = -1;
        for (int i = 0; i < n; ++i) {
            if (p[i] == -1) {
                x = i;
            }
        }
        gaod(x);
        gaou(x);
        ans = 0;
        for (int i = 0; i < n; ++i) {
            static int a[MAXN];
            if (merge(d[i].begin(), d[i].end(), u[i].begin(), u[i].end(), a) - a >= m) {
                ans = min(ans, accumulate(a, a + m, 0));
            }
        }
        printf("%d\n", -ans);
    }

    return 0;
}

// 2012-09-07 16:04:26 | Accepted | 3517 | C++ | 1980 | 31596 | watashi | Source

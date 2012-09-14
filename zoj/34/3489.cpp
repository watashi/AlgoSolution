#include <utility> // auto fix CE
#include <cstdio>
#include <utility> // auto fix CE
#include <vector>
#include <utility> // auto fix CE
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int rank[MAXN];
vector<int> e[MAXN];

bool pr(int lhs, int rhs) {
    return rank[lhs] < rank[rhs];
}

void gao(const vector<int>& v) {
    if (v.empty()) {
        return;
    }
    vector<int> w;
    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
        w.insert(w.end(), e[*i].begin(), e[*i].end());
    }
    gao(w);

    vector<pair<vector<int>, int> > vv;
    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
        sort(e[*i].begin(), e[*i].end(), pr);
        vv.push_back(make_pair(vector<int>(), *i));
        for (vector<int>::const_iterator j = e[*i].begin(); j != e[*i].end(); ++j) {
            vv.back().first.push_back(rank[*j]);
        }
        if (!vv.back().first.empty()) {
            vv.back().first.push_back(MAXN);
        }
    }
    sort(vv.begin(), vv.end());

    for (vector<pair<vector<int>, int> >::const_iterator i = vv.begin(); i != vv.end(); ++i) {
        if (i == vv.begin() || (i - 1)->first < i->first) {
            rank[i->second] = i - vv.begin();
        } else {
            rank[i->second] = rank[(i - 1)->second];
        }
    }
}

vector<int> cur;
vector<vector<int> > ans;

void dfs(int v) {
    if (e[v].empty()) {
        ans.push_back(cur);
    } else {
        for (int i = 0; i < (int)e[v].size(); ++i) {
            cur.push_back(i);
            dfs(e[v][i]);
            cur.pop_back();
        }
    }
}

int main() {
    int re, n, m, a, b;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &a, &b);
            e[a].push_back(b);
        }

        gao(vector<int>(1, 0));
        cur.clear();
        ans.clear();
        dfs(0);

        for (int i = 0; i < m; ++i) {
            scanf("%d", &a);
            --a;
            if (a < (int)ans.size()) {
                for (int i = 0; i < (int)ans[a].size(); ++i) {
                    if (i > 0) {
                        putchar(' ');
                    }
                    printf("%d", ans[a][i]);
                }
                puts("");
            } else {
                puts("Out of range.");
            }
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//468   2011-04-15 01:43:07     Accepted    C   C++     140     1120    watashi     Source
//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2500529   2011-04-17 22:15:21     Accepted    3489    C++     90  1120    watashi@ArcOfDream  Source

// 2012-09-07 16:01:22 | Accepted | 3489 | C++ | 80 | 1120 | watashi | Source

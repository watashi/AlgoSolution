#include <map>
#include <queue>
#include <cctype>
#include <cstdio>
#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>

using namespace std;

const int ROOT = 0;
const int MAXN = 10001;

map<int, int> tab;
vector<int> e[MAXN];
int m[MAXN], u[MAXN], d[MAXN];
int depth, temp;
vector<int> ans;

int hash(int a, int b) {
    if (a <= b) {
        return a * 10000 + b;
    } else {
        return b * 10000 + a;
    }
}

void clear(int n) {
    tab.clear();
    for (int i = 0; i < n; ++i) {
        e[i].clear();
    }
    fill(m, m + n, 0);
    depth = 0;
    ans.clear();
}

void add(int a, int b, int c) {
    e[a].push_back(b);
    e[b].push_back(a);
    temp = hash(a, b);
    if (tab.count(temp) == 0) {
        tab[temp] = c;
    } else {
        tab[temp] = -1;
    }
}

void dfs(int p, int f) {
    d[p] = depth;
    u[p] = depth;
    m[p] = 1;
    ++depth;
    for (int i = 0; i < (int)e[p].size(); ++i) {
        int t = e[p][i];
        if ((t = e[p][i]) == f) {
            continue;
        }
        if (m[t] == 1) {
            u[p] = min(u[p], d[t]);
        } else if (m[t] == 0) {
            dfs(t, p);
            u[p] = min(u[p], u[t]);
            if (u[t] > d[p]) {
                temp = tab[hash(t, p)];
                if (temp != -1) {
                    ans.push_back(temp);
                }
            }
        }
    }
    --depth;
    m[p] = 2;
}

void solve() {
    // !assert! connected
    dfs(ROOT, -1);
    sort(ans.begin(), ans.end());
}

vector<int> ans2;

void bfs(int n) {
    static int p[MAXN];

    fill(p, p + n, -1);
    p[0] = -2;
    queue<int> q;
    q.push(ROOT);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (vector<int>::const_iterator i = e[s].begin(); i != e[s].end(); ++i) {
            if (p[*i] == -1) {
                p[*i] = s;
                q.push(*i);
            }
        }
    }
    assert(p[n - 1] != -1);

    ans2.clear();
    for (int s = n - 1; p[s] != -2; s = p[s]) {
        int temp = tab[hash(s, p[s])];
        if (temp != -1) {
            ans2.push_back(temp);
        }
    }
    sort(ans2.begin(), ans2.end());
}

int main() {
    int n, m, a, b;

    while (scanf("%d%d", &n, &m) != EOF) {
        clear(n);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            add(a, b, i);
        }
        solve();

        bfs(n);
//      fprintf(stderr, "%d and ", ans.size());
//      fprintf(stderr, "%d = ", ans2.size());
        ans.erase(set_intersection(ans.begin(), ans.end(), ans2.begin(), ans2.end(), ans.begin()), ans.end());
//      fprintf(stderr, "%d\n", ans.size());

        printf("%d\n", ans.size());
        for (int i = 0; i < (int)ans.size(); ++i) {
            if (i > 0) {
                putchar(' ');
            }
            printf("%d", ans[i]);
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1070  2010-07-26 13:36:17     Accepted    1127    C++     3200    8880    anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//219   2010-08-12 15:11:57     Accepted    kaguya  C++     1670    7840    watashi@Zodiac  Source

// 2012-09-07 15:50:30 | Accepted | 3378 | C++ | 1570 | 7840 | watashi | Source

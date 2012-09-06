#include <map>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

void tsort(int n, vector<int> e[MAXN], int v[MAXN]) {
    static int c[MAXN];
    int m = 0;

    fill(c, c + n, 0);
    for (int i = 0; i < n; ++i) {
        for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
            ++c[*j];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (c[i] == 0) {
            v[m++] = i;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (vector<int>::const_iterator j = e[v[i]].begin(); j != e[v[i]].end(); ++j) {
            if (--c[*j] == 0) {
                v[m++] = *j;
            }
        }
    }
    assert(m == n);
}

int main() {
    int n, m, a, b, c;
    int p[MAXN], q[MAXN], e[MAXN][MAXN];
    vector<int> ans, ep[MAXN], eq[MAXN];

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            ep[i].clear();
            eq[i].clear();
            for (int j = 0; j < n; ++j) {
                e[i][j] = -1;
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            ep[--a].push_back(--b);
            if (c == 0) {
                eq[a].push_back(b);
            } else {
                eq[b].push_back(a);
            }
            e[a][b] = e[a][b] == -1 ? i : -2;
        }
        tsort(n, ep, p);
        tsort(n, eq, q);

        ans.clear();
        try {
            for (int i = 0; i < n; ++i) {
                for (int j = find(p, p + n, q[i]) - p; j > i; --j) {
                    assert(e[p[j]][p[j - 1]] == -1);
                    if (e[p[j - 1]][p[j]] == -2) {
                        throw 1;
                    } else if (e[p[j - 1]][p[j]] != -1) {
                        ans.push_back(e[p[j - 1]][p[j]]);
                        swap(e[p[j - 1]][p[j]], e[p[j]][p[j - 1]]);
                    }
                    swap(p[j - 1], p[j]);
                }
            }
            assert((int)ans.size() <= m);
            printf("%d\n", (int)ans.size());
            for (int i = 0; i < (int)ans.size(); ++i) {
                if (i > 0) {
                    putchar(' ');
                }
                printf("%d", ans[i] + 1);
            }
            puts("");
        } catch (...) {
            puts("-1");
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2179030   2010-04-28 14:16:44     Accepted    2697    C++     170     724     watashi@Zodiac

// 2012-09-07 01:35:04 | Accepted | 2697 | C++ | 140 | 724 | watashi | Source

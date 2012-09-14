#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 512;
const int MAXM = 65536;

vector<int> e[MAXN];
int d[MAXN][MAXN];

int xx, yy, zz;

bool dfs(int p, int s, int t) {
    if (s == t) {
        return true;
    } else {
        for (vector<int>::const_iterator i = e[s].begin(); i != e[s].end(); ++i) {
            if (*i != p && dfs(s, *i, t)) {
                if (zz > d[s][*i]) {
                    xx = s;
                    yy = *i;
                    zz = d[xx][yy];
                }
                return true;
            }
        }
        return false;
    }
}

char c[MAXM];
int x[MAXM], y[MAXM];

int main() {
    int ri = 0;
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            e[i].clear();
            fill(d[i], d[i] + n, MAXM);
        }
        for (int i = 0; i < m; ++i) {
            scanf(" %c%d%d", &c[i], &x[i], &y[i]);
            --x[i];
            --y[i];
            if (c[i] == 'D') {
                d[x[i]][y[i]] = d[y[i]][x[i]] = i;
            }
        }

        if (ri > 0) {
            puts("");
        }
        printf("Case %d:\n", ++ri);
        for (int i = 0; i < m; ++i) {
            if (c[i] == 'I') {
                zz = MAXM;
                if (dfs(-1, x[i], y[i])) {
                    if (zz < d[x[i]][y[i]]) {
                        e[xx].erase(remove(e[xx].begin(), e[xx].end(), yy), e[xx].end());
                        e[yy].erase(remove(e[yy].begin(), e[yy].end(), xx), e[yy].end());
                        e[x[i]].push_back(y[i]);
                        e[y[i]].push_back(x[i]);
                    }
                } else {
                    e[x[i]].push_back(y[i]);
                    e[y[i]].push_back(x[i]);
                }
            } else if (c[i] == 'D') {
                e[x[i]].erase(remove(e[x[i]].begin(), e[x[i]].end(), y[i]), e[x[i]].end());
                e[y[i]].erase(remove(e[y[i]].begin(), e[y[i]].end(), x[i]), e[y[i]].end());
            } else {
                puts(dfs(-1, x[i], y[i]) ? "YES" : "NO");
            }
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//747   2011-04-27 04:20:17     Accepted    J   C++     590     1784    watashi@ArcOfDream  Source

// 2012-09-07 16:03:25 | Accepted | 3509 | C++ | 590 | 1784 | watashi | Source

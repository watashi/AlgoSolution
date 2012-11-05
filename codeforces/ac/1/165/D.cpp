#include <set>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 100100;

int t[MAXN], d[MAXN], a[MAXN], b[MAXN];
set<int> s[MAXN];
vector<int> e[MAXN];

void gao(int v, int f) {
    for (int w: e[v]) {
        if (w != f) {
            t[w] = t[v];
            d[w] = d[v] + 1;
            gao(w, v);
        }
    }
}

int main() {
    int n, m, r, x, y;

    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }

    r = 1;
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() > 2) {
            r = i;
        }
    }
    t[r] = r;
    d[r] = 0;
    s[r].insert(MAXN);
    for (int i: e[r]) {
        t[i] = i;
        d[i] = 1;
        s[i].insert(MAXN);
        gao(i, r);
    }

    for (int i = 1; i < n; ++i) {
        if (d[a[i]] > d[b[i]]) {
            swap(a[i], b[i]);
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &y, &x);
        if (y == 1) {
            s[t[b[x]]].erase(d[b[x]]);
        } else if (y == 2) {
            s[t[b[x]]].insert(d[b[x]]);
        } else {
            scanf("%d", &y);
            if (t[x] == t[y]) {
                if (d[x] > d[y]) {
                    swap(x, y);
                }
                printf("%d\n", *s[t[x]].upper_bound(d[x]) > d[y] ? d[y] - d[x] : -1);
            } else {
                printf("%d\n", *s[t[x]].begin() > d[x] && *s[t[y]].begin() > d[y] ? d[x] + d[y] : -1);
            }
        }
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1408983 	Mar 25, 2012 6:35:04 PM 	watashi 	165D - Beard Graph 	GNU C++0x 	Accepted 	520 ms 	14000 KB

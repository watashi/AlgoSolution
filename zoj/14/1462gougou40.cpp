#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 128;

struct DisjointSet {
    int p[MAXN], a[MAXN], b[MAXN];

    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
            a[i] = 1;
            b[i] = 0;
        }
    }

    int root(int i) {
        if (i > 0) {
            return i == p[i] ? i : (p[i] = root(p[i]));
        } else {
            return -i == p[-i] ? i : -(p[-i] = root(p[-i]));
        }
    }

    int _istrue(int i, int j) {
        if (i < 0) {
            return _isfalse(-i, j);
        } else if (j < 0) {
            return _isfalse(i, -j);
        } else if (i != j) {
            p[j] = i;
            a[i] += a[j];
            b[i] += b[j];
            return 1;
        } else {
            return 0;
        }
    }

    int _isfalse(int i, int j) {
        if (i < 0) {
            return _istrue(-i, j);
        } else if (j < 0) {
            return _istrue(i, -j);
        } else if (i != j) {
            p[j] = -i;
            a[i] += b[j];
            b[i] += a[j];
            return 1;
        } else {
            return -1;
        }
    }

    int istrue(int i, int j) {
        return _istrue(root(i), root(j));
    }

    int isfalse(int i, int j) {
        return _isfalse(root(i), root(j));
    }
} ds;

int r[MAXN], s[MAXN], t[MAXN];

struct F {
    const int y;
    F(int y) : y(y) { }
    bool operator()(int x) const { return ds.root(x) != y; }
};

int main() {
    int re, n, m, a, p, ans[MAXN];
    bool flg, e[MAXN], dp[MAXN][MAXN];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        ds.init(n);
        flg = true;
        for (int i = 1; i <= n; ++i) {
            ans[i] = i;
            fill(e + 1, e + 1 + n, false);
            while (scanf("%d", &a) != EOF && a > 0) {
                e[a] = true;
            }
            for (int j = 1; j <= n; ++j) {
                if (!e[j] && j != i) {
                    flg &= ds.isfalse(i, j) != -1;
                }
            }
        }

        if (ri > 1) {
            puts("");
        }
        if (!flg) {
            puts("No solution");
            continue;
        }

        m = 0;
        for (int i = 1; i <= n; ++i) {
            if (ds.root(i) == i) {
                ++m;
                r[m] = i;
                s[m] = ds.a[i];
                t[m] = ds.b[i];
                // printf("%d: %d + %d\n", r[m], s[m], t[m]);
            }
        }
        dp[0][0] = true;
        fill(dp[0] + 1, dp[0] + 1 + n, false);
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = (j >= s[i] && dp[i - 1][j - s[i]]) || (j >= t[i] && dp[i - 1][j - t[i]]);
            }
        }

        a = 0;
        for (int j = 0; j <= n; ++j) {
            if (dp[m][j] && abs(n - 2 * j) < abs(n - 2 * a)) {
                a = j;
            }
        }

        p = n;
        for (int i = m; i > 0; --i) {
            if (a >= s[i] && dp[i - 1][a - s[i]]) {
                a -= s[i];
                p = partition(ans + 1, ans + 1 + p, F(-r[i])) - ans - 1;
            } else {
                a -= t[i];
                p = partition(ans + 1, ans + 1 + p, F(r[i])) - ans - 1;
            }
        }

        printf("%d", p);
        for (int i = 1; i <= p; ++i) {
            printf(" %d", ans[i]);
        }
        printf("\n%d", n - p);
        for (int i = p + 1; i <= n; ++i) {
            printf(" %d", ans[i]);
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//338   2010-06-28 04:28:31     Accepted    1035    C++     110     180     anotherpeg  Source

// 2012-09-30 23:40:54 | Accepted | 1462 | C++ | 70 | 184 | watashi | Source

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

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
};

int main() {
    int n, j, ans;
    char buf[80];
    DisjointSet ds;

    while (scanf("%d", &n) != EOF && n > 0) {
        ans = 0;
        ds.init(n);
        for (int i = 1; i <= n; ++i) {
            scanf("%*s%d%*s%s", &j, buf);
            if (ans != -1) {
                if (buf[0] == 't') {
                    ans -= (ds.istrue(i, j) == -1);
                } else {
                    ans -= (ds.isfalse(i, j) == -1);
                }
            }
        }

        if (ans == -1) {
            puts("Inconsistent");
        } else {
            for (int i = 1; i <= n; ++i) {
                if (ds.root(i) == i) {
                    ans += max(ds.a[i], ds.b[i]);
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//262   2010-06-25 21:16:38     Accepted    1040    C++     0   180     anotherpeg  Source

// 2012-09-30 23:41:27 | Accepted | 1518 | C++ | 0 | 180 | watashi | Source

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 2048;

struct DisjointSet {
    int p[MAXN];
    int a[MAXN], b[MAXN];

    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
            a[i] = 1;
            b[i] = 0;
        }
    }

    int getp(int i) {
        if (i < 0) {
            return -getp(-i);
        } else if (p[i] == i) {
            return i;
        } else {
            return p[i] = getp(p[i]);
        }
    }

    bool setp(int i, int j) {
        printf("setp(%d, %d)\n", i, j);
        i = getp(i);
        j = getp(j);
        printf("  setp(%d, %d)\n", i, j);
        if (i == j) {
            return true;
        } else if (i == -j) {
            return false;
        }
        if (i < 0) {
            i = -i;
            j = -j;
        }
        if (j > 0) {
            p[j] = i;
            a[i] += a[j];
            b[i] += b[j];
        } else {
            p[-j] = -i;
            a[i] += b[-j];
            b[i] += a[-j];
        }
        return true;
    }
} ds;

vector<int> x, y;
int ans[MAXN][MAXN];

int main() {
    bool flag = true;
    int r, c, t;

    scanf("%d%d", &r, &c);
    ds.init(r + c);
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            scanf("%d", &t);
            if (t == 1) {
                flag &= ds.setp(i, r + j);
            } else {
                flag &= ds.setp(-i , r + j);
            }
        }
    }

    if (!flag) {
        puts("Impossible");
        return 0;
    }

    for (int i = 1; i <= r + c; ++i) {
        if (ds.getp(i) == i) {
            if (ds.a[i] % 2 != ds.b[i] % 2) {
                flag = !flag;
            }
        } else if (ds.getp(i) < 0) {
            if (i <= r) {
                x.push_back(r);
            } else {
                y.push_back(i - r);
            }
        }
    }

    if (!flag) {
        puts("Impossible");
        return 0;
    }

    while (x.size() < y.size()) {
        x.push_back(1);
    }
    while (y.size() < x.size()) {
        y.push_back(1);
    }
    for (int i = 0; i < (int)x.size(); ++i) {
        ans[x[i]][y[i]] ^= 1;
    }

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            printf("%d%c", ans[i][j], j == c ? '\n' : ' ');
        }
    }

    return 0;
}


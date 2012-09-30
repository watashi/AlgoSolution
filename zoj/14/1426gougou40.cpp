#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 128;

struct Line {
    int a, b, c;
    Line(int a, int b, int c) : a(min(a, b)), b(max(a, b)), c(c) { }
};

int main() {
    int re, n, x1, y1, x2, y2, tmp, ans;
    bool inter[MAXN][MAXN];
    vector<Line> h, v;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        h.clear();
        v.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 == x2) {
                v.push_back(Line(y1, y2, x1));
            } else {
                h.push_back(Line(x1, x2, y1));
            }
        }

        ans = 0;
        for (int i = 0; i < (int)h.size(); ++i) {
            for (int j = 0; j < (int)v.size(); ++j) {
                inter[i][j] = v[j].a <= h[i].c && h[i].c <= v[j].b && h[i].a <= v[j].c && v[j].c <= h[i].b;
            }
        }
        for (int i = 0; i < (int)h.size(); ++i) {
            for (int j = i + 1; j < (int)h.size(); ++j) {
                tmp = 0;
                for (int k = 0; k < (int)v.size(); ++k) {
                    if (inter[i][k] && inter[j][k]) {
                        ++tmp;
                    }
                }
                ans += tmp * (tmp - 1) / 2;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//319   2010-06-27 08:22:52     Accepted    1032    C++     0   180     anotherpeg  Source

// 2012-09-30 23:40:34 | Accepted | 1426 | C++ | 0 | 180 | watashi | Source

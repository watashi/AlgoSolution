#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
    Point() { }
    Point(double x, double y) : x(x), y(y) { }
};

double intersection(const Point& a, const Point& b, const Point& c, const Point& d) {
    double s1 = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
    double s2 = (d.x - a.x) * (d.y - c.y) - (d.y - a.y) * (d.x - c.x);
    return fabs(s1) < 1e-8 || s2 / s1 > 1e-8 ? -1e100 : s2 / s1;
}

int main() {
    int re, n, w, h;
    Point a[32], b[32];
    double l[32][32], r[32][32], s[32], dp[4096];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d", &w, &h, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &a[i].x, &a[i].y);
            if (i > 0) {
                b[i] = a[i - 1];
            }
        }
        b[0] = a[n - 1];
        a[n] = b[n + 3] = Point(0, 0);
        a[n + 1] = b[n] = Point(0, h);
        a[n + 2] = b[n + 1] = Point(w, h);
        a[n + 3] = b[n + 2] = Point(w, 0);

        for (int i = 0; i < n; ++i) {
            s[i] = hypot(b[i].x - a[i].x, b[i].y - a[i].y);
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                l[i][j] = intersection(a[i], b[i], a[j], b[j]);
                r[i][j] = intersection(b[i], a[i], a[j], b[j]);
            }
            l[i][i] = r[i][i] = -1e100;
            for (int j = n; j < n + 4; ++j) {
                l[i][i] = max(l[i][i], intersection(a[i], b[i], a[j], b[j]));
                r[i][i] = max(r[i][i], intersection(b[i], a[i], a[j], b[j]));
            }
        }

        fill(dp, dp + (1 << n), 1e100);
        dp[0] = 0;
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    continue;
                }
                double ll = l[j][j], rr = r[j][j];
                for (int k = 0; k < n; ++k) {
                    if ((i & (1 << k)) != 0) {
                        ll = max(ll, l[j][k]);
                        rr = max(rr, r[j][k]);
                    }
                }
                dp[i ^ (1 << j)] = min(dp[i ^ (1 << j)], dp[i] + (1 - ll - rr) * s[j]);
            }
        }

        if (ri > 1) {
            puts("");
        }
        printf("Minimum total length = %.3lf\n", dp[(1 << n) - 1]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//334   2010-06-27 22:26:51     Accepted    1016    C++     10  180     anotherpeg  Source

// 2012-09-30 23:38:46 | Accepted | 1185 | C++ | 0 | 180 | watashi | Source

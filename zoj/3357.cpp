#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2048;
const double EPS = 1e-8;
const double INF = 1e99;

struct Line {
    double x0, y0, dx, dy;
} ln[MAXN];

int main() {
    int re, n, wol;
    double a, b, c, t, l, r, x, y;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf%d", &a, &b, &c, &wol);
            if (wol == -1) {
                a = -a;
                b = -b;
                c = -c;
            }
            // ax + by > c
            c /= hypot(a, b);
            t = atan2(a, -b);
            ln[i].dx = cos(t);
            ln[i].dy = sin(t);
            ln[i].x0 = ln[i].dy * c;
            ln[i].y0 = -ln[i].dx * c;
        //  printf("%lf %lf %lf %lf\n", ln[i].x0, ln[i].y0, ln[i].dx, ln[i].dy);
        }
        scanf("%lf%lf", &a, &b);

        x = INF;
        y = -INF;
        for (int i = 0; i < n; ++i) {
            l = -INF;
            r = INF;
            for (int j = 0; l <= r && j < n; ++j) {
                if (j == i) {
                    continue;
                }
                t = (ln[j].x0 - ln[i].x0) * ln[j].dy - (ln[j].y0 - ln[i].y0) * ln[j].dx;
                c = ln[i].dx * ln[j].dy - ln[i].dy * ln[j].dx;
                if (c > EPS) {
                    l = max(l, t / c);
                } else if (c < -EPS) {
                    r = min(r, t / c);
                } else if (t > EPS) {
                    l = INF;
                    r = -INF;
                }
            }
            if (l <= r) {
            //  printf("%d: %lf %lf\n", i, l, r);
            //  printf("(%lf, %lf)\n", ln[i].x0 + ln[i].dx * l, ln[i].y0 + ln[i].dy * l);
                c = a * (ln[i].x0 + ln[i].dx * l) + b * (ln[i].y0 + ln[i].dy * l);
                x = min(x, c);
                y = max(y, c);
            //  printf("(%lf, %lf)\n", ln[i].x0 + ln[i].dx * r, ln[i].y0 + ln[i].dy * r);
                c = a * (ln[i].x0 + ln[i].dx * r) + b * (ln[i].y0 + ln[i].dy * r);
                x = min(x, c);
                y = max(y, c);
            }
        }
        // printf("%.4lf %.4lf\n", x, y);

        printf("%.0lf %.0lf\n", ceil(x + EPS) + EPS, floor(y - EPS) + EPS);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//918   2010-07-22 19:10:06     Accepted    1097    C++     70  244     anotherpeg  Source

// 2012-09-07 15:48:21 | Accepted | 3357 | C++ | 40 | 244 | watashi | Source

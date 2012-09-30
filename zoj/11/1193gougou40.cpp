#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

const int MAXN = 32;
const double EPS = 1e-6;

int main() {
    int ri = 0, n, pre, cur;
    double x0, y0, dx, dy, xx, yy, b, c, d, t, mint;
    double x[MAXN], y[MAXN], r[MAXN];

    while (scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
        }
        scanf("%lf%lf%lf%lf", &x0, &y0, &dx, &dy);
        d = hypot(dx, dy);
        dx /= d;
        dy /= d;

        printf("Scene %d\n", ++ri);
        pre = -1;
        for (int i = 0; i <= 10; ++i) {
            cur = -1;
            for (int j = 0; j < n; ++j) {
                if (j == pre) {
                    continue;
                }
                xx = x0 - x[j];
                yy = y0 - y[j];
                b = 2 * (xx * dx + yy * dy);
                c = xx * xx + yy * yy - r[j] * r[j];
                d = b * b - 4 * c;
                if (d < -EPS) {
                    continue;
                }
                d = d < 0 ? 0 : sqrt(d);
                // printf("%lf %lf d=%lf t1=%lf t2=%lf\n", b, c, d, (-b - d) / 2, (-b + d) / 2);
                if (-b - d >= -EPS) {
                    t = (-b - d) / 2;
                } else {
                    t = (-b + d) / 2;
                }
                if (t >= -EPS && (cur == -1 || t < mint)) {
                    cur = j;
                    mint = t;
                }
            }

            if (cur == -1) {
                printf("inf");
                break;
            } else if (i == 10) {
                printf("...");
                break;
            } else {
                printf("%d ", cur + 1);
                pre = cur;
                x0 += dx * mint;
                y0 += dy * mint;
                xx = x0 - x[cur];
                yy = y0 - y[cur];
                // printf("mint = %lf; hypot(%lf, %lf) = %lf\n", mint, xx, yy, hypot(xx, yy));
                d = 2 * fabs(xx * dx + yy * dy) / (xx * xx + yy * yy);
                dx += xx * d;
                dy += yy * d;
                // printf("(%lf, %lf) (%lf, %lf) = %lf [%lf]\n", x0, y0, dx, dy, hypot(dx, dy), d);
            }
        }
        puts("\n");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//324   2010-06-27 19:35:12     Accepted    1017    C++     10  180     anotherpeg  Source

// 2012-09-30 23:38:53 | Accepted | 1193 | C++ | 0 | 180 | watashi | Source

#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

const int MAXN = 1024;
double x[MAXN], y[MAXN], dx[MAXN], dy[MAXN], z[MAXN];

int main() {
    int ri = 0, n, m;
    double xx, yy, zz, zzz;

    while (scanf("%d%d", &n, &m) != EOF) {
        zzz = 0;
        x[0] = y[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf", &x[i], &y[i]);
            dx[i] = x[i] - x[i - 1];
            dy[i] = y[i] - y[i - 1];
            z[i] = hypot(dx[i], dy[i]);
            if (fabs(z[i] > 1e-8)) {
                dx[i] /= z[i];
                dy[i] /= z[i];
            }
            zzz += z[i];
        }
        zzz /= (m + 1);

        printf("Route %d\n", ++ri);
        xx = yy = 0;
        for (int i = 0, j = 1; i < m; ++i) {
            zz = zzz;
            while (z[j] <= zz) {
                xx = x[j];
                yy = y[j];
                zz -= z[j];
                ++j;
            }
            xx += dx[j] * zz;
            yy += dy[j] * zz;
            z[j] -= zz;
            printf("CP%d: (%.3lf, %.3lf)\n", i + 1, xx, yy);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//899   2010-07-21 21:14:17     Accepted    1094    C++     300     220     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//322   2010-10-05 22:28:48     Accepted    I   C++     200     220     watashi@Zodiac  Source

// 2012-09-07 15:53:33 | Accepted | 3414 | C++ | 180 | 220 | watashi | Source

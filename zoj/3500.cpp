#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

double sqr(double x) {
    return x * x;
}

double vol(double r, double h) {
    return M_PI * (r * r - h * h / 3) * h;
}

int main() {
    int re;
    double x1, y1, z1, r1, x2, y2, z2, r2, d, t, ans;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &z1, &r1, &x2, &y2, &z2, &r2);
        d = sqrt(sqr(x1 - x2) + sqr(y1 - y2) + sqr(z1 - z2));
        if (r1 < r2) {
            swap(r1, r2);
        }
        if (d >= r1 + r2) {
            ans = vol(r1, r1) - vol(r1, -r1) + vol(r2, r2) - vol(r2, -r2);
        } else if (d <= r1 - r2) {
            ans = vol(r1, r1) - vol(r1, -r1);
        } else {
            t = (r1 * r1 - r2 * r2) / d;
            z1 = (d + t) / 2;
            z2 = (d - t) / 2;
            ans = vol(r1, z1) - vol(r1, -r1) + vol(r2, z2) - vol(r2, -r2);
        }
        printf("%.2lf\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//744   2011-04-27 03:40:42     Accepted    A   C++     0   180     watashi@ArcOfDream  Source

// 2012-09-07 16:02:30 | Accepted | 3500 | C++ | 0 | 180 | watashi | Source

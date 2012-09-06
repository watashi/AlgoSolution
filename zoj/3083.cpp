#include <cmath>
#include <cstdio>

const double PI = acos(-1.0);

int main() {
    double D, d, s;
    int re;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%lf%lf%lf", &D, &d, &s);
        printf("%.0lf\n", floor(PI / asin((s + d) / (D - d))));
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1746040   2009-01-21 00:43:51     Accepted    3083    C++     0   176     watashi@Zodiac

// 2012-09-07 02:00:55 | Accepted | 3083 | C++ | 0 | 180 | watashi | Source

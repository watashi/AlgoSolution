#include <cmath>
#include <cstdio>

const double PI = acos(-1.0);

int main(void)
{
    double k, h, a, b, x, y;

    while (scanf("%lf%lf%lf%lf", &k, &h, &a, &b) != EOF) {
        k = -tan(k / 180 * PI);
        x = (a - h) / (k + 1.0 / k);
        y = -x / k + a;
        x = 2 * x;
        y = 2 * y - a;
//      printf("%lf %lf\n", x, y);
        printf("%.2lf\n", sqrt((x - b) * (x - b) + y * y));
    }

    return 0;
}

//26673     2008-07-07 09:24:59       Accepted      B   C++     0   260     watashi

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//27364     2008-07-08 10:21:43     Accepted    1016    C++     0   256     watashi     Source
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3040683   2008-08-18 16:17:59     Accepted    3015    C++     00:00.01    400K    Re:ReJudge
//

// 2012-09-07 01:55:11 | Accepted | 3015 | C++ | 0 | 180 | watashi | Source

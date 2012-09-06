#include <cmath>
#include <cstdio>

int main(void)
{
    int a, b, s, m, n;
    double x, y;
    double ratio = 90.0 / acos(0.0);

    while(scanf("%d%d%d%d%d", &a, &b, &s, &m, &n) != EOF && s > 0) {
        x = a * m;
        y = b * n;
        printf("%.2lf %.2lf\n",
                atan2(y, x) * ratio,
                sqrt(x * x + y * y) / s);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2843693   2008-04-14 18:03:02     Accepted    1852    C++     00:00.01    396K    Re:ReJudge

// 2012-09-07 01:02:52 | Accepted | 1852 | C++ | 0 | 180 | watashi | Source

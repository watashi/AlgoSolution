#include <cstdio>

double calc(int n, double t, double x)
{
    if(n == 0)
        return x;

    double e = calc(n - 1, t, x * 2);
    double p = x / e;

    if(p <= t)
        return (1 + t) / 2.0 * e;
    else
        return ((p - t) * x + (1 - p) * (1 + p) / 2.0 * e) / (1 - t);
}

int main(void)
{
    int n;
    double t;

    while(scanf("%d%lf", &n, &t) != EOF && n > 0) {
        printf("%.3lf\n", calc(n, t, 1));
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2874589   2008-04-27 16:51:32     Accepted    2549    C++     00:00.01    440K    Re:ReJudge

// 2012-09-07 01:27:58 | Accepted | 2549 | C++ | 0 | 180 | watashi | Source

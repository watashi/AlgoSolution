// Ä£ÄâÍË»ð
#include <cmath>
#include <cstdio>

int n;
double x[100], y[100];

double length(double xx, double yy)
{
    double ret = 0;

    for (int i = 0; i < n; i++) {
        ret += hypot(x[i] - xx, y[i] - yy);
    }

    return ret;
}

int main(void)
{
    double xt, yt, lt, t, l;

    while (scanf("%d", &n) != EOF) {
        xt = yt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &x[i], &y[i]);
            xt += x[i];
            yt += y[i];
        }
        xt /= n;
        yt /= n;
        lt = length(xt, yt);
        for (double t = 1e4; t >= 1e-4; t *= 0.618) {
            l = length(xt + t, yt);
            if (l < lt) {lt = l; xt += t;}
            l = length(xt - t, yt);
            if (l < lt) {lt = l; xt -= t;}
            l = length(xt, yt + t);
            if (l < lt) {lt = l; yt += t;}
            l = length(xt, yt - t);
            if (l < lt) {lt = l; yt -= t;}
        }
        printf("%.0lf\n", lt);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3020026 2008-08-03 21:54:08 Accepted 1901 C++ 00:00.01 400K Re:ReJudge

// for (double t = 1e3; t >= 1e-3; t *= 0.618)
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3020027 2008-08-03 21:54:35 Accepted 1901 C++ 00:00.00 400K Re:ReJudge
//

// 2012-09-07 01:05:12 | Accepted | 1901 | C++ | 0 | 180 | watashi | Source

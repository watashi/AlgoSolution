#include <cmath>
#include <cstdio>

inline double sqr(double x)
{
    return x * x;
}

int n;
double a[100], b[100], c[100];

double diff(double aa, double bb, double cc)
{
    double ret = 0;

    for (int i = 0; i < n; i++) {
        ret += sqrt(sqr(a[i] - aa) + sqr(b[i] - bb) + sqr(c[i] - cc));
    }

    return ret;
}

double att, btt, ctt, dtt;

void test(double aa, double bb, double cc)
{
    double dd = diff(aa, bb, cc);

    if (dd < dtt) {
        att = aa;
        btt = bb;
        ctt = cc;
        dtt = dd;
    }
}

int main(void)
{
    double at, bt, ct, dt;

    while (scanf("%d", &n) != EOF) {
        at = bt = ct = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
            at += a[i], bt += b[i], ct += c[i];
        }
        at /= n, bt /= n, ct /= n;
        dt = diff(at, bt, ct);
        for (double t = 1e3; t >= 1e-6; t *= 0.8) { // 0.618 WA
            att = at, btt = bt, ctt = ct, dtt = dt;
            // 只搜平行方向WA
            for (int i = -2; i <= 2; i++) {
                for (int j = -2; j <= 2; j++) {
                    for (int k = -2; k <= 2; k++) {
                        test(at + i * t, bt + j * t, ct + k * t);
                    }
                }
            }
            at = att, bt = btt, ct = ctt, dt = dtt;
        }
        // no -0.000
        //if (at < 0 && at >= -0.0005) at = 0;
        //if (bt < 0 && bt >= -0.0005) bt = 0;
        //if (ct < 0 && ct >= -0.0005) ct = 0;
        printf("%.3lf %.3lf %.3lf\n", at, bt, ct);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3020099 2008-08-03 22:28:36 Accepted 2928 C++ 00:00.77 408K Re:ReJudge
//

// 2012-09-07 01:48:00 | Accepted | 2928 | C++ | 220 | 180 | watashi | Source

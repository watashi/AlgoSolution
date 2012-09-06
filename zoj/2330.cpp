// alnx与xlna交于x1<=e<=x2，其中a=x1或x2

#include <cmath>
#include <cstdio>

int main(void)
{
    double x;
    while(scanf("%lf", &x) != EOF) {
        if(x >= exp(1.0)) printf("-1\n");
        else {
            double l = exp(1.0), r = 101.0;
            while(r - l > 1e-8) {
                double mid = (l + r) / 2;
                if(mid * log(x) < x * log(mid)) l = mid;
                else r = mid;
            }
            printf("%.5lf\n", (l + r) / 2);
        }
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2746656 2008-02-08 18:33:01 Accepted 2330 C++ 00:00.00 400K わたし

// 2012-09-07 01:19:11 | Accepted | 2330 | C++ | 0 | 180 | watashi | Source

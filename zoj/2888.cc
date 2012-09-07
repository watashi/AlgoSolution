/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!"Negative zeros" should be printed without the negative sign.!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

#include <cstdlib> // auto fix CE
#include <cstdio> // auto fix CE
#include <cstdlib> // auto fix CE
#include <stdio.h>
#define eps 1e-6
#define abs(real) (((real) > 0) ? (real) : -(real))
#define zero(real) ((abs(real) < eps) ? 1 : 0)
#define output(real) (zero(real) ? 0 : (real))
const double pi = 3.1415926535897932384626433832795;
int main()
{
    int kase;
    int ri, re, m, n;
    double t, c, s[5];

    /*freopen("showinput.php", "r", stdin);
    freopen("test.out", "w", stdout);*/
    scanf("%d", &kase);
    while(kase--) {
        scanf("%d", &re);
        for (ri = 1; ri <= re; ri++) {
            scanf("%d%d%lf%lf", &m, &n, &t, &c);
            s[0] = m * n * t * t;
            s[1] = ((m - 1) * n + (n - 1) * m) * t * c;
            s[2] = ((m - 1) * (n - 1)) * c * c;
            s[4] = ((m - 1) * (n - 1)) * pi * c * c / 4.0;

            s[3] = s[2] - s[4];
            s[2] = s[1] - 2 * s[2];
            s[1] = s[0] - s[2] - s[3] - s[4];

            s[0] /= 100.0;
            s[1] /= s[0];
            s[2] /= s[0];
            s[3] /= s[0];
            s[4] /= s[0];

            printf("Case %d:\n", ri);
            printf("Probability of covering 1 tile  = %.4lf%%\n", output(s[1]));
            printf("Probability of covering 2 tiles = %.4lf%%\n", output(s[2]));
            printf("Probability of covering 3 tiles = %.4lf%%\n", output(s[3]));
            printf("Probability of covering 4 tiles = %.4lf%%\n", output(s[4]));
            if(ri != re) putchar('\n');
        }
        if(kase) putchar('\n');
    }
}
/*！！！！！！！！！！！！！！！！！！！
//输出浮点数切记不要输出-0！！！！！！！
！！！！！！！！！！！！！！！！！！！*/

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2719320 2008-01-04 14:08:20 Accepted 2888 C 00:00.14 396K わたし

// 2012-09-07 14:11:35 | Accepted | 2888 | C++ | 60 | 180 | watashi | Source

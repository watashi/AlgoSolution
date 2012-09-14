#include <cmath>
#include <cstdio>

char buf[81];
double ans;
int res;

inline double dist(char buf[])
{
    double x, y, xx, yy;

    sscanf(buf, "%lf%lf%lf%lf", &x, &y, &xx, &yy);
    x -= xx;
    y -= yy;

    return sqrt(x * x + y * y);
}

int main(void)
{
    while(gets(buf) != NULL) {
        ans = 0.0;
        while(gets(buf) != NULL && buf[0] != 'j')
            ans += dist(buf);
        res = (int)(ans * 6e-3 + 0.5);
        printf("%d:%02d\n", res / 60, res % 60);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2770351 2008-03-04 21:28:06 Accepted 1105 C++ 00:00.00 396K ¤ï¤¿¤·

// 2012-09-07 00:37:03 | Accepted | 1105 | C++ | 0 | 180 | watashi | Source

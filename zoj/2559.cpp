// -1- 内切圆，角平分线交点
// -2- 解三元一次方程

#include <cmath>
#include <cstdio>

int p[3][2];
double a, b, c;
double x, y, z;

inline double dist(int p1[], int p2[])
{
    double x = p1[0] - p2[0], y = p1[1] - p2[1];

    return sqrt(x * x + y * y);
}

int main(void)
{
    while(scanf("%d%d%d%d%d%d", &p[0][0], &p[0][1], &p[1][0], &p[1][1], &p[2][0], &p[2][1]) != EOF) {
        a = dist(p[0], p[1]);
        b = dist(p[0], p[2]);
        c = dist(p[1], p[2]);
        x = (a + b - c) / 2;
        y = (a - b + c) / 2;
        z = (-a + b + c) / 2;
        printf("%lf\n%lf\n%lf\n", x, y, z);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2795892 2008-03-22 00:24:45 Accepted 2559 C++ 00:00.00 396K わたし

// 2012-09-07 01:28:23 | Accepted | 2559 | C++ | 0 | 180 | watashi | Source

//模线性方程

#include <cstdio>

long long extGcd(long long a, long long b, long long& x, long long& y)
{
    long long t, ret;

    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ret = extGcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return ret;
}

int main(void)
{
    long long a, b, c, k, x, y, d;

    while(scanf("%lld%lld%lld%lld", &b, &c, &a, &k) != EOF && k > 0) {
        k = 1LL << k;
        b = c - b;
        if(b < 0) b += k;
        d = extGcd(a, k, x, y);
        if(b % d != 0) {
            printf("FOREVER\n");
            continue;
        }
        k /= d;
        c = x * (b / d) % k;
        if(c < 0) c += k;
        printf("%lld\n", c);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2795969 2008-03-22 02:38:34 Accepted 2305 C++ 00:00.00 428K わたし

// 2012-09-07 01:17:51 | Accepted | 2305 | C++ | 0 | 180 | watashi | Source

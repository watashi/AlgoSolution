#include <cstdio>

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main(void)
{
    int t, n, b, d, num, den;

    scanf("%d", &t);
    while(t--) {
        scanf("%d.%d", &num, &den);
        num = num * 100 + den;
        den = 100;
        d = gcd(num, den);
        num /= d;
        den /= d;
        d = 0;
        scanf("%d", &n);
        while(n--) {
            scanf("%d", &b);
            d = gcd(b, d);
        }
        while(d > 0 && (d & 1) == 0) d >>= 1;
        while(den > 0 && (den & 1) == 0) den >>= 1;
        puts((den == 1 && num % d == 0) ? "yes" : "no");
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2756982 2008-02-21 18:22:19 Accepted 2914 C++ 00:00.04 388K ¤ï¤¿¤·

// 2012-09-07 01:46:58 | Accepted | 2914 | C++ | 0 | 180 | watashi | Source

#include <cstdio>

int bin[31];
double p[31];

int len(int x)
{
    int ret = 0;

    while (x != 0) {
        x >>= 1;
        ++ret;
    }

    return ret;
}

// all y < x
double calc(int x)
{
    double ret = 0;
    int l = len(x), k = 0;

    ret = bin[l - 1] * p[l - 1];
    k = 1;
    for (int i = l - 2; i >= 0; i--) {
        if ((x & (1 << i)) == 0) {
            continue;
        }
        ret += bin[i] * (i / 2.0 + k) / l;
        ++k;
    }

    return ret / x;
}

int main(void)
{
    int re;
    int a, b;

    p[1] = 0.5;
    bin[0] = 1;
    for (int i = 1; i < 30; i++) {
        bin[i] = bin[i - 1] + bin[i - 1];
        p[i + 1] = (1 + i / 2.0) / (i + 1);
        p[i + 1] = (p[i] + p[i + 1]) / 2;
    }
//  printf("%d\n", bin[29]);
    scanf("%d", &re);
    while (re--) {
        scanf("%d%d", &a, &b);
        printf("%.6lf\n", ((b + 1) * calc(b + 1) - a * calc(a)) / (b - a + 1));
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801104   2009-03-23 21:07:31     Accepted    3162    C++     0   176     watashi@Zodiac

// 2012-09-07 02:04:53 | Accepted | 3162 | C++ | 0 | 180 | watashi | Source

#include <cmath>
#include <cstdio>
#include <cstdlib>

// Hi+1 = 2 * Hi + 1 - Hi-1

double h[1024];

bool calc(int n, double a, double m)
{
    bool ret = true;

    h[1] = a;
    h[2] = m;
    for (int i = 3; i <= n; i++) {
        h[i] = 2 * (h[i - 1] + 1) - h[i - 2];
        if (h[i] < 0.0) {
            ret = false;
        }
    }

    return ret;
}

int main()
{
    int re, n;
    double a, l, r, m;

    scanf("%d", &re);
    while (re--) {
        scanf("%d%lf", &n, &a);
        l = 0;
        r = a;
        while (r - l > 1e-8) {
            m = (l + r) / 2.0;
            if (calc(n, a, m)) {
                r = m;
            }
            else {
                l = m;
            }
        }
        calc(n, a, (l + r) / 2);
        // fabs is better than +eps when to avoid -0.00
        printf("%.2lf\n", fabs(h[n]));
        if (re) {
            putchar('\n');
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1647444   2008-09-19 16:52:36     Accepted    2056    C++     0   264     watashi

// 2012-09-07 01:11:28 | Accepted | 2056 | C++ | 0 | 188 | watashi | Source

#include <cstdio>

const long long inf = 12345678987654321LL;

long long trans(long long a, long long b)
{
    long long ret;

    a *= 10;
    ret = a / b;
    a %= b;
    if (a + a >= b) {
        ++ret;
    }

    return ret;
}

int main(void)
{
    int n, k, l, m;
    long long a, b, c, ini, ans;
    double kk, ll;

    while (scanf("%d%lf%lf%d", &n, &kk, &ll, &m) != EOF) {
        k = (int)(kk * 10 + 0.1);
        l = (int)(ll * 10 + 0.1);
        if (l < 10) {
            printf("-1\n");
            continue; // nc "break;" -_-b
        }
        else if(k <= l) {
            printf("0\n");
            continue; // big_nc @@
        }

        a = 0;
        b = inf;
        while (a < b) {
            c = (a + b) / 2;
            if (trans(c, m) <= k) {
                a = c + 1;
            }
            else {
                b = c;
            }
        }
        ini = b - 1;
        if (ini > n * m) {
            ini = n * m;
        }

        a = 0;
        b = inf;
        while (a < b) {
            c = (a + b) / 2;
            if (trans(ini + c, c + m) > l) {
                a = c + 1;
            }
            else {
                b = c;
            }
        }
        ans = b;

        printf("%lld\n", ans);
    }

    return 0;
}

//27369     2008-07-08 10:24:49       Accepted      1019    C++     120     260     watashi     Source

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3040705   2008-08-18 16:24:10     Accepted    3021    C++     00:00.30    392K    Re:ReJudge
//

// 2012-09-07 01:55:48 | Accepted | 3021 | C++ | 120 | 180 | watashi | Source

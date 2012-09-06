#include <cstdio>

const int INT = 8192;
const double DBL = 1.0 / INT;

int main(void)
{
    int re;
    long long ini, ans, r, f, a, b;
    int m, n, type;
    double dbl;

    scanf("%d", &re);
    while(re--) {
        scanf("%lld%d%d", &ini, &m, &n);
        ans = 0;
        while(n--) {
            scanf("%d%lf%lld", &type, &dbl, &f);
            r = (long long)(dbl / DBL + 0.5);
            a = ini;
            b = 0;
            if(type == 0) {
                for (int i = 0; i < m; i++) {
                    b += a * r / INT;
                    a -= f;
                }
            }
            else {
                for (int i = 0; i < m; i++) {
                    a += a * r / INT;
                    a -= f;
                }
            }
            if(a + b > ans)
                ans = a + b;
        }
        printf("%lld\n", ans);
    }
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2842407   2008-04-13 20:55:25     Accepted    2789    C++     00:00.00    396K    Re:ReJudge

// 2012-09-07 01:40:02 | Accepted | 2789 | C++ | 0 | 180 | watashi | Source

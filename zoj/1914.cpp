// 可以全int最后答案再sqrt，而且这样二分次数更少

#include <cstdio>

bool mark[512];
int n;
double x[512], y[512], d[512][512], dd;

inline double sqr(double x)
{
    return x * x;
}

void dfs(int p)
{
    mark[p] = true;
    for (int i = 0; i < n; i++) {
        if (!mark[i] && d[p][i] <= dd) {
            dfs(i);
        }
    }
}

int main(void)
{
    int re, m, c;
    double l, r, mid;

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &x[i], &y[i]);
            d[i][i] = 0;
            for (int j = 0; j < i; j++) {
                d[i][j] = d[j][i] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
            }
        }
        l = 0;
        r = 1e6;
        while (r - l > 1e-6) {
            mid = (l + r) / 2;
            dd = sqr(mid);
            for (int i = 0; i < n; i++) {
                mark[i] = false;
            }
            c = 0;
            for (int i = 0; i < n; i++) {
                if (!mark[i]) {
                    ++c;
                    dfs(i);
                }
            }
            if (c <= m) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        printf("%.2lf\n", (l + r) / 2);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3026393 2008-08-07 13:48:28 Accepted 1914 C++ 00:00.37 2504K Re:ReJudge
//

// 2012-09-07 01:06:07 | Accepted | 1914 | C++ | 180 | 2236 | watashi | Source

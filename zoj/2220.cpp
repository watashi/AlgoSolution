#include <cstdio>

inline int Min(const int x, const int y)
{
    return (x < y) ? x : y;
}

inline int Sqr(const int x)
{
    return x * x;
}

inline int SumOfSqr(const int x, const int y)
{
    return Sqr(x) + Sqr(y);
}

int main(void)
{
    int re;
    int s, h, r, d;
    int p[51][2];
    bool flag;

    scanf("%d", &re);
    while(re--) {
        scanf("%d%d", &s, &h);
        for (int i = 0; i < h; i++)
            scanf("%d%d", &p[i][0], &p[i][1]);
        for (int i = 1; i < s; i++)
            for (int j = 1; j < s; j++) {
                r = Min(Min(i - 0, s - i), Min(j - 0, s - j));
                r = Sqr(r);
                flag = true;
                for (int k = 0; k < h; k++) {
                    d = SumOfSqr(i - p[k][0], j - p[k][1]);
                    if(d > r || d == 0) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    printf("%d %d\n", i, j);
                    goto GOTO;
                }
            }
        puts("poodle");
GOTO:
        ;
    }
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2842500   2008-04-13 21:30:29     Accepted    2220    C++     00:00.01    392K    Re:ReJudge

// 2012-09-07 01:16:13 | Accepted | 2220 | C++ | 0 | 180 | watashi | Source

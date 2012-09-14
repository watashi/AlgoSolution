/*
[quote="Ice_Ax"]
证明：最优解中一定存在相邻两点间没有边。
若每相邻两点都有边相连，那么我们把所有顺时针的边的长度减去所有逆时针的边的长度得到P。
若p>0，把每个顺时针的边的权减去1，逆时针的加上1，这样每个点最终的货物量不变，但是总cost会减少p。不断进行这个步骤，cost会不断减少，直到有一个边的权变成0（也就是消失了……）；P<0也一样。
[/quote]
*/

#include <cmath>
#include <cstdio>
double a[2002], d[2002];
int main(void)
{
    int re;
    int n;
    double s, t, ans;

    scanf("%d", &re);
    while(re--) {
        scanf("%d", &n);
        s = 0.0;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
            s += a[i];
        }
        t = 0.0;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &d[i]);
            t += d[i];
        }
        for (int i = 0; i < n; i++) {
            a[i] -= d[i] / t * s;
            scanf("%lf", &d[i]);
        }
        ans = -1;
        for (int i = 0; i < n; i++) {
            s = t = 0.0;
            for (int j = i; j < n; j++) {
                t = a[j] + t;
                s += d[j] * fabs(t);
            }
            for (int j = 0; j < i; j++) {
                t = a[j] + t;
                s += d[j] * fabs(t);
            }
            if(ans < 0 || s < ans)
                ans = s;
        }
        printf("%.2lf\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2813588 2008-03-31 15:31:07 Accepted 2951 C++ 00:00.61 424K わたし

// 2012-09-07 01:49:31 | Accepted | 2951 | C++ | 180 | 212 | watashi | Source

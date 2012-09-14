// jiong ti

#include <cstdio>

int a[10001], b[10001];

int main(void)
{
    int re;
    int na, nb, sa, sb;
    int ans;
    long long cost; // orz

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++) {
        scanf("%d%d", &na, &nb);
        sa = 0;
        for (int i = 0; i < na; i++) {
            scanf("%d", &a[i]);
            sa += a[i];
        }
        sb = 0;
        for (int i = 0; i < nb; i++) {
            scanf("%d", &b[i]);
            sb += b[i];
        }
        ans = (sa < sb) ? sa : sb;
        cost = 0;
        sa = ans;
        for (int i = 0; sa > 0 && i < na; i++) {
            if(sa <= a[i]) {
                cost += sa * i;
                sa = 0;
            }
            else {
                cost += a[i] * i;
                sa -= a[i];
            }
        }
        sb = ans;
        for (int i = 0; sb > 0 && i < nb; i++) {
            if(sb <= b[i]) {
                cost += sb * i;
                sb = 0;
            }
            else {
                cost += b[i] * i;
                sb -= b[i];
            }
        }
        cost += (ans << 1);
        printf("Case %d:\n%d %lld\n", ri, ans, cost);
        if(ri < re)
            putchar('\n');
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2874840   2008-04-27 18:44:28     Accepted    2541    C++     00:00.05    472K    Re:ReJudge

// 2012-09-07 01:27:22 | Accepted | 2541 | C++ | 10 | 256 | watashi | Source

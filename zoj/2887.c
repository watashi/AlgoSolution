#include <stdio.h>
#include <stdlib.h>
int mind[1000];
int q[1000];
int pos[1000][2];
/*int unsigned int ¶¼Òç³ö*/
double dist(int i, int j)
{
    double x = abs(pos[i][0] - pos[j][0]);
    double y = abs(pos[i][1] - pos[j][1]);
    return x * x + y * y;
}
int main()
{
    int kase, re;
    int i, n, f, t, p, e;
    double l, ll;

    scanf("%d", &kase);
    while(kase--) {
        scanf("%d", &re);
        while(re--) {
            scanf("%d", &n);
            scanf("%d%d", &f, &t);
            f--;
            t--;
            scanf("%lf%lf", &l, &ll);
            l += ll;
            l *= l;
            for (i = 0; i < n; i++) {
                scanf("%d%d", &pos[i][0], &pos[i][1]);
                mind[i] = -1;
            }
            q[0] = f;
            mind[f] = 0;
            p = 0;
            e = 1;
            while(mind[t] == -1 && p < e) {
                f = q[p++];
                for (i = 0; i < n; i++) {
                    if(mind[i] == -1 && dist(f, i) <= l) {
                        mind[i] = mind[f] + 1;
                        q[e++] = i;
                    }
                }
            }
            if(mind[t] == -1) puts("Impossible");
            else printf("%d\n", mind[t]);
        }
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2717862 2008-01-01 21:31:55 Accepted 2887 C 00:00.64 412K ¤ï¤¿¤· */

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //127 2007-12-27 22:43:44 Accepted 1012 C 00:00:62 412K ¤ï¤¿¤· */

// 2012-09-07 01:44:55 | Accepted | 2887 | C | 220 | 176 | watashi | Source

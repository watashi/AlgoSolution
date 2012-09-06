/* //-_- (A + B) / 2 with for .. ms */

#include <stdio.h>
int main()
{
    int n;
    double x, y, a, b, c, d;

    while(scanf("%d", &n) != EOF) {
        printf("%d", n);
        scanf("%lf%lf", &x, &y);
        a = x;
        b = y;
        while(--n) {
            scanf("%lf%lf", &c, &d);
            printf(" %.6lf %.6lf", (a + c) / 2.0, (b + d) / 2.0);
            a = c;
            b = d;
        }
        printf(" %.6lf %.6lf\n", (a + x) / 2.0, (b + y) / 2.0);
    }

    return 0;   /* NZEC */
}


/* //Run ID     Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name */
/* //2721826    2008-01-08 22:32:28     Accepted    1973    C   00:00.02    396K    ¤ï¤¿¤· */

// 2012-09-07 03:07:43 | Accepted | 1973 | C | 20 | 160 | watashi | Source

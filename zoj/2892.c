#include <stdio.h>
#include <string.h>
int main()
{
    int i, p, m, n;
    int a[2][256];

    while(scanf("%d", &n) != EOF && n) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a[0][i]);
            a[1][i] = a[0][i];
        }
        p = 1;
        for (m = 1; m < n; m <<= 1){
            p = !p;
            for (i = 0; i < m; i++) {
                a[!p][i << 1] = (a[p][i] + a[p][m + i]) >> 1;
                a[!p][(i << 1) + 1] = (a[p][i] - a[p][m + i]) >> 1;
            }
        }
        p = !p;
        for (i = 0; i < n; i++) {
            if(i) putchar(' ');
            printf("%d", a[p][i]);
        }
        putchar('\n');
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2717872 2008-01-01 21:36:27 Accepted 2892 C 00:00.54 396K わたし */


/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //55 2007-12-26 20:19:21 Accepted 1017 C 00:00:61 392K わたし */

// 2012-09-07 03:14:44 | Accepted | 2892 | C | 190 | 160 | watashi | Source

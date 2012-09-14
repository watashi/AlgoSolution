#include <stdio.h>
long long f(int n)
{
    return (long long)n * (n - 1) / 2;
}
int main()
{
    int i, n, l ,r, mid;
    long long m;

    while(scanf("%d%lld", &n, &m) != EOF && (n >= 0 && m>= 0)){
        l = 1;
        r = 50005;
        while(l < r) {
            mid = (l + r) >> 1;
            if(f(mid) < m) l = mid + 1;
            else r = mid;
        }
        r = m - f(l - 1) + 1;
        m = n - l;
        for (i = 1; i <= m; i++){
            printf("%d", i);
            if (i != n) putchar(' ');
        }
        printf("%d", m + r);
        if (m + 1 != n) putchar(' ');
        for (i = l; i > r; i--){
            printf("%d", m + i);
            if (m + l - i + 2 != n) putchar(' ');
        }
        for (i = r - 1; i > 0; i--){
            printf("%d", m + i);
            if (m + l - i + 1 != n) putchar(' ');
        }
        putchar('\n');
    }

    return 0;   /* NZEC */
}

/* //Run ID     Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name */
/* //2708692    2007-12-21 22:47:44     Accepted    2425    C   00:00.09    396K    ¤ï¤¿¤· */

// 2012-09-07 03:10:22 | Accepted | 2425 | C | 60 | 160 | watashi | Source

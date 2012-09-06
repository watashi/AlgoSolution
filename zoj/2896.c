/* //1002   Cache  4.27% (15/351) */

/* //误差累积大， eps要小， 可以用bignum做 */
#include <stdio.h>
#define eps 1e-6
#define abs(x) (((x) < 0) ? -(x) : x)
#define zero(x) (abs(x) < eps)

int na, nb;
double fa[101], fb[101];

int doit(int na, double fa[], int nb, double fb[])
{
    int i, j;
    double t;

    if(na < nb) return doit(nb, fb, na, fa);
    if(nb == -1) return na > 0;
    t = fa[na] / fb[nb];
    for(i = na - 1, j = nb - 1; j>=0; i--, j--)
        fa[i] -= t * fb[j];
    do {
        --na;
    }while(na >= 0 && zero(fa[na]));
    return doit(na, fa, nb, fb);
}

int main()
{
    int i;

    while(scanf("%d%d", &na, &nb) != EOF) {
        for (i = na; i >= 0; --i)
            scanf("%lf", &fa[i]);
        for (i = nb; i >= 0; --i)
            scanf("%lf", &fb[i]);
        puts(doit(na, fa, nb, fb) ? "YES" : "NO");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2735529 2008-01-27 17:13:53 Accepted 2896 C 00:00.01 392K わたし */

// 2012-09-07 03:14:56 | Accepted | 2896 | C | 0 | 160 | watashi | Source

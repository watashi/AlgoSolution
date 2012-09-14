#include <stdio.h>
#include <math.h>
int main()
{
    int ri,re,m,n;
    const double a=sqrt(2)-1;

    scanf("%d",&re);
    for(ri=1;ri<=re;ri++){
        scanf("%d%d",&n,&m);
        printf("Scenario #%d:\n",ri);
        if((m&1)&&(n&1)) printf("%.2lf\n",m*n+a);
        else  printf("%.2lf\n",(double)m*n);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2594784 2007-09-03 17:11:56 Accepted 1037 C 00:00.05 400K わたし */
/* //2594783 2007-09-03 17:11:30 Presentation Error 1037 C 00:00.04 404K わたし */

// 2012-09-07 02:54:48 | Accepted | 1037 | C | 10 | 160 | watashi | Source

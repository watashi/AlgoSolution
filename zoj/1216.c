/*简单物理分析知1/2n是也*/
#include <stdio.h>
int main()
{
    double sum;
    long i,n;

    printf("# Cards  Overhang\n");
    while(scanf("%ld",&n)!=EOF){
        sum=0;
        for(i=1;i<=n;i++)
            sum+=0.5/i;
        printf("%5ld%10.3lf\n",n,sum);
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //easy. */
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469460 2007-05-29 12:10:52 Accepted 1216 C 00:00.05 392K わたし */

// 2012-09-07 02:57:52 | Accepted | 1216 | C | 20 | 160 | watashi | Source

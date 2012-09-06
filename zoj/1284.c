#include <stdio.h>
int main()
{
    long i,x,sum;

    printf("PERFECTION OUTPUT\n");
    while(scanf("%ld",&x),x){
        sum=0;
        for(i=1;i<=x/2;i++)
            if(x%i==0) sum+=i;
        if(sum==x) printf("%5ld  PERFECT\n",x);
        else if(sum>x) printf("%5ld  ABUNDANT\n",x);
        else printf("%5ld  DEFICIENT\n",x);
    }
    printf("END OF OUTPUT\n");

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2471041 2007-05-29 23:47:48 Accepted 1284 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 02:58:41 | Accepted | 1284 | C | 0 | 160 | watashi | Source

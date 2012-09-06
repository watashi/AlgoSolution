#include <stdio.h>
int main()
{
    int I,N,i,n;
    long res;

    scanf("%d",&N);
    I=0;
    while(I<N){
        scanf("%d",&n);
        res=0;
        for(i=1;i<=n;i++)
            res+=i*(i+1)*(i+2)/2;
        printf("%d %d %ld\n",++I,n,res);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2498696 2007-06-21 00:43:45 Accepted 2773 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:12:54 | Accepted | 2773 | C | 0 | 160 | watashi | Source

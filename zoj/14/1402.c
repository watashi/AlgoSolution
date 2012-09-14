#include <stdio.h>
int main()
{
    int i,j,n,a[30],sum1,sum2;

    while(scanf("%d",&n),n!=0){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            sum1=sum2=0;
            for(j=0;j<=i-1;j++)
                sum1+=a[j];
            for(j=0;j<=n-1-i;j++)
                sum2+=a[n-1-j];
            if(sum1==sum2) break;
        }
        if(sum1==sum2) printf("Sam stops at position %d and Ella stops at position %d.\n",i-1+1,i+1);
        else printf("No equal partitioning.\n");
    }

    return 0;   /* NZEC */
}


/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469495 2007-05-29 12:25:57 Accepted 1402 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:00:55 | Accepted | 1402 | C | 0 | 160 | watashi | Source

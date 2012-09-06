#include <stdio.h>
int main()
{
    int i,j,index,n,t,a[100];

    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            index=i;
            for(j=i+1;j<n;j++)
                if(a[index]>a[j]) index=j;
            t=a[index];
            a[index]=a[i];
            a[i]=t;
        }
        printf("%d",a[0]);
        for(i=1;i<n;i++)
            if(a[i]!=a[i-1]) printf(" %d",a[i]);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2481475 2007-06-06 01:23:43 Accepted 2481 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:10:46 | Accepted | 2481 | C | 0 | 160 | watashi | Source

#include <stdio.h>
int main()
{
    int i,j,n,count,a[20];

    while(1){
        count=0;
        if(i=0,scanf("%d",&a[i]),a[i]==-1) break;
        while(a[i]){
            i++;
            scanf("%d",&a[i]);
        }
        n=i;
        for(i=0;i<n;i++)
            if(a[i]%2==0)
                for(j=0;j<n;j++)
                    if(a[i]==2*a[j]){
                        count++;
                        break;
                    }
        printf("%d\n",count);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2475704 2007-06-01 23:35:12 Accepted 1760 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:04:49 | Accepted | 1760 | C | 0 | 160 | watashi | Source

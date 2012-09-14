#include <stdio.h>
int main()
{
    int i,j,n,o,d,sum,a[10000];

    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d%d",&o,&d);
            a[i]=o-d;
        }
        for(i=0;i<n;i++){
            sum=0;
            for(j=i;j<n;j++){
                sum+=a[j];
                if(sum<0) break;
            }
            for(j=0;j<i;j++){
                if(sum<0) break;
                sum+=a[j];
            }
            if(sum>=0) break;
        }
        if(i<n) printf("%d\n",i);
        else printf("impossible\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2497009 2007-06-19 14:08:50 Accepted 2656 C 00:01.97 428K ¤ï¤¿¤· */

// 2012-09-07 03:12:06 | Accepted | 2656 | C | 670 | 160 | watashi | Source

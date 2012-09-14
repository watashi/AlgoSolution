#include <stdio.h>
int main()
{
    int i,j,k,s,n;
    int m[50],p[50];
    double ans;

    ans=1;
    while(scanf("%d%d",&n,&k)!=EOF && n>=0&&k>=0){
        s=0;
        for(i=0;i<n;i++){
            scanf("%d",&m[i]);
            s+=m[i];
        }
        for(i=0;i<n;i++)
            scanf("%d",&p[i]);
        if(k>s){
            printf("%.5lf\n",0);
            continue;
        }
        ans=1;
        for(i=0;i<n;i++)
            for(j=1;j<=p[i];j++)
                ans*=(double)(m[i]+1-j)/j;
        for(j=1;j<=k;j++)
            ans*=(double)j/(s+1-j);
        printf("%.5lf\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2652750 2007-10-21 09:44:43 Accepted 2098 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:08:07 | Accepted | 2098 | C | 0 | 160 | watashi | Source

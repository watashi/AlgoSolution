#include <stdio.h>
int main()
{
    int i,j,k,n,m,dk,nk,dp[10001],blank=0;

    while(scanf("%d%d",&n,&m)!=EOF){
        if(blank) printf("\n");
        else blank=1;
        dp[0]=1;
        for(i=1;i<=n;i++)
            dp[i]=0;
        while(m--){
            scanf("%d%d",&dk,&nk);
            for(i=n;i>=0;i--)
                if(dp[i]){
                    k=i+dk;
                    for(j=nk;j&&k<=n;j--,k+=dk)
                        dp[k]+=dp[i];
                }
        }
        printf("%d\n",dp[n]);
    }

    return 0;   /* NZEC */
}

/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2584241 2007-08-26 01:01:56 Accepted 2734 C++ 00:00.01 428K ¤ï¤¿¤·
*/

// 2012-09-07 03:12:30 | Accepted | 2734 | C | 0 | 160 | watashi | Source

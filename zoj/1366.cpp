#include <stdio.h>
int main()
{
    bool dp[100100];
    int i,j,k,n,m,nk,dk;

    while(scanf("%d%d",&n,&m)!=EOF){
        dp[0]=1;
        for(i=1;i<=n;i++)
            dp[i]=0;
        while(m--){
            scanf("%d%d",&nk,&dk);
            for(i=n;i>=0;i--)
                if(dp[i]){
                    k=i+dk;
                    for(j=nk;j&&k<=n;j--,k+=dk)
                        if(dp[k]) break;
                        else dp[k]=1;
                }
        }
        for(i=n;i;i--)
            if(dp[i]) break;
        printf("%d\n",i);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2584215 2007-08-26 00:28:18 Accepted 1366 C++ 00:00.02 488K ¤ï¤¿¤·

// 2012-09-07 00:47:37 | Accepted | 1366 | C++ | 20 | 180 | watashi | Source

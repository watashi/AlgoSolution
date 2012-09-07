#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    int ri,re,n,m,i,j;
    long long dp[11][2001];//BIG_NUM

    scanf("%d",&re);
    for(j=0;j<2001;j++)
        dp[0][j]=j;
    for(ri=1;ri<=re;ri++){
        scanf("%d%d",&n,&m);
        for(i=1;i<n;i++){
            dp[i][0]=dp[i-1][0];
            for(j=1;j<=m;j++)
                dp[i][j]=dp[i][j-1]+dp[i-1][j/2];
        }
        printf("Case %d: n = %d, m = %d, # lists = %lld\n",ri,n,m,dp[n-1][m]);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2550224 2007-08-02 21:03:58 Accepted 2402 C 00:00.00 560K ¤ï¤¿¤·

// 2012-09-07 14:10:27 | Accepted | 2402 | C++ | 0 | 180 | watashi | Source

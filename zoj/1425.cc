//dp
#include <cstdio> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
int dp[101][101];
int a[101],b[101],na,nb;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int i,j,ii,jj,m;

    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&na,&nb);
        dp[0][0]=0;
        for(i=1;i<=na;i++){
            dp[i][0]=0;
            scanf("%d",&a[i]);
        }
        for(j=1;j<=nb;j++){
            dp[0][j]=0;
            scanf("%d",&b[j]);
        }
        for(i=1;i<=na;i++)
            for(j=1;j<=nb;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(a[i]==b[j]) continue;//最坏O(n^3)
                ii=i-1;
                while(ii&&a[ii]!=b[j]) --ii;
                if(ii==0) continue;
                jj=j-1;
                while(jj&&b[jj]!=a[i]) --jj;
                if(jj==0) continue;
                if(dp[ii-1][jj-1]+2>dp[i][j]) dp[i][j]=dp[ii-1][jj-1]+2;
            }
        printf("%d\n",dp[na][nb]);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2680956 2007-11-20 15:16:53 Accepted 1425 C 00:00.00 428K わたし

//水了一点O(n^4)也过

// 2012-09-07 14:08:34 | Accepted | 1425 | C++ | 0 | 220 | watashi | Source

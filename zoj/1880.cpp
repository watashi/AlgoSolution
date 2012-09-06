#include <cstdio>
#include <string.h>
bool dp[25000][52];
int main()
{
    int i,j,k,n,a[101],sum,m;

    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof dp);
        sum=0;
        for(k=0;k<n;k++){
            scanf("%d",&a[k]);
            sum+=a[k];
        }
        if(n&1) m=(n+1)>>1;
        else m=n>>1;
        dp[0][0]=1;
        for(k=0;k<n;k++)
            for(i=a[k];i<=sum>>1;i++)
                for(j=m;j>=0;j--)
                    if(dp[i-a[k]][j-1]) dp[i][j]=true;
        if(n&1){
            for(i=sum>>1;i;i--)
                if(dp[i][m]||dp[i][m-1]) break;
        }
        else{
            for(i=sum>>1;i;i--)
                if(dp[i][m]) break;
        }
        printf("%d %d\n",i,sum-i);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2633536 2007-10-05 19:07:06 Accepted 1880 C++ 00:01.23 1664K ¤ï¤¿¤·

// 2012-09-07 01:04:11 | Accepted | 1880 | C++ | 480 | 1448 | watashi | Source

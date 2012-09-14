#include <stdio.h>
#include <string.h>
#define MAXN(a,b) (((a)>(b))?(a):(b))
int dp[2002][2002];
char a[2002],b[2002];
int la,lb;
int v[256];
int main()
{
    int i,j,n;

    while(scanf("%d",&n)!=EOF){
        memset(v,0,sizeof(v));
        while(n--){
            scanf("%s",a);
            scanf("%d",&v[*a]);
        }
        memset(dp,0,sizeof(dp));
        scanf("%s%s",a+1,b+1);
        la=strlen(a+1);lb=strlen(b+1);
        for(i=1;i<=la;i++)
            for(j=1;j<=lb;j++){
                dp[i][j]=MAXN(dp[i-1][j],dp[i][j-1]);
                if(a[i]==b[j]&&dp[i-1][j-1]+v[a[i]]>dp[i][j]) dp[i][j]=dp[i-1][j-1]+v[a[i]];
            }
        printf("%d\n",dp[la][lb]);
    }

    return 0;   /* NZEC */
}

/* //2686373 2007-11-26 22:29:02 Accepted 1642 C 00:00.26 16048K 再做几题改成Fire */

// 2012-09-07 03:03:36 | Accepted | 1642 | C | 80 | 15820 | watashi | Source

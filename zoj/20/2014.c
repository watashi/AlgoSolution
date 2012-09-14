#include <stdio.h>
#define INF 999999999
typedef struct{
    int p,w;
}Coin;
int main()
{
    int re,i,j,k,n,w,dp[10001];
    Coin a[500];

    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&i,&j);
        w=j-i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i].p,&a[i].w);
        dp[0]=0;
        for(j=1;j<=w;j++){
            dp[j]=INF;
            for(i=0;i<n;i++){
                k=j-a[i].w;
                if(k>=0&&dp[k]+a[i].p<dp[j])
                    dp[j]=dp[k]+a[i].p;
            }
        }
        if(dp[w]==INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2578766 2007-08-21 23:43:11 Accepted 2014 C++ 00:00.31 436K ¤ï¤¿¤· */

// 2012-09-07 01:10:21 | Accepted | 2014 | C | 140 | 160 | watashi | Source

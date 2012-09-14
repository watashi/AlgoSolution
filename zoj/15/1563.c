#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define inf 2000000000
int a[108],p[108];
int dp[108][108];
/*The qualities of the classes (and so the prices) are given in ascending order. */
int main()
{
    int re;
    int i,j,n;

    scanf("%d",&re);
    while(re--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i],&p[i]);
        dp[n-1][n-1]=(a[n-1]+10)*p[n-1];
        for(i=n-2;i>=0;i--){
            dp[i][i]=inf;
            for(j=i+1;j<n;j++){
                if(dp[i+1][j]<dp[i][i]) dp[i][i]=dp[i+1][j];
                dp[i][j]=dp[i+1][j]+a[i]*p[j];
            }
            dp[i][i]+=(a[i]+10)*p[i];
        }
        for(j=1;j<n;j++)
            if(dp[0][j]<dp[0][0]) dp[0][0]=dp[0][j];
        printf("%d\n",dp[0][0]);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2684785 2007-11-25 00:34:03 Accepted 1563 C 00:00.00 436K ¤ï¤¿¤· */

// 2012-09-07 00:54:01 | Accepted | 1563 | C | 0 | 204 | watashi | Source

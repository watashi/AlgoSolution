#include <stdio.h>
#define INF 999999999
int main()
{
    int i,j,k,n,t,min,a[100],dp[100][100];

    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<n;i++)
            dp[i-1][i]=0;
        for(k=2;k<n;k++){
            for(i=0;i<n-k;i++){
                min=INF;
                for(j=i+1;j<i+k;j++){
                    t=dp[i][j]+dp[j][i+k]+a[i]*a[j]*a[i+k];
                    if(t<min) min=t;
                }
                dp[i][i+k]=min;
            }
        }
        printf("%d\n",dp[0][n-1]);
    }

    return 0;   /* NZEC */
}

/* //2546654 2007-07-31 22:22:28 Accepted 1602 C 00:00.00 428K ¤ï¤¿¤· */

// 2012-09-07 03:03:03 | Accepted | 1602 | C | 0 | 160 | watashi | Source

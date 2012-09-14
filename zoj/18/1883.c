#include <stdio.h>
int main()
{
    int i,j,n,k;
    double ans,dp[108][10];


    while(scanf("%d%d",&k,&n)!=EOF){
        if(k<=1){printf("100.00000\n");continue;}
        for(j=0;j<=k;j++)
            dp[1][j]=100;
        for(i=2;i<=n;i++){
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
            for(j=1;j<k;j++)
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
            dp[i][k]=dp[i-1][k-1]+dp[i-1][k];
        }
        ans=0;
        for(j=0;j<=k;j++)
            ans+=dp[n][j];
        for(i=0;i<n;i++)
            ans/=k+1;
        printf("%.5lf\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2601475 2007-09-08 20:30:37 Accepted 1883 C 00:00.00 400K ¤ï¤¿¤· */

// 2012-09-07 03:06:36 | Accepted | 1883 | C | 0 | 160 | watashi | Source

#include <stdio.h>
#include <string.h>
#define inf 999999999
int mp[33][33];
int dp[33][33][33];
int main()
{
    int re;
    int i,j,k,d,n,ans;

    scanf("%d",&re);
    while(re--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            mp[i][i]=0;
            for(j=i+1;j<n;j++){
                scanf("%d",&mp[i][j]);
                mp[j][i]=mp[i][j];
            }
        }
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++){
                    dp[i][j][k]=inf;
                    /*if(mp[i][k]+mp[k][j]<mp[i][j]) mp[i][j]=mp[i][k]+mp[k][j];*//*居然反而WA了-_-b*/
                }
        dp[0][0][0]=0;
        for(d=1;d<n;d++)
            for(i=0;i<d;i++)
                for(j=0;j<d;j++){
                    if(i!=d-1&&j!=d-1){
                        if(dp[i][j][d-1]+mp[i][d]<dp[d][j][d-1]) dp[d][j][d-1]=dp[i][j][d-1]+mp[i][d];
                        if(dp[i][j][d-1]+mp[j][d]<dp[i][d][d-1]) dp[i][d][d-1]=dp[i][j][d-1]+mp[j][d];
                        if(dp[i][j][d-1]+mp[d-1][d]<dp[i][j][d]) dp[i][j][d]=dp[i][j][d-1]+mp[d-1][d];
                    }
                    else{
                        for(k=0;k<d;k++){
                            if(dp[i][j][k]+mp[i][d]<dp[d][j][k]) dp[d][j][k]=dp[i][j][k]+mp[i][d];
                            if(dp[i][j][k]+mp[j][d]<dp[i][d][k]) dp[i][d][k]=dp[i][j][k]+mp[j][d];
                            if(dp[i][j][k]+mp[k][d]<dp[i][j][d]) dp[i][j][d]=dp[i][j][k]+mp[k][d];
                        }
                    }
                }
        d=n-1;
        ans=inf;
        for(i=0;i<=d;i++)
            for(j=0;j<=d;j++){
                if(dp[d][i][j]<ans) ans=dp[d][i][j];
                if(dp[i][d][j]<ans) ans=dp[i][d][j];
                if(dp[i][j][d]<ans) ans=dp[i][j][d];
            }
        printf("%d\n",ans);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2659267 2007-10-26 16:07:15 Accepted 1428 C 00:00.00 536K わたし */

// 2012-09-07 00:49:14 | Accepted | 1428 | C | 0 | 304 | watashi | Source

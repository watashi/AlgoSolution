#include <cstdio> // auto fix CE
#include <stdio.h>
#define inf 999999999
int np,pr[1500];
int dp[10001][2];
int main()
{
    int i,j,k;

    pr[0]=2;
    k=1;
    for(i=3;i<10001;i+=2){
        for(j=0;j<k;j++)
            if(i%pr[j]==0) break;
        if(j==k) pr[k++]=i;
    }
    np=k;
    for(k=1;k<=10000;k++)
        dp[k][0]=inf;
    dp[0][0]=0;
    dp[0][1]=0;
    //non-increasing. If there is a tie, output the one in order of smallest dictionary order.
    for(i=0;i<np;i++){
        for(j=pr[i];j<=10000;j++){
            if(dp[j][0]>dp[j-pr[i]][0]+1){
                dp[j][0]=dp[j-pr[i]][0]+1;
                dp[j][1]=pr[i];
            }
        }
    }
    /*
    for(i=np-1;i>=0;i--){
        for(j=pr[i];j<=10000;j++){
            if(dp[j][0]>dp[j-pr[i]][0]){
                dp[j][0]=dp[j-pr[i]][0]+1;
                dp[j][1]=pr[i];
            }
        }
    }
    */

    while(scanf("%d",&k)!=EOF){
        if(k<2){
            //printf("0\n\n");//PE
            printf("0\n");
            continue;
        }
        printf("%d\n",dp[k][0]);
        printf("%d",dp[k][1]);
        while(k-=dp[k][1]){
            printf(" %d",dp[k][1]);
        }
        printf("\n");
    }
}
/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2651539 2007-10-20 12:28:26 Accepted 2414 C 00:00.16 476K わたし
2651538 2007-10-20 12:28:09 Accepted 2414 C++ 00:00.17 476K わたし
2651537 2007-10-20 12:27:22 Presentation Error 2414 C 00:00.16 476K わたし
2651536 2007-10-20 12:27:06 Presentation Error 2414 C++ 00:00.17 476K わたし
*/

// 2012-09-07 14:10:33 | Accepted | 2414 | C++ | 60 | 264 | watashi | Source

#include <stdio.h>
#define inf 999999999
int lk,ll;
char sk[81],sl[81];
int a[88];
int _cost[81][81];
int dp[81][81][2];
int cost(int f,int t)
{
    int i;

    if(f>=t) return 0;
    else if(_cost[f+1][t]!=-1) return _cost[f+1][t];
    else return _cost[f+1][t]=cost(f,t-1)+a[t]*(t-f+1);
}
int main()
{
    int ri,re;
    int i,j,k,t;

    scanf("%d",&re);
    for(ri=1;ri<=re;ri++){
        scanf("%d%d",&lk,&ll);
        scanf("%s%s",sk,sl);
        for(i=1;i<=ll;i++){
            scanf("%d",&a[i]);
            dp[0][i][0]=inf;
            dp[0][i][1]=-1;
            for(j=1;j<=ll;j++)
                _cost[i][j]=-1;
        }
        dp[0][0][0]=0;
        dp[0][0][1]=-1;
        for(i=1;i<=lk;i++)
            for(j=0;j<=ll;j++){
                dp[i][j][0]=inf;
                dp[i][j][1]=-1;
                for(k=0;k<=j;k++){
                    if(dp[i-1][k][0]==inf) continue;
                    t=cost(k,j);
                    if(dp[i-1][k][0]+t<dp[i][j][0]){
                        dp[i][j][0]=dp[i-1][k][0]+t;
                        dp[i][j][1]=k;
                    }
                }
            }
        a[lk+1]=ll;
        for(i=lk;i;i--)
            a[i]=dp[i][a[i+1]][1];
        printf("Keypad #%d:\n",ri);
        for(i=1;i<=lk;i++){
            printf("%c: ",sk[i-1]);
            for(j=a[i];j<a[i+1];j++)
                putchar(sl[j]);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2646910 2007-10-16 19:03:50 Accepted 2025 C 00:01.52 476K ¤ï¤¿¤· */

// 2012-09-07 01:10:39 | Accepted | 2025 | C | 600 | 236 | watashi | Source

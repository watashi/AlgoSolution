/* //可以用滚动数组~~ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) ((a<b)?(a):(b))
#define inf 2000000000
int dp[5005][1010];
int l[5005];
int cmp(const void *pa,const void *pb)
{
    int a=*(int *)pa,b=*(int *)pb;

    if(a<b) return -1;
    else if(a>b) return 1;
    else return 0;
}
int main()
{
    int re;
    int i,j,k,t,m,n;

    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&m,&n);
        m+=8;
        for(i=0;i<n;i++){
            scanf("%d",&l[i]);
            dp[i][0]=0;
            for(j=1;j<=m;j++)
                dp[i][j]=inf;
        }
        qsort(l,n,sizeof(int),cmp);
        for(i=n-3;i>=0;i--){
            t=(l[i+1]-l[i])*(l[i+1]-l[i]);
            k=(n-i)/3;
            for(j=MIN(k,m);j;j--)
                dp[i][j]=MIN(dp[i+1][j],dp[i+2][j-1]+t);
        }
        printf("%d\n",dp[0][m]);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2684354 2007-11-24 15:39:33 Accepted 1234 C 00:00.81 20188K わたし */

// 2012-09-07 00:42:26 | Accepted | 1234 | C | 150 | 19924 | watashi | Source

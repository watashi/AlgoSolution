#include <stdio.h>
#include <string.h>
#define inf 1000000000
int p[1000],mp[1000][1000];
int mark[1000];
int mind[1000];
int main()
{
    int re,i,j,k,n,ans;

    scanf("%d",&re);
    while(re--){
        scanf("%d",&n);
        for(k=0;k<n;k++){
            scanf("%d",&p[k]);
            mark[k]=0;
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                scanf("%d",&mp[i][j]);
                mp[i][j]+=p[i]+p[j];
            }
        mark[0]=1;
        for(k=0;k<n;k++)
            mind[k]=mp[0][k];
        ans=0;
        for(k=1;k<n;k++){
            i=-1;
            for(j=0;j<n;j++)
                if(!mark[j]&&(i==-1||mind[j]<mind[i])) i=j;
            ans+=mind[i];
            mark[i]=1;
            for(j=0;j<n;j++)
                if(!mark[j]&&mp[i][j]<mind[j]) mind[j]=mp[i][j];
        }
        printf("%d\n",ans);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2684809 2007-11-25 01:55:38 Accepted 1586 C 00:00.20 4312K ¤ï¤¿¤· */

// 2012-09-07 00:55:03 | Accepted | 1586 | C | 50 | 4076 | watashi | Source

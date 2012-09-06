/* //最小割最大流~标号 */
#include <stdio.h>
#define inf 1000000
int n,sink,mp[22][22],flow[22][22];
int pre[22],que[22],d[22],p,q,t;
int main()
{
    int i,j,k,ans,re;
    char str[5];

    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&n,&sink);
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                mp[i][j]=flow[i][j]=0;
        for(i=0;i<n;i++){
            scanf("%s%d",str,&k);
            if(*str=='I') mp[n][i]=inf;
            while(k--){
                scanf("%d",&j);
                mp[i][j]=inf;
                mp[j][i]++;
            }
        }
        while(1){
            for(i=0;i<=n;i++)
                pre[i]=0;
            pre[n]=n+1;
            d[n]=inf;
            for(t=n,p=q=0;p<=q&&!pre[sink];t=que[p++])
                for(i=0;i<=n;i++){
                    if(!pre[i]&&(j=mp[t][i]-flow[t][i])){
                        pre[i]=t+1;
                        que[q++]=i;
                        d[i]=(d[t]<j)?d[t]:j;
                    }
                    else if(!pre[i]&&(j=flow[i][t])){
                        pre[i]=-t-1;
                        que[q++]=i;
                        d[i]=(d[t]<j)?d[t]:j;
                    }
                }
            if(!pre[sink]) break;
            for(i=sink;i!=n;){
                if(pre[i]>0){
                    flow[pre[i]-1][i]+=d[sink];
                    i=pre[i]-1;
                }
                else{
                    flow[i][-pre[i]-1]-=d[sink];
                    i=-pre[i]-1;
                }
            }
        }
        ans=0;
        for(i=0;i<=n;i++)
            ans+=flow[n][i];
        if(ans>=inf) printf("PANIC ROOM BREACH\n");
        else printf("%d\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2646016 2007-10-15 20:33:52 Accepted 2788 C 00:00.00 392K わたし */

// 2012-09-07 05:07:54 | Accepted | 2788 | C | 0 | 164 | watashi | Source

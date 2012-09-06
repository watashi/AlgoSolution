#include <stdio.h>
#define MAXN 501
#define inf 999999999
typedef struct{
    int t,n;
}TN;
const TN INF={inf,-1};
TN add(const TN a,const TN b)
{
    TN res;

    res.t=a.t+b.t;
    res.n=a.n+b.n;
    return res;
}
TN make_TN(int t,int n)
{
    TN res;

    res.t=t;
    res.n=n;
    return res;
}
int cc[MAXN];
int pre[MAXN];
TN mind[MAXN];
int vn[MAXN];
int et[MAXN][MAXN];
void Dijkstra(int n,int s)
{
    int i,j,k;
    int mark[MAXN];

    for(i=0;i<n;i++)
        {mark[i]=0;cc[i]=0;pre[i]=-1;mind[i]=INF;}
    cc[s]=1;mind[s]=make_TN(0,vn[s]);
    for(i=0;i<n;i++){
        k=-1;
        for(j=0;j<n;j++)
            if(!mark[j]&&(k==-1||mind[j].t<mind[k].t)) k=j;
        mark[k]=1;
        for(j=0;j<n;j++)
            if(!mark[j]){
                if(mind[k].t+et[k][j]<mind[j].t){
                    mind[j].t=mind[k].t+et[k][j];
                    mind[j].n=mind[k].n+vn[j];
                    pre[j]=k;
                    cc[j]=cc[k];
                }
                else if(mind[k].t+et[k][j]==mind[j].t){
                    if(mind[k].n+vn[j]>mind[j].n){mind[j].n=mind[k].n+vn[j];pre[j]=k;}
                    cc[j]+=cc[k];
                }
            }
    }
}
void putpath(t)
{
    if(pre[t]==-1) printf("%d",t);
    else{
        putpath(pre[t]);
        printf(" %d",t);
    }
}
int main()
{
    int n,m,i,j,k,s,t;

    while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&vn[i]);
            for(j=0;j<n;j++)
                et[i][j]=inf;
        }
        while(m--){
            scanf("%d%d%d",&i,&j,&k);
            if(k<et[i][j]) et[i][j]=et[j][i]=k;
        }
        Dijkstra(n,s);
        printf("%d %d\n",cc[t],mind[t].n);
        putpath(t);
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //2637605 2007-10-08 22:34:46 Accepted 2526 C 00:00.03 1388K ¤ï¤¿¤· */

// 2012-09-07 03:11:23 | Accepted | 2526 | C | 0 | 1148 | watashi | Source

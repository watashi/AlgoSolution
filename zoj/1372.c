#include <stdio.h>
#define INF 1000000
int main()
{
    int i,j,n,p,t,d,sum,mark[51],map[51][51];

    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++){
            mark[i]=map[i][i]=0;
            for(j=i+1;j<=n;j++)
                map[i][j]=map[j][i]=INF;
        }
        scanf("%d",&p);
        while(p--){
            scanf("%d%d%d",&i,&j,&d);
            if(d<map[i][j]) map[i][j]=map[j][i]=d;
        }
        p=mark[1]=1;
        sum=0;
        while(p<n){
            t=0;
            d=INF;
            for(i=1;i<=n;i++){
                if(mark[i]==0) continue;
                for(j=1;j<=n;j++){
                    if(mark[j]) continue;
                    if(map[i][j]<d){d=map[i][j];t=j;}
                }
            }
            mark[t]=1;
            p++;
            sum+=d;
        }
        printf("%d\n",sum);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2550371 2007-08-02 22:15:40 Accepted 1372 C 00:00.03 400K ¤ï¤¿¤· */

// 2012-09-07 00:47:43 | Accepted | 1372 | C | 10 | 160 | watashi | Source

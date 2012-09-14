#include <stdio.h>
#define INF 1000000
int main()
{
    int i,j,k,n,t,d,min,map[108][108];

    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++){
            map[i][i]=0;
            for(j=i+1;j<=n;j++)
                map[i][j]=map[j][i]=INF;
        }
        for(i=1;i<=n;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&j);
                scanf("%d",&map[i][j]);
            }
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(map[i][j]>map[i][k]+map[k][j])
                        map[i][j]=map[i][k]+map[k][j];
        t=0;
        min=INF;
        for(i=1;i<=n;i++){
            d=-1;
            for(j=1;j<=n;j++)
                if(map[i][j]>d) d=map[i][j];
            if(d<=min){min=d;t=i;}
        }
        if(min<INF) printf("%d %d\n",t,min);
        else printf("disjoint\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2550078 2007-08-02 19:53:47 Accepted 1082 C 00:00.00 440K ¤ï¤¿¤· */

// 2012-09-07 02:55:37 | Accepted | 1082 | C | 0 | 160 | watashi | Source

#include <stdio.h>
#define INF 54321
int main()
{
    int ri,i,j,n,t,map[21][21];

    ri=1;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=20;i++){
            map[i][i]=0;
            for(j=i+1;j<=20;j++)
                map[i][j]=map[j][i]=INF;
        }
        for(i=1;i<20;i++){
            for(j=0;j<n;j++){
                scanf("%d",&t);
                map[i][t]=map[t][i]=1;
            }
            scanf("%d",&n);
        }
        for(t=1;t<=20;t++)
            for(i=1;i<=20;i++)
                for(j=1;j<=20;j++)
                    if(map[i][j]>map[i][t]+map[t][j])
                        map[i][j]=map[i][t]+map[t][j];
        printf("Test Set #%d\n",ri++);
        while(n--){
            scanf("%d%d",&i,&j);
            printf("%d to %d: %d\n",i,j,map[i][j]);
        }
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2546443 2007-07-31 20:33:28 Accepted 1221 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 02:57:58 | Accepted | 1221 | C | 0 | 160 | watashi | Source

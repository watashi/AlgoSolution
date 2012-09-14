#include <stdio.h>
#define MAX 500
int main()
{
    int i,j,k,n,m,x1,y1,x2,y2,win[MAX][MAX];
    while(scanf("%d",&n),n){
        for(i=0;i<MAX;i++)
            for(j=0;j<MAX;j++)
                win[i][j]=-1;
        for(k=0;k<n;k++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(i=x1;i<=x2;i++)
                for(j=y1;j<=y2;j++)
                    win[i][j]=k;
        }
        scanf("%d",&m);
        while(m--){
            scanf("%d%d",&i,&j);
            printf("%d\n",win[i][j]);
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2502175 2007-06-24 22:01:45 Accepted 2480 C 00:00.00 1364K ¤ï¤¿¤· */

// 2012-09-07 03:10:40 | Accepted | 2480 | C | 0 | 160 | watashi | Source

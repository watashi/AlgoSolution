#include <stdio.h>
int main()
{
    struct{
        int r,g,b,gray;
    }pic[100][100];
    int i,j,x,y,ri=0;

    while(scanf("%d%d",&x,&y),x){
        printf("Case %d:\n",++ri);
        for(i=0;i<x;i++)
            for(j=0;j<y;j++)
                scanf("%d",&pic[i][j].r);
        for(i=0;i<x;i++)
            for(j=0;j<y;j++)
                scanf("%d",&pic[i][j].g);
        for(i=0;i<x;i++)
            for(j=0;j<y;j++){
                scanf("%d",&pic[i][j].b);
                pic[i][j].gray=(pic[i][j].r+pic[i][j].g+pic[i][j].b)/3;
            }
        for(i=0;i<x;i++)
            for(j=0;j<y;j++){
                printf("%d",pic[i][j].gray);
                if(j==y-1) printf("\n");
                else printf(",");
            }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2488083 2007-06-10 22:44:38 Accepted 2857 C 00:00.02 544K ¤ï¤¿¤· */

// 2012-09-07 03:14:20 | Accepted | 2857 | C | 0 | 160 | watashi | Source

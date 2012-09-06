#include <stdio.h>
int main()
{
    int m,n,i,j,cc1,cc2;
    int a[11][11]={{1,1,1,1,1,1,1,1,1,1,1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1}};

    while(scanf("%d%d",&m,&n),m){
        cc1=cc2=0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
                if(a[i][j]==0){
                    cc1=1;
                    if(a[i-1][j]==0||a[i][j-1]==0)
                        cc2=1;
                }
            }
        if(cc1==1&&cc2==0) printf("Yes\n");
        else printf("No\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2494873 2007-06-17 14:22:58 Accepted 2850 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:13:55 | Accepted | 2850 | C | 0 | 160 | watashi | Source

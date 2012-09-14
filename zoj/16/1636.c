#include <stdio.h>
int main()
{
    static int a[501][501];
    int ri,i,j,t,m,n,p,r1,r2,c1,c2;

    scanf("%d",&t);
    for(ri=1;ri<=t;ri++){
        scanf("%d%d",&m,&n);
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++){
                scanf("%d",&p);
                a[i][j]=p*p;
                a[i][j]+=a[i][j-1];
            }
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                a[i][j]+=a[i-1][j];
        scanf("%d",&p);
        printf("Case %d:\n",ri);
        while(p--){
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            r1--;
            c1--;
            printf("%d\n",a[r2][c2]+a[r1][c1]-a[r1][c2]-a[r2][c1]);
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2548608 2007-08-01 23:51:34 Accepted 1636 C 00:00.45 1372K ¤ï¤¿¤· */

// 2012-09-07 03:03:28 | Accepted | 1636 | C | 140 | 1140 | watashi | Source

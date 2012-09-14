#include <stdio.h>
#include <string.h>
#define L(i) ((i<<1)-1)
#define R(i) ((i<<1))
int mp[130][130];
int a[130],b[130];
int main()
{
    int i,j,k,m,n;
    int blank=0;

    while(scanf("%d",&n)!=EOF && n){
        if(blank) printf("\n");
        else blank=1;
        m=1<<n;
        for(i=1;i<=m;i++)
            a[i]=i;
        memset(mp,0,sizeof(mp));
        while(m>>=1){
            for(i=1;i<=m;i++){
                scanf("%d",&k);
                if(k==a[L(i)]) mp[a[L(i)]][a[R(i)]]=1;
                else if(k==a[R(i)]) mp[a[R(i)]][a[L(i)]]=1;
                a[i]=k;
            }
        }
        m=1<<n;
        for(k=1;k<=m;k++)
            for(i=1;i<=m;i++)
                for(j=1;j<=m;j++)
                    if(mp[i][k]&&mp[k][j]) mp[i][j]=1;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=1;i<=m;i++)
            for(j=1;j<=m;j++)
                if(mp[i][j]){
                    a[i]++;
                    b[j]++;
                }
        scanf("%d",&n);
        while(n--){
            scanf("%d",&k);
            printf("Player %d can be ranked as high as %d or as low as %d.\n",k,b[k]+1,m-a[k]);
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2660911 2007-10-28 11:09:14 Accepted 1501 C 00:00.01 464K ¤ï¤¿¤· */

// 2012-09-07 03:02:02 | Accepted | 1501 | C | 0 | 224 | watashi | Source

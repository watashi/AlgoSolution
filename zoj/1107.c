#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IN(x,y) ((x)>=0&&(y)>=0&&(x)<n&&(y)<n)
struct pos{
    char x;
    char y;
};
int maxd[100][100];
int mp[100][100];
struct pos q[10000];
int cmp(const void *ppa,const void *ppb)
{
    struct pos *pa=(struct pos *)ppa,*pb=(struct pos *)ppb;
    int a=mp[pa->x][pa->y],b=mp[pb->x][pb->y];

    if(a<b) return -1;
    else if(a>b) return 1;
    else return 0;
}
int ans;
int main()
{
    int i,j,k,n,m,p,nn;

    while(scanf("%d%d",&n,&m)!=EOF && n>=0 && m>=0){
        p=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                scanf("%d",&mp[i][j]);
                maxd[i][j]=-1;
                q[p].x=i;q[p].y=j;p++;
            }
        nn=p;
        qsort(q,nn,sizeof(struct pos),cmp);
        ans=maxd[0][0]=0;
        for(p=0;p<nn;p++){
            i=q[p].x;j=q[p].y;
            if(mp[i][j]<mp[0][0]) continue;
            for(k=1;k<=m;k++){
                if(IN(i-k,j)&&mp[i-k][j]<mp[i][j]&&maxd[i-k][j]>maxd[i][j]) maxd[i][j]=maxd[i-k][j];
                if(IN(i,j-k)&&mp[i][j-k]<mp[i][j]&&maxd[i][j-k]>maxd[i][j]) maxd[i][j]=maxd[i][j-k];
                if(IN(i+k,j)&&mp[i+k][j]<mp[i][j]&&maxd[i+k][j]>maxd[i][j]) maxd[i][j]=maxd[i+k][j];
                if(IN(i,j+k)&&mp[i][j+k]<mp[i][j]&&maxd[i][j+k]>maxd[i][j]) maxd[i][j]=maxd[i][j+k];
            }
            if(maxd[i][j]!=-1) maxd[i][j]+=mp[i][j];
            if(maxd[i][j]>ans) ans=maxd[i][j];
        }
        printf("%d\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2685975 2007-11-26 14:56:11 Accepted 1107 C 00:00.15 516K ¤ï¤¿¤· */

// 2012-09-07 02:55:57 | Accepted | 1107 | C | 80 | 260 | watashi | Source

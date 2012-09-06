#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct record{
    int p,id;
}a[10010];
int comp(const void *pa,const void *pb)
{
    const struct record *a=(struct record *)pa,*b=(struct record *)pb;

    if(a->p==b->p) return (a->id<b->id)?-1:1;
    else return (a->p>b->p)?-1:1;
}
int main()
{
    int i,j,n,m,t;

    while(scanf("%d%d",&n,&m)!=EOF && m||n){
        for(i=1;i<=10000;i++){
            a[i].id=i;
            a[i].p=0;
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                scanf("%d",&t);
                a[t].p++;
            }
        qsort(a+1,10000,sizeof(struct record),comp);
        for(i=2;i<=10000;i++){
            if(a[i].p==a[2].p){
                printf("%d ",a[i].id);
            }
            else break;
        }
        printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2654649 2007-10-22 21:33:34 Accepted 2250 C 00:00.38 556K ¤ï¤¿¤· */

// 2012-09-07 01:17:08 | Accepted | 2250 | C | 100 | 236 | watashi | Source

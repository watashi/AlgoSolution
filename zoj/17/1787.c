#include <stdio.h>
#include <stdlib.h>
struct Block{
    int l,m;
}a[10001];
int length,len[10001];
int comp(const void *pa,const void *pb)
{
    struct Block a=*(struct Block *)pa,b=*(struct Block *)pb;

    if(a.l==b.l) return (a.m==b.m)?0:((a.m<b.m)?-1:1);
    else return (a.l<b.l)?-1:1;
}
int main()
{
    int i,n,l,r,m;

    while(scanf("%d",&n)!=EOF && n){
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i].l,&a[i].m);
        qsort(a,n,sizeof(struct Block),comp);
        length=0;
        len[length]=a[0].m;
        for(i=1;i<n;i++){
            if(a[i].m>=len[length]) len[++length]=a[i].m;
            else if(a[i].m<len[0]) len[0]=a[i].m;
            else{
                l=0;r=length;
                while(l<r){
                    m=(l+r)/2;
                    if(a[i].m>=len[m]) l=m+1;
                    else r=m;
                }
                len[l]=a[i].m;
            }
        }
        printf("%d\n",length+1);
    }
    printf("*\n");

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2651753 2007-10-20 15:04:47 Accepted 1787 C 00:00.02 540K ¤ï¤¿¤· */

// 2012-09-07 03:05:08 | Accepted | 1787 | C | 0 | 280 | watashi | Source

/* //long long~~!!!!!!!!!!so xe~~ */
#include <stdio.h>
#include <stdlib.h>
long long a[100000];
int cmp(const void *pa,const void *pb)
{
    long long a=*(long long *)pa,b=*(long long *)pb;

    if(a<b) return -1;
    else if(a>b) return 1;
    else return 0;
}
int main()
{
    int i,n;
    long long x,y,ans;

    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        qsort(a,n,sizeof(long long),cmp);
        ans=0;
        while(n>=4){
            x=a[0]+a[0]+a[n-2]+a[n-1];
            y=a[0]+a[1]+a[1]+a[n-1];
            if(y<x) ans+=y;
            else ans+=x;
            n-=2;
        }
        if(n==1) ans+=a[0];
        else if(n==2) ans+=a[1];
        else if(n==3) ans+=a[0]+a[1]+a[2];
        printf("%lld\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2684807 2007-11-25 01:20:00 Accepted 1579 C 00:00.52 1292K ¤ï¤¿¤· */

// 2012-09-07 03:02:45 | Accepted | 1579 | C | 110 | 1180 | watashi | Source

#include <stdio.h>
#include <string.h>
int a[10001];
int i,j,n,m,ans;
int main()
{
    int re;

    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&n,&m);
        memset(a+1,0,n*sizeof(int));
        while(m--){
            scanf("%d%d",&i,&j);
            a[i]++;
            a[j]++;
        }
        ans=0;
        for(i=1;i<=n;i++)
            ans+=a[i]*a[i];
        printf("%d\n",ans);
        if(re) printf("\n");
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2647093 2007-10-16 21:01:15 Accepted 2316 C 00:01.25 432K わたし */
/* //2647092 2007-10-16 21:01:09 Accepted 2316 C++ 00:01.26 436K わたし */

// 2012-09-07 14:44:18 | Accepted | 2316 | C | 460 | 196 | watashi | Source

#include <stdio.h>
int main()
{
    int i,n,a,ans;

    while(scanf("%d",&n),n){
        ans=0;
        for(i=0;i<n;i++){
            scanf("%d",&a);
            if(a+ans<n-i) ans=n-i-a;
        }
        printf("%d\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2596228 2007-09-04 19:20:12 Accepted 1495 C 00:00.00 392K わたし */
/* //2596227 2007-09-04 19:19:52 Accepted 1495 C 00:00.01 392K わたし */

// 2012-09-07 03:01:50 | Accepted | 1495 | C | 0 | 160 | watashi | Source

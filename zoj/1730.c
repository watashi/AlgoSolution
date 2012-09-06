#include <stdio.h>
int main()
{
    int re;
    int n,a,b,ans;

    scanf("%d",&re);
    while(re--){
        scanf("%d",&n);
        a=n/2;
        b=n-a;
        ans=a*(a-1)/2+b*(b-1)/2;
        printf("%d\n",ans);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2651363 2007-10-20 09:45:50 Accepted 1730 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 00:59:06 | Accepted | 1730 | C | 0 | 160 | watashi | Source

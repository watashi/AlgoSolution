#include <stdio.h>
int main()
{
    int n,p,t;
    int ans;

    while(scanf("%d",&n)!=EOF){
        ans=0;
        scanf("%d",&p);
        while(n--){
            scanf("%d",&t);
            switch(p){
            case 1:if(t>0) ans+=t;break;
            case 2:ans+=t*t;break;
            case 3:if(t>0) ans+=t*t*t;break;
            }
        }
        printf("%d\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2684187 2007-11-24 13:31:48 Accepted 2460 C 00:00.02 392K ¤ï¤¿¤· */

// 2012-09-07 03:10:28 | Accepted | 2460 | C | 0 | 160 | watashi | Source

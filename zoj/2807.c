#include <stdio.h>
int main()
{
    int ri,n,i,k,o,sum;

    scanf("%d",&n);
    for(ri=1;ri<=n;ri++){
        sum=1;
        scanf("%d",&k);
        for(i=0;i<k;i++){
            scanf("%d",&o);
            sum+=o;
        }
        printf("%d\n",sum-k);
    }

    return 0;   /* NZEC */
}

/* //2476540 2007-06-02 16:44:48 Accepted 2807 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:13:06 | Accepted | 2807 | C | 0 | 160 | watashi | Source

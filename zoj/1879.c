#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n,a[3003],x[3003];

    while(scanf("%d",&n)!=EOF){
        for(i=1;i<n;i++)
            x[i]=1;
        scanf("%d",&a[0]);
        for(i=1;i<n;i++){
            scanf("%d",&a[i]);
            x[abs(a[i]-a[i-1])]=0;
        }
        for(i=1;i<n;i++)
            if(x[i]) break;
        if(i<n) printf("Not jolly\n");
        else printf("Jolly\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2489508 2007-06-12 17:23:40 Accepted 1879 C 00:00.02 416K ¤ï¤¿¤· */

// 2012-09-07 03:06:24 | Accepted | 1879 | C | 0 | 160 | watashi | Source

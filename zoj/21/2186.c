#include <stdio.h>
int main()
{
    int i,h[3];
    const int n=3,H=168;

    while(scanf("%d%d%d",&h[0],&h[1],&h[2])!=EOF){
        for(i=0;i<n;i++)
            if(h[i]<=H){
                printf("CRASH %d\n",h[i]);
                break;
            }
        if(i>=n) printf("NO CRASH\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2500279 2007-06-22 18:36:42 Accepted 2186 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:09:15 | Accepted | 2186 | C | 0 | 160 | watashi | Source

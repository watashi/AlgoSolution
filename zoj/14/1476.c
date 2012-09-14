#include <stdio.h>
int main()
{
    int i,n,d,s[61];

    while(scanf("%d %d",&s[0],&d),s[0]&&d){
        for(i=1;i<=60;i++){
            s[i]=(s[i-1]*(d+1))%60;
            if(s[i]==0) break;
        }
        if(i>=60) printf("Impossible\n");
        else printf("%d\n",i);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2490599 2007-06-13 16:22:33 Accepted 1476 C 00:00.20 396K ¤ï¤¿¤· */

// 2012-09-07 03:01:19 | Accepted | 1476 | C | 80 | 160 | watashi | Source

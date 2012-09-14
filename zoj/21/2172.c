#include <stdio.h>
int main()
{
    char name[26][26];
    int i,n,ri=0;

    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            scanf("%s",name[i]);
        printf("SET %d\n",++ri);
        for(i=0;i<n;i+=2)
            puts(name[i]);
        if(n%2==0)
            for(i=n-1;i>0;i-=2) puts(name[i]);
        else
            for(i=n-2;i>0;i-=2) puts(name[i]);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2488106 2007-06-10 23:24:25 Accepted 2172 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:09:02 | Accepted | 2172 | C | 0 | 160 | watashi | Source

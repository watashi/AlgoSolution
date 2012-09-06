#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t,a,b,d,dd,bl=0;

    while(scanf("%d",&t),t!=5280){
        if(bl) printf("\n");
        else bl=1;
        a=0;
        d=abs(t);
        while(scanf("%d",&b)){
            printf("Moving from %d to %d: ",a,b);
            if(b==t){
                printf("found it!\n");
                break;
            }
            dd=abs(b-t);
            if(d==dd) printf("same.\n");
            else if(d<dd) printf("colder.\n");
            else if(d>dd) printf("warmer.\n");
            d=dd;
            a=b;
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2492813 2007-06-15 18:09:56 Accepted 1745 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 03:04:31 | Accepted | 1745 | C | 0 | 160 | watashi | Source

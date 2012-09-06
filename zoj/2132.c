/* //看了<C语言名题精选百则:技巧篇->voting>才会的; */
#include <stdio.h>
int main()
{
    long l,t,x,c;

    while(scanf("%ld",&l)!=EOF){
        scanf("%d",&x);
        c=1;
        while(--l){
            scanf("%d",&t);
            if(t==x) c++;
            else if(c) c--;
            else {x=t;c=1;}
        }
        printf("%ld\n",x);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2534754 2007-07-25 09:23:38 Accepted 2132 C 00:01.40 392K わたし */

// 2012-09-07 03:08:38 | Accepted | 2132 | C | 380 | 160 | watashi | Source

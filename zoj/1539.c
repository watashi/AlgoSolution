#include <stdio.h>
long choose(long x)
{
    if(x<3) return 0;
    else if(x==3) return 1;
    else return choose(x/2)+choose(x-x/2);
}
int main()
{
    long x;
    long n;

    while(scanf("%ld",&x)!=EOF){
        n=choose(x);
        printf("%ld\n",n);
    }

    return 0;   /* NZEC */
}

/* //2495865 2007-06-18 10:42:55 Accepted 1539 C 00:00.26 396K ¤ï¤¿¤· */

// 2012-09-07 03:02:14 | Accepted | 1539 | C | 70 | 160 | watashi | Source

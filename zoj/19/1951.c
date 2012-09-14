#include <stdio.h>
#include <math.h>
int prime(long x)/*no 2k*/
{
    int i;
    double y;

    y=sqrt(x);
    for(i=3;i<=y;i+=2)
        if(x%i==0) break;
    if(i>y) return 1;
    else return 0;
}
int main()
{
    long i,x;

    while(scanf("%ld",&x),x){
        for(i=3;;i+=2)
            if(prime(i)&&prime(x-i)) break;
        printf("%d = %d + %d\n",x,i,x-i);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2462846 2007-05-25 20:50:53 Accepted 1951 C 00:00.39 404K ¤ï¤¿¤· */

// 2012-09-07 01:08:12 | Accepted | 1951 | C | 180 | 160 | watashi | Source

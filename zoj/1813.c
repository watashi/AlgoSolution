#include <stdio.h>
int main()
{
    long n,ri=0;
    double d,t,s,v;
    const double PI=3.1415927,inch_mile=12*5280,second_hour=3600;

    while(scanf("%lf%ld%lf",&d,&n,&t),n){
        s=PI*d*n/inch_mile;
        v=s/t*second_hour;
        printf("Trip #%d: %.2lf %.2lf\n",++ri,s,v);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2489481 2007-06-12 17:03:59 Accepted 1813 C 00:00.01 388K ¤ï¤¿¤· */

// 2012-09-07 01:01:45 | Accepted | 1813 | C | 0 | 160 | watashi | Source

#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,c,f0,f1,f2,f3,f4,f5;

    while(scanf("%lf%lf%lf",&f0,&f1,&f2)!=EOF){
        a=(f2-2*f1+f0)/2;
        b=(4*f1-f2-3*f0)/2;
        c=f0;
        f3=9*a+3*b+c;
        f4=16*a+4*b+c;
        f5=25*a+5*b+c;
        printf("%.0lf %.0lf %.0lf\n",f3,f4,f5);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2501715 2007-06-24 11:59:17 Accepted 2191 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:09:27 | Accepted | 2191 | C | 0 | 160 | watashi | Source

/*V=pi*R^2*2R-2*1/3*pi*R^2*R-2*2/3*pi*r^2*r*/
#include <stdio.h>
#include <math.h>
#define PI 3.14159265/*35897932384626433832795!!!*/
int main()
{
    double D,V;

    while(scanf("%lf%lf",&D,&V),D){
        printf("%.3lf\n",pow(D*D*D-V*6/PI,1.0/3));
    }
}
/*EASY*/
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2470036 2007-05-29 16:45:07 Accepted 1904 C 00:00.00 396K ¤ï¤¿¤·

// 2012-09-07 01:05:24 | Accepted | 1904 | C++ | 0 | 180 | watashi | Source

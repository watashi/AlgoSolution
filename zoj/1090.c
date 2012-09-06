/*(x1-x2)(x-x12)+(y1-y2)(y-y12)=0*/
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793
int main()
{
    double x0,y0,x1,y1,x2,y2,x3,y3,a1,b1,c1,a2,b2,c2,d,d1,d2,r;

    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF){
        a1=x1-x2;
        b1=y1-y2;
        c1=(x1+x2)*(x1-x2)/2.0+(y1+y2)*(y1-y2)/2.0;
        a2=x2-x3;
        b2=y2-y3;
        c2=(x2+x3)*(x2-x3)/2.0+(y2+y3)*(y2-y3)/2.0;
        d=a1*b2-a2*b1;
        d1=c1*b2-c2*b1;
        d2=a1*c2-a2*c1;
        x0=d1/d;
        y0=d2/d;
        r=sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
        printf("%.2lf\n",2*PI*r);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2484550 2007-06-08 00:39:40 Accepted 1090 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 02:55:43 | Accepted | 1090 | C | 0 | 160 | watashi | Source

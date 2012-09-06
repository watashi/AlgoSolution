/*S::area=sqrt(s*(s-a)*(s-b)*(s-c));*/
/*inscribed circle r::r*(a+b+c)/2=S*/
/*circum circle R::*/
#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    double x[4],y[4],z[4],r,a,b,c,s,S;
    double angle[4],R;

    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x[1],&y[1],&z[1],&x[2],&y[2],&z[2],&x[3],&y[3],&z[3])!=EOF){
        a=sqrt((x[2]-x[1])*(x[2]-x[1])+(y[2]-y[1])*(y[2]-y[1])+(z[2]-z[1])*(z[2]-z[1]));
        b=sqrt((x[3]-x[1])*(x[3]-x[1])+(y[3]-y[1])*(y[3]-y[1])+(z[3]-z[1])*(z[3]-z[1]));
        c=sqrt((x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2])+(z[3]-z[2])*(z[3]-z[2]));
        s=(a+b+c)/2;
        S=sqrt(s*(s-a)*(s-b)*(s-c))/2;
        r=2*S/s;/*get r*/
        /*another wey to get R,beside ..*/
        angle[1]=acos((b*b+c*c-a*a)/(2*b*c));
        angle[2]=acos((a*a+c*c-b*b)/(2*a*c));
        angle[3]=acos((a*a+b*b-c*c)/(2*a*b));
        angle[0]=(angle[2]+angle[3]-angle[1])/2;
        R=(a/2)/cos(angle[0]);
        /*get R*/
        printf("%.3lf\n",r*r/R/R);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2486517 2007-06-09 15:08:46 Accepted 1439 C 00:00.11 404K ¤ï¤¿¤· */

// 2012-09-07 03:01:13 | Accepted | 1439 | C | 30 | 160 | watashi | Source

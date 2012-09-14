#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,c;
    int ri;

    ri=0;
    while(scanf("%lf%lf%lf",&a,&b,&c),c){
        ri++;
        if(c==-1) printf("Triangle #%d\nc = %.3lf\n",ri,sqrt(a*a+b*b));
        else{
            if(a>=c||b>=c) printf("Triangle #%d\nImpossible.\n",ri);
            else if(b==-1) printf("Triangle #%d\nb = %.3lf\n",ri,sqrt(c*c-a*a));
            else printf("Triangle #%d\na = %.3lf\n",ri,sqrt(c*c-b*b));
        }
        printf("\n");
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469465 2007-05-29 12:12:56 Accepted 1241 C 00:00.01 400K ¤ï¤¿¤· */

// 2012-09-07 02:58:05 | Accepted | 1241 | C | 0 | 160 | watashi | Source

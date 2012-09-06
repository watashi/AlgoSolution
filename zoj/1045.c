#include <stdio.h>
int main()
{
    int i;
    double x,sum;

    while(scanf("%lf",&x),0.01<=x&&x<=5.20){
        sum=0;
        i=0;
        while(sum<x){
            sum+=1.0/(i+2);
            i++;
        }
        printf("%d card(s)\n",i);
    }

    return 0;   /* NZEC */
}


/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2464492 2007-05-26 22:53:08 Accepted 1045 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 02:54:54 | Accepted | 1045 | C | 0 | 160 | watashi | Source

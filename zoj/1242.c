#include <stdio.h>
#include <math.h>
int main()
{
    int ri=0;
    double w,d;
    int x;

    while(ri++,scanf("%lf%lf",&w,&d),w||d){
        x=(int)(5730*log(d/w/810)/log(0.5));
        if(x<10000) printf("Sample #%d\nThe approximate age is %d years.\n\n",ri,(x+50)/100*100);
        else printf("Sample #%d\nThe approximate age is %d years.\n\n",ri,(x+500)/1000*1000);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2477696 2007-06-03 03:55:17 Accepted 1242 C 00:00.00 396K ¤ï¤¿¤· */

// 2012-09-07 02:58:11 | Accepted | 1242 | C | 0 | 160 | watashi | Source

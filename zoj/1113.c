#include <stdio.h>
int main()
{
    int i;
    double x=1,e=0;

    printf("n e\n- -----------\n");
    for(i=0;i<=9;i++){
            if(i) x=x*i;
            e+=1.0/x;
            if(i==0||i==1) printf("%d %.0lf\n",i,e);
            else if(i==2) printf("%d %.1lf\n",i,e);
            else printf("%d %.9lf\n",i,e);
    }

    return 0;   /* NZEC */
}


/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2464500 2007-05-26 22:59:04 Accepted 1113 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 02:56:21 | Accepted | 1113 | C | 0 | 156 | watashi | Source

#include <stdio.h>
#define PI 3.14159
int main()
{
    double x[40],y[40],z[40];
    int n,i;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf%lf",&x[i],&y[i]);
        z[i]=(x[i]*x[i]+y[i]*y[i])*PI/100.0+1.0;
        printf("Property %d: This property will begin eroding in year %d.\n",i+1,(int)z[i]);
    }
    printf("END OF OUTPUT.\n");

    return 0;   /* NZEC */
}


/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2464495 2007-05-26 22:54:54 Accepted 1049 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 02:55:06 | Accepted | 1049 | C | 0 | 160 | watashi | Source

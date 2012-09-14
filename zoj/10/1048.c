#include <stdio.h>
int main()
{
    int i;
    float average,sum=0,a[12];

    for(i=0;i<12;i++){
        scanf("%f",&a[i]);
        sum+=a[i];
    }
    average=sum/12;
    printf("$%.2f\n",average);

    return 0;   /* NZEC */
}


/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2464493 2007-05-26 22:54:13 Accepted 1048 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 02:55:00 | Accepted | 1048 | C | 0 | 160 | watashi | Source

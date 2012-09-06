/* //up SUMn~1(-1) down SUM(n-1)~1||SUM2(-2) */
#include <stdio.h>
int main()
{
    long x[505];
    int i,j,n;

    x[0]=0;
    x[1]=1;
    x[2]=5;
    x[3]=13;
    for(i=4;i<502;i++)
        x[i]=x[i-2]+(3*i*i-i)/2;/*SUM(i)+SUM(i-1)+SUM(i-1)*/
    while(scanf("%d",&n)!=EOF){
        printf("%ld\n",x[n]);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2485974 2007-06-09 03:44:22 Accepted 1629 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:03:15 | Accepted | 1629 | C | 0 | 160 | watashi | Source

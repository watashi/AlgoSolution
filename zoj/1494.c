#include <stdio.h>
int main()
{
    int n,u,d,t;

    while(scanf("%d %d %d",&n,&u,&d),n){
        t=0;
        n=n-d;
        do{
            n+=d;
            n-=u;
            t++;
        }while(n>0);
        printf("%d\n",2*t-1);
    }
}
/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2443502 2007-05-18 17:03:29 Accepted 1494 C 00:00.00 388K ¤ï¤¿¤· */

// 2012-09-07 00:50:45 | Accepted | 1494 | C | 0 | 160 | watashi | Source

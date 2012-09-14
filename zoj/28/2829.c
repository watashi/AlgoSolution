#include <stdio.h>
int main()
{
    long n,m,i,a[8]={0,3,5,6,9,10,12};

    while(scanf("%ld",&n)!=EOF){
        m=n/7;
        i=n%7;
        printf("%ld\n",15*m+a[i]);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2476504 2007-06-02 16:14:52 Accepted 2829 C 00:00.01 392K ¤ï¤¿¤· */

// 2012-09-07 03:13:25 | Accepted | 2829 | C | 0 | 160 | watashi | Source

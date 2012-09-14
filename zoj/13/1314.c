/*ª•÷ */
#include <stdio.h>
int main()
{
    long step,mod,m,n,t;

    while(scanf("%ld%ld",&step,&mod)!=EOF){
        m=(step>mod)?step:mod;
        n=(step<mod)?step:mod;
        while(m%n){
            t=n;
            n=m%n;
            m=t;
        }
        if(n==1) printf("%10d%10d    Good Choice\n\n",step,mod);
        else printf("%10d%10d    Bad Choice\n\n",step,mod);
    }

    return 0;   /* NZEC */
}

/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2469476 2007-05-29 12:17:06 Accepted 1314 C 00:00.01 392K §Ô§ø§∑ */

// 2012-09-07 02:59:18 | Accepted | 1314 | C | 0 | 160 | watashi | Source

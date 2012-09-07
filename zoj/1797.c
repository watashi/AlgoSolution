/* //GCD =Greatest Common Divisor最大公约数 */
/* //LCM abbr. Lowest Common Multiple, [数]最小公倍数 */

#include <stdio.h>

/* error: ‘Lcm’ was not declared in this scope */
long Lcm(long m, long n);

int main()
{
    int ri,repeat,i,k;
    long m,n,lcm;
    long gcd(long m,long n);

    scanf("%d",&repeat);
    for(ri=1;ri<=repeat;ri++){
        scanf("%d",&k);
        scanf("%ld",&m);
        lcm=m;
        for(i=2;i<=k;i++){
            scanf("%ld",&n);
            m=Lcm(m,n);
        }
        printf("%ld\n",m);
    }

    return 0;   /* NZEC */
}

long Lcm(long m,long n)
{
    long rem;
    long x=m,y=n;

    if(m<n){
        rem=m;
        m=n;
        n=rem;
    }
    while(n){
        rem=m%n;
        m=n;
        n=rem;
    }
    return x/m*y;
}

/* //x/m*y is better than x*y/m */
/*DONE*/
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2470031 2007-05-29 16:43:50 Accepted 1797 C 00:00.00 388K わたし */

// 2012-09-07 14:36:54 | Accepted | 1797 | C | 0 | 160 | watashi | Source

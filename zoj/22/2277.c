#include  <stdio.h>
double calc(double a,long n)
{
    double x;

    if(n==0) return 1;
    if(n&1){
        x=calc(a,n-1);
        x*=a;
        while(x>10) x/=10;
        return x;
    }
    else{
        x=calc(a,n/2);
        x=x*x;
        while(x>10) x/=10;
        return x;
    }
}
int main()
{
    long n;
    double a;

    while(scanf("%ld",&n)!=EOF){
        a=n;
        while(a>10) a/=10;
        a=calc(a,n);
        printf("%d\n",(int)a);
    }

    return 0;   /* NZEC */
}

/* //2546410 2007-07-31 20:18:37 Accepted 2277 C 00:00.29 2984K ¤ï¤¿¤· */

// 2012-09-07 03:09:45 | Accepted | 2277 | C | 130 | 160 | watashi | Source

/*
#include <stdio.h>
int isprime(n)
{
    int i,t;

    t=n/2;
    if(n==2) return 1;
    else if(n%2==0) return 0;
    for(i=3;i<=t;i+=2)
        if(n%i==0) break;
    if(i>t) return 1;
    else return 0;
}
int main()
{
    int i,t,x,count;

    while(scanf("%d",&x),x){
        count=0;
        t=x/2;
        for(i=2;i<=t;i++)
            if(isprime(i)&&isprime(x-i)) count++;
        printf("%d\n",count);
    }
}
*/
/* //tle */
#include <stdio.h>
int prime[3600]={2};
int oddisprime(int n)
{
    int i,t;

    t=n/2;
    for(i=3;i<=t;i+=2)
        if(n%i==0) break;
    if(i>t) return 1;
    else return 0;
}
int makeprime()
{
    int i,j=1;

    for(i=3;i<32768;i+=2)
        if(oddisprime(i)){prime[j++]=i;}
    return j;
}
int searchprime(int n)
{
    int i;

    for(i=0;i<3600;i++){
        if(prime[i]==n) return 1;
        else if(prime[i]>n) return 0;
    }
}
int main()
{
    int i,n,t,x,count;

    n=makeprime();
    while(scanf("%d",&x),x){
        count=0;
        t=x/2;
        for(i=0;i<n;i++){
            if(prime[i]>t) break;
            else if(searchprime(x-prime[i])) count++;
        }
        printf("%d\n",count);
    }

    return 0;   /* NZEC */
}

/* //2497997 2007-06-20 14:32:42 Accepted 1657 C 00:00.68 404K ¤ï¤¿¤· */

// 2012-09-07 03:03:42 | Accepted | 1657 | C | 260 | 172 | watashi | Source

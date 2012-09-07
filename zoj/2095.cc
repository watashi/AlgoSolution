/*s=mul(all ziyinshu(^?)-1)*/
/*
#include <cmath> // auto fix CE
#include <cstdio> // auto fix CE
#include <cmath> // auto fix CE
#include <stdio.h>
#include <cmath> // auto fix CE
#include <cstdio> // auto fix CE
#include <cmath> // auto fix CE
#include <math.h>
int isprime(long x)
{
    int i;
    float u=sqrt(x);

    if(x==1||x==2) return 1;
    else if(x%2==0) return 0;
    for(i=3;i<=u;i+=2)
        if(x%i==0) break;
    if(i>u) return 1;
    else return 0;
}
int main()
{
    struct divisors{
        long x;
        int n;
    }div[12];
    int re,i,j,n;
    long num,x,s,t;
    float u;

    scanf("%d",&re);
    while(re--){
        scanf("%ld",&x);
        num=x;
        u=sqrt(x);
        j=0;
        for(i=2;i<=x;i++){
            if(isprime(i)&&x%i==0){
                div[j].x=i;
                div[j].n=1;
                x/=i;
                while(x%i==0){
                    x/=i;
                    div[j].n++;
                }
                j++;
            }
        }
        s=1;
        n=j;
        for(i=0;i<n;i++){
            t=1;
            for(j=1;j<=div[i].n;j++)
                t+=pow(div[i].x,j);
            s*=t;
        }
        s-=num;
        printf("%ld\n",s);
    }
}
//TLE
*/
#include <cmath> // auto fix CE
#include <cstdio> // auto fix CE
#include <cmath> // auto fix CE
#include <stdio.h>
#include <cmath> // auto fix CE
#include <cstdio> // auto fix CE
#include <cmath> // auto fix CE
#include <math.h>
int nprime,prime[200]={2};
void makeprime()
{
    int i,j,k;

    k=1;
    for(i=3;i<888;i++){
        for(j=0;j<k;j++)
            if(i%prime[j]==0) break;
        if(j>=k) prime[k++]=i;
    }
    nprime=k;
}
int main()
{
    struct divisors{
        long x;
        int n;
    }div[12];
    int i,j,n;
    long re,num,x,s,t;
    float u;

    makeprime();
    scanf("%d",&re);
    while(re--){
        scanf("%ld",&x);
        num=x;
        j=0;
        for(i=0;i<nprime;i++){
            if(x%prime[i]==0){
                div[j].x=prime[i];
                div[j].n=1;
                x/=prime[i];
                while(x%prime[i]==0){
                    x/=prime[i];
                    div[j].n++;
                }
                j++;
            }
            if(x==1) break;
        }
        if(x!=1){
            div[j].x=x;
            div[j].n=1;
            j++;
        }
        s=1;
        n=j;
        for(i=0;i<n;i++){
            t=1;
            for(j=1;j<=div[i].n;j++)
                t+=pow(div[i].x,j);
            s*=t;
        }
        s-=num;
        printf("%ld\n",s);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2492132 2007-06-14 21:07:45 Accepted 2095 C 00:03.04 404K ¤ï¤¿¤·

// 2012-09-07 14:09:56 | Accepted | 2095 | C++ | 1370 | 180 | watashi | Source

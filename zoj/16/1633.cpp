#include <cstdio>
#define MAXN 89
const char A[5]="^__^",B[4]="T.T";
long long len[MAXN];
char doit(int t,long long n)
{
//    printf("%d %lld\n",t,n);
    if(t==0) return A[n-1];
    else if(t==1) return B[n-1];
    if(n<=len[t-1]) return doit(t-1,n);
    else return doit(t-2,n-len[t-1]);
}
int main()
{
    long long i;

    len[0]=4;len[1]=3;
    for(i=2;i<MAXN;i++)
        len[i]=len[i-1]+len[i-2];
//    for(i=0;i<MAXN;i++)
//        printf("%lld %lld\n",i,len[i]);
    while(scanf("%lld",&i)!=EOF)
        printf("%c\n",doit(MAXN,i));
}
//2618052 2007-09-22 13:26:42 Accepted 1633 C++ 00:00.01 448K ¤ï¤¿¤·

// 2012-09-07 00:56:28 | Accepted | 1633 | C++ | 0 | 180 | watashi | Source

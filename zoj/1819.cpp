#include <cstdio>
const int MAXD=10;
const long long MAXL=100000000;
typedef struct{
long long a[MAXD];
}bignum;
bignum add(const bignum &a,const bignum &b)
{
    int i;
    bignum c;

    for(i=0;i<MAXD;i++){
        c.a[i]=a.a[i]+b.a[i];
        if(i&&c.a[i-1]>=MAXL){c.a[i-1]-=MAXL;c.a[i]++;}
    }
    return c;
}
bignum mul(const bignum &a,const long long &b)
{
    int i;
    bignum c;

    for(i=0;i<MAXD;i++){
        c.a[i]=a.a[i]*b;
        if(i&&c.a[i-1]>=MAXL){c.a[i]+=c.a[i-1]/MAXL;c.a[i-1]%=MAXL;}
    }
    return c;
}
void output(const bignum &a)
{
    int i;

    i=MAXD-1;
    while(i&&a.a[i]==0) i--;
    printf("%lld",a.a[i--]);
    while(i>=0) printf("%08lld",a.a[i--]);
    printf("\n");
}
int main()
{
    static bignum a[51][51],ans;
    int i,j;

    a[1][1].a[0]=1;
    for(i=2;i<=50;i++){
        a[i][1]=a[i-1][1];
        for(j=2;j<i;j++)
            a[i][j]=add(a[i-1][j-1],mul(a[i-1][j],j));
        a[i][i]=a[1][1];
    }
    while(scanf("%d",&i),i){
        ans=a[i][1];
        for(j=2;j<=i;j++)
            ans=add(ans,a[i][j]);
        printf("%d ",i);
        output(ans);
    }
}
//2595930 2007-09-04 15:46:07 Accepted 1819 C++ 00:00.01 596K ¤ï¤¿¤·

// 2012-09-07 01:01:51 | Accepted | 1819 | C++ | 0 | 384 | watashi | Source

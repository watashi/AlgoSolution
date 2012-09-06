#include <stdio.h>
#define MAXN 1000000
#define MAXD 100
#define MAXL 6
class bignum{
private:
    int data[MAXD];
public:
    bignum()
    {
        for(int i=0;i<MAXD;i++)
            data[i]=0;
    }
    bignum operator=(const int &that)
    {
        data[0]=that;
        for(int i=1;i<MAXD;i++)
            data[i]=0;
        return *this;
    }
    bignum operator=(const bignum &that)
    {
        for(int i=0;i<MAXD;i++)
            data[i]=that.data[i];
        return *this;
    }
    bignum operator+(const bignum &that)
    {
        bignum res;
        for(int i=0;i<MAXD;i++){
            res.data[i]=data[i]+that.data[i];
            if(i&&res.data[i-1]>MAXN){res.data[i-1]-=MAXN;res.data[i]++;}
        }
        return res;
    }
    bignum operator*(const bignum &that)
    {
        bignum res;
        for(int i=0;i<MAXD;i++){
            for(int j=0;j<=i;j++)
                res.data[i]+=data[j]*that.data[i-j];
            if(i!=MAXD-1){res.data[i+1]+=res.data[i]/MAXN;res.data[i]%=MAXN;}
        }
        return res;
    }
    bignum operator+=(const bignum &that)
    {
        return *this=*this+that;
    }
    void show()
    {
        int i=MAXD-1;
        for(;i;i--) if(data[i]) break;
        printf("%d",data[i]);
        for(--i;i>=0;i--)
            printf("%06d",data[i]);//
    }
};
bignum tri[64];
int main()
{
    int i,flag;
    unsigned long long bin[64]={1};
    unsigned long long n;

    tri[0]=1;
    for(i=1;i<64;i++){
        bin[i]=bin[i-1]+bin[i-1];
        tri[i]=tri[i-1]+tri[i-1]+tri[i-1];
    }
    while(scanf("%lld",&n)!=EOF && n--){
        printf("{");
        flag=0;
        for(i=0;i<64&&n>=bin[i];i++){
            if(n&bin[i]){
                if(flag) printf(", ");
                else {printf(" ");flag=1;}
                tri[i].show();
            }
        }
        printf(" }\n");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2639112 2007-10-10 15:42:00 Accepted 2371 C++ 00:00.01 464K ¤ï¤¿¤·

// 2012-09-07 01:21:32 | Accepted | 2371 | C++ | 0 | 204 | watashi | Source

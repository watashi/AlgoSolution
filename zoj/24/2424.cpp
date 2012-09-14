#include <cstring> // auto fix CE
#include <string>
#include <cstdio>
#define MAXD 15
#define MAXN 10000
#define MAXL 8
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
            printf("%04d",data[i]);//
        printf("\n");
    }
};
int main()
{
    int i,j;
    bignum dp[101];

    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(i=1;i<=100;i++)
        for(j=0;j<i;j++)
            dp[i]+=dp[j]*dp[i-1-j];
    while(scanf("%d",&i),i!=-1){
        dp[i].show();
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2618003 2007-09-22 12:52:56 Accepted 2424 C++ 00:00.01 436K ¤ï¤¿¤·

// 2012-09-07 13:35:51 | Accepted | 2424 | C++ | 0 | 180 | watashi | Source

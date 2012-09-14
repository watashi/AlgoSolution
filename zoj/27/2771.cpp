#include <cstdio>
#define MAXD 5
#define MAXN 100000000
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
            printf("%08d",data[i]);
        printf("\n");
    }
};
int main()
{
    int i,j;
    bignum dp[61][5],ans;

    dp[0][4]=dp[0][0]=1;dp[0][1]=dp[0][2]=dp[0][3]=0;
    for(i=1;i<=60;i++){
        if(i&1){
            dp[i][4]=dp[i][0]=0;
            for(j=1;j<=3;j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                dp[i][4]+=dp[i][j];
            }
        }
        else{
            dp[i][4]=dp[i][3]=0;
            for(j=2;j>=0;j--){
                dp[i][j]=dp[i][j+1]+dp[i-1][j+1];
                dp[i][4]+=dp[i][j];
            }
        }
    }
    while(scanf("%d",&i)!=EOF){
        dp[i][4].show();
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2617686 2007-09-22 02:48:39 Accepted 2771 C++ 00:00.00 436K ¤ï¤¿¤·

// 2012-09-07 01:38:50 | Accepted | 2771 | C++ | 0 | 180 | watashi | Source

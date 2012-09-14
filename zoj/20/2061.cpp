//DP
#include <cstdio>
#define MAXN 10000
#define MAXD 100
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
    bignum operator*(const int &that)
    {
        bignum res;
        for(int i=0;i<MAXD;i++){
            res.data[i]+=data[i]*that;
            if(i!=MAXD-1){res.data[i+1]+=res.data[i]/MAXN;res.data[i]%=MAXN;}
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
        int i;
        for(i=MAXD-1;i;i--) if(data[i]) break;
        printf("%d",data[i]);
        for(--i;i>=0;i--)
            printf("%04d",data[i]);//
        printf("\n");
    }
};
int main()
{
    int i,j,ri=0;
    bignum *dp[101];
    bignum ans;

    dp[0]=new bignum;
    dp[0][0]=1;
    for(i=1;i<=100;i++){
        dp[i]=new bignum[i+1];
        dp[i][0]=dp[i-1][0];
        for(j=1;j<i;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        dp[i][i]=dp[i][i-1];
    }
    while(scanf("%d%d",&i,&j)!=EOF && i||j){
        printf("Test #%d:\n",++ri);
        if(j>i) printf("0\n");
        else{
            ans=dp[i][j];
            while(i>1) ans=ans*i--;
            while(j>1) ans=ans*j--;
            ans.show();
        }
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2652749 2007-10-21 09:43:45 Accepted 2061 C++ 00:00.02 2448K わたし





//math
//as follow~by zr




/*
Old men's question

--------------------------------------------------------------------------------

Time limit: 1 Seconds   Memory limit: 32768K
Total Submit: 19   Accepted Submit: 3

--------------------------------------------------------------------------------
                                Old men`s question
Once,there is an island which is full of old men.They all lead a tragic life,because there is no woman on that island.One day the God have a great mood,he send m young ladies to enjoy a vocation with the n old men on that island.But--what a pity--n>=m... Old men are waiting for the ladies in a line,when a lady arrives she will get in the queue to find the guy she prefer.A Lady will only get the old men on her left to be her partner.And the ladies are clever so that they can always find their partners.It means from every position count to the left end the number of old men will more than or equal to the number of ladies.Now,old men want to know how many queues are possible to exist.Because the number of possible queues is so large,Just tell them the length of the number,don`t let them down!
For example ,when n=3,m=2,there are 5 possible queues:MMMLL  MLMLM  MLMML  MMLML  MMLLM
So the length of the number is 1.

Input

There are multiple test cases. Each line have two numbers n and m (0<=m<=n<=500000).
Process to the end of file.

Output

For each case, print the answer on a line, the length of the number of queues which are possible to exist.

Sample Input

3 2
10 3
10 10

Sample Output

1
3
5
*/
/*
寒，没人写……
种类数为C（n+m,n）-C(n+m,m-1)
前者为n个男人，m个女人所有的排列数，后者为非法解数。
前者不用证了……
后者有如下证明：
为了叙述方便男人为1，女人为－1
解为a1, a2, ^, ak, ^ an+m (ai = -1 or 1)
1）对于任何一个非法解，存在一个子序列a1+a2+^＋ak-1=0, ak=-1.其中k为满足条件的第一个数。把这k个数全部乘取反，就变成n＋1个1，m－1个－1。于是存在一个非法解集到（n＋1，m－1）集合的映射。而且可以证明是单射。
2）对于（n＋1，m－1）集合，必然存在一个子序列a1+a2+^＋ak-1=0, ak=-1(n+1>m-1).其中k为满足条件的第一个数。把这k个数全部乘取反，就变成n个1，m个－1，而且还是非法解。于是存在一个（n＋1，m－1）集合到非法解集的映射。而且也可以证明是单射。
所以二者是一一映射，所以……
*/
/*
int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   double ans;
   int n,m;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
      ans = log10(double(n + 1 - m)/double(n + 1));
      for(int i = 1;i <= m;i++)
         ans += log10(double(i + n)/double(i));
      printf("%d\n",1 + int(ans));
   }
   return 0;
}
*/

// 2012-09-07 01:11:52 | Accepted | 2061 | C++ | 0 | 2152 | watashi | Source

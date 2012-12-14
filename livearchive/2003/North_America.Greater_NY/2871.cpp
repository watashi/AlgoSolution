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

	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805974 	2871 	Rhyme Schemes 	Accepted 	C++ 	0.008 	2011-05-23 16:22:54
/*
id => 1174318
pid => 2871
pname => Rhyme Schemes
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:53:37
*/

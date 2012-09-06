// #include <iostream.h> // CE
#include <iostream>

using namespace std;

long fact(int f,int t)
{
    int i;
    long res=1;

    for(i=f;i<=t;i++)
        res*=i;
    return res;
}
int main()
{
    int i,n,x,sum,a[13];
    long ans;

    while(cin>>n){
        sum=0;
        ans=1;
        for(i=0;i<13;i++)
            a[i]=0;
        for(i=0;i<n;i++){
            cin>>x;
            sum+=x;
            ans*=fact(sum-x+1,sum)/fact(1,x);
            a[x]++;
        }
        for(i=0;i<13;i++){
            ans/=fact(1,a[i]);
        }
        cout<<ans<<endl;
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2477695 2007-06-03 03:35:21 Accepted 1202 C++ 00:00.00 832K ¤ï¤¿¤·

// 2012-09-07 04:26:41 | Accepted | 1202 | C++ | 0 | 188 | watashi | Source

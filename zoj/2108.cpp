// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int i,n,t,a[108],b,s;

    while(cin>>n,n){
        a[0]=0;
        s=0;
        for(i=1;i<=n;i++){
            cin>>a[i];
            b=a[i]-a[i-1];
            if(b>0) s+=6*b;
            else s-=4*b;
        }
        cout<<s+n*5<<"\n";
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2470074 2007-05-29 16:56:29 Accepted 2108 C++ 00:00.00 832K ¤ï¤¿¤·

// 2012-09-07 04:27:18 | Accepted | 2108 | C++ | 0 | 188 | watashi | Source

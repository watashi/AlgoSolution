// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int i,n,s,t[12]={0},d;//istance

    while(cin>>n,n+1){
        d=0;
        for(i=1;i<=n;i++){
            cin>>s>>t[i];
            d+=s*(t[i]-t[i-1]);
        }
        cout<<d<<" miles\n";
    }
}
/*naive*/
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2463871 2007-05-26 15:32:11 Accepted 2176 C++ 00:00.01 832K ¤ï¤¿¤·

// 2012-09-07 04:27:25 | Accepted | 2176 | C++ | 0 | 188 | watashi | Source

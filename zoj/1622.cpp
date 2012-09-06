// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int i,n,x,count;

    while(cin>>n){
        count=0;
        for(i=1;i<=n;i++){
            cin>>x;
            if(i%2==x) count++;
        }
        count=(n<2*count)?(n-count):count;
        cout<<count<<endl;
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2475882 2007-06-02 03:49:50 Accepted 1622 C++ 00:00.00 836K ¤ï¤¿¤·

// 2012-09-07 04:27:00 | Accepted | 1622 | C++ | 0 | 188 | watashi | Source

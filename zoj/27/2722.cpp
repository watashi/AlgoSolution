// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    long n,r;

    while(cin>>n,n){
        r=0;
        while(n!=1){
            n=n/2+n%2;
            r++;
        }
        cout<<r<<endl;
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2477699 2007-06-03 04:30:15 Accepted 2722 C++ 00:00.02 836K ¤ï¤¿¤·

// 2012-09-07 04:27:56 | Accepted | 2722 | C++ | 10 | 188 | watashi | Source

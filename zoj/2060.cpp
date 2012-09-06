/*1,2,0,2,2,1,0,1,,1,2,0*/

// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int n,a[8]={1,2,0,2,2,1,0,1};

    while(cin>>n){
        if(!a[n%8]) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
/*simple*/
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2470068 2007-05-29 16:54:04 Accepted 2060 C++ 00:00.43 840K ¤ï¤¿¤·

// 2012-09-07 04:27:12 | Accepted | 2060 | C++ | 350 | 188 | watashi | Source

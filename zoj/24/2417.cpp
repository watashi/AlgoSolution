// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int i,x,bit[8],res;

    while(cin>>x,x){
        i=0;
        do{
            bit[i++]=x%2;
            x/=2;
        }while(x);
        i=0;
        while(bit[i++]==0);
        x=i-1;
        res=1;
        for(i=0;i<x;i++)
            res*=2;
        cout<<res<<"\n";
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2472885 2007-05-30 23:57:01 Accepted 2417 C++ 00:00.00 836K わたし
/*尚可大大简化*/

// 2012-09-07 04:27:50 | Accepted | 2417 | C++ | 0 | 188 | watashi | Source

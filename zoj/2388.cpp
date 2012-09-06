// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int ri,repeat,sum,diff,a,b;

    cin>>repeat;
    for(ri=1;ri<=repeat;ri++){
        cin>>sum>>diff;
        a=sum+diff;
        b=sum-diff;
        if(b<0||a%2)
            cout<<"impossible"<<endl;
        else cout<<a/2<<" "<<b/2<<endl;
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2478850 2007-06-03 23:17:33 Accepted 2388 C++ 00:00.00 836K ¤ï¤¿¤·

// 2012-09-07 04:27:37 | Accepted | 2388 | C++ | 0 | 188 | watashi | Source

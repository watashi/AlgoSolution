// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int num,x,t,sum;

    while(cin>>num){
        sum=0;
        x=num;
        do{
            t=x%10;
            sum+=t*t*t;
            x/=10;
        }while(x);
        if(sum==num) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2477700 2007-06-03 04:35:14 Accepted 2736 C++ 00:00.02 840K ¤ï¤¿¤·

// 2012-09-07 04:28:03 | Accepted | 2736 | C++ | 10 | 188 | watashi | Source

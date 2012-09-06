// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    long x,num;
    int i,n,base,digit[32],j,ok[16];

    while(cin>>num,num){
        ok[j=0]=0;
        for(base=2;base<=16;base++){
            i=0;
            x=num;
            do{
                digit[i++]=x%base;
                x/=base;
            }while(x);
            n=i;
            for(i=0;i<n/2;i++)
                if(digit[i]!=digit[n-i-1]) break;
            if(i>=n/2){
                ok[j++]=base;
                ok[j]=0;
            }
        }
        if(!ok[0]) cout<<"Number "<<num<<" is not a palindrom"<<endl;
        else{
            cout<<"Number "<<num<<" is palindrom in basis";
            j=0;
            while(ok[j]!=0) cout<<" "<<ok[j++];
            cout<<endl;
        }
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2476972 2007-06-02 21:34:18 Accepted 1078 C++ 00:00.00 832K ¤ï¤¿¤·

// 2012-09-07 04:26:34 | Accepted | 1078 | C++ | 0 | 188 | watashi | Source

// #include <iostream.h> // CE
#include <iostream>

using namespace std;


int main()
{
    int i,n,a[20],b[20],t,sa,sb;

    cin>>n;
    while(1){
        for(i=0;i<n;i++)
            cin>>a[i];
        sa=sb=0;
        for(i=0;i<n;i++){
            cin>>b[i];
            t=a[i]-b[i];
            if(t>1) sa+=a[i];
            else if(t==-1){
                sa+=a[i]+b[i];
                if(a[i]==1) sa+=3;
            }
            else if(t<-1) sb+=b[i];
            else if(t==1){
                sb+=a[i]+b[i];
                if(b[i]==1) sb+=3;
            }
        }
        cout<<"A has "<<sa<<" points. B has "<<sb<<" points."<<endl;
        cin>>n;
        if(!n) break;
        cout<<endl;
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2476940 2007-06-02 21:17:28 Accepted 1057 C++ 00:00.00 832K ¤ï¤¿¤·

// 2012-09-07 04:26:28 | Accepted | 1057 | C++ | 0 | 188 | watashi | Source

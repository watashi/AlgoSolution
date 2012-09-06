// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int m,i,n,x,a[10001],count;

    while(cin>>n>>m,m){
        for(i=1;i<=n;i++)
            a[i]=0;
        count=0;
        for(i=1;i<=m;i++){
            cin>>x;
            a[x]++;
            if(a[x]==2) count++;

        }
        cout<<count<<endl;
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2476167 2007-06-02 11:46:46 Accepted 1514 C++ 00:00.00 872K ¤ï¤¿¤·

// 2012-09-07 04:26:53 | Accepted | 1514 | C++ | 0 | 188 | watashi | Source

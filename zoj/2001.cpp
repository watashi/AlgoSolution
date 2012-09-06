// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int reverse(int x)
{
    int t,res;

    res=0;
    do{
        t=x%10;
        res=10*res+t;
        x=x/10;
    }while(x);
    return res;
}
int main()
{
    int i,ri,m,n;

    cin>>ri;
    for(i=1;i<=ri;i++){
        cin>>m>>n;
        cout<<reverse(reverse(m)+reverse(n))<<endl;
    }
}
/*simple*/
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2470064 2007-05-29 16:52:43 Accepted 2001 C++ 00:00.33 836K ¤ï¤¿¤·

// 2012-09-07 04:27:06 | Accepted | 2001 | C++ | 120 | 188 | watashi | Source

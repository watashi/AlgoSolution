////!!!!the cycle might not begin with the seed! !!!!////


// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int ri,Z,I,M,L,i,j,n,num[10000];

    ri=0;
    while(ri++,cin>>Z>>I>>M>>L,M){
        num[i=0]=L;
        n=0;
        while(!n){
            num[i+1]=(Z*num[i++]+I)%M;
            for(j=0;j<i;j++)
                if(num[j]==num[i]){
                    n=i-j;
                    break;
                }
        }
        cout<<"Case "<<ri<<": "<<n<<endl;
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2477697 2007-06-03 04:14:23 Accepted 1278 C++ 00:00.10 876K ¤ï¤¿¤·

// 2012-09-07 04:26:47 | Accepted | 1278 | C++ | 40 | 188 | watashi | Source

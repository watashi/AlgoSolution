// #include <iostream.h> // CE
#include <iostream>

using namespace std;

int main()
{
    int i,sum10,sum16,sum12;

    for(i=1000;i<10000;i++){
        sum10=i/1000+(i/100)%10+(i/10)%10+i%10;
        sum12=i/1728+(i/144)%12+(i/12)%12+i%12;
        if(sum10!=sum12) continue;
        sum16=i/4096+(i/256)%16+(i/16)%16+i%16;
        if(sum10==sum16) cout<<i<<"\n";
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2472893 2007-05-31 00:12:39 Accepted 2405 C++ 00:00.00 828K ¤ï¤¿¤·

// 2012-09-07 04:27:44 | Accepted | 2405 | C++ | 0 | 184 | watashi | Source

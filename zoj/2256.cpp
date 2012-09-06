/*
#include <iostream.h>

int main()
{
    int len,n,r;
    double price;

    while(cin>>len,len){
        if(len<8){
            if(len<=4) price=10;
            else price=2.0*len+2;
        }
        else{
            n=len/8-1;
            r=len%8+8;
            price=n*18;
            //          t1=2.4*r-1.2;           if(r<12) t2=28;         else t2=2*r+4;          price+=(t1>t2)?t1:t2;
            if(r<13) price+=2.4*r-1.2;
            else price+=2.0*r+2;
        }
        //      if(price>(double)((int)price)) printf("%.1f\n",price); //leave one digit after decimal point if NECESSARY.
        //      else printf("%.0f\n",price);
        if(price> (double)(int)price)
            cout<<setprecision(1)<<setiosflags(ios::fixed)<<price<<endl;
        else
            cout<<(int)price<<endl;

    }
}
*/
// 2256 mincost 难道是传说中的rpwt？ (cc98)
//我用的是if(v > (double)(int)v)  于是AC

#include <iostream>
#include <iomanip>/**/

using namespace std;

int main()
{
    int distance;
    double cost;
     int i;

     while(cin>>distance ,distance != 0)
     {
        if(distance <= 4)    cost = 10;
        else{
            i = distance % 8;
            cost = (distance / 8) * 18;
            if(i <= 4)/*i<=5??(if int the same ,but if float)*/
                cost += i * 2.4;
            else
                cost += (10 + (i - 4) * 2);
        }
        if(cost > (double)(int)cost)
            cout<<setprecision(1)<<setiosflags(ios::fixed)<<cost<<endl;
        else
            cout<<(int)cost<<endl;
    }
    return 0;
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2501719 2007-06-24 12:11:32 Accepted 2256 C++ 00:00.01 836K わたし

// 2012-09-07 01:17:21 | Accepted | 2256 | C++ | 0 | 188 | watashi | Source

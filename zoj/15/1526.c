/*
#include <iostream>
using namespace std;

int main()
{
 int d;
 int n;
 cin >> n;
 for ( int i = 0 ;i < n;i++)
 {
  cin >> d;
  double h = 1;
  int cou = 0;
  for( int j = 2;j <= d;j++)
  {
   h *= j;
   while( h >= 10 )
   {
    h /= 10;
    cou ++;
   }
  }
  cout << cou +1<< endl;
 }

 return 0;
}
*/
/* //2533124 2007-07-24 14:19:02 Accepted 1526 C++ 00:03.01 836K わたし */
#include <stdio.h>
int main()
{
    long double x;
    long re,i,n,y;

    scanf("%ld",&re);
    while(re--){
        scanf("%ld",&n);
        x=1;
        y=0;
        for(i=2;i<=n;i++){
            x*=i;
            if(x>10000000000){x/=10000000000;y+=10;}
        }
        while(x>10){x/=10;y++;}
        printf("%ld\n",y+1);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2533127 2007-07-24 14:20:28 Accepted 1526 C 00:00.34 392K わたし */

// 2012-09-07 00:52:36 | Accepted | 1526 | C | 190 | 160 | watashi | Source

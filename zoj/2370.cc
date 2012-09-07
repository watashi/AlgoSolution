//圆弧~?it expands and takes the shape of a circular segment
#include <cstdlib> // auto fix CE
#include <stdio.h>
#include <cstdlib> // auto fix CE
#include <math.h>
const double EPS=1e-6;
double f(double x,double y)
{
    double a=2.0*atan(x/y);
    double r=y/sin(a);
    return 2*a*r;
}
int main()
{
    double l,r,a,s;
    double L,C,N;

    while(scanf("%lf%lf%lf",&L,&N,&C)!=EOF && (L>=0||N>=0||C>=0) ) {
        s=(1.0+N*C)*L;
        l=0;
        r=L/2;
        while(r-l>=EPS){
            a=(l+r)/2;
            if(f(a,L/2)<s) l=a;
            else r=a;
        }
        printf("%.3lf\n",a);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2683923 2007-11-24 01:29:51 Accepted 2370 C 00:00.00 384K わたし


//refer to 2614->抛物
/*
#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <vector>
#define EPS 1e-10
using namespace std;
double a,l,r;
inline double f(double x)
{
    return sqrt(4*a*a*x*x+1);
}
double Romberg(double a,double b,double (*f)(double),double eps=EPS)//Romberg积分
{
   vector<double> cur,next;
   int m,i,k;
   double x,tmp,h=b-a;
   next.clear();
   next.push_back((f(a)+f(b))*h/2);
   m=0;
   while(1){
      m++;
      cur=next;
      next.clear();
      h=h/2;
      tmp=0;
      for(i=0,x=a+h;i<(1<<(m-1));i++,x+=2*h)
         tmp+=f(x)*h;
      tmp+=cur[0]/2;
      next.push_back(tmp);
      for(k=1;k<=m;k++)
         next.push_back((pow(4.0,k)*next[k-1]-cur[k-1])/(pow(4.0,k)-1));
      if(m>=4&&fabs(next[m]-cur[m-1])<eps) break;
   }
   return next[m];
}
int main()
{
    double l,r,s;
    double L,C,N;

    while(scanf("%lf%lf%lf",&L,&N,&C)!=EOF && (L>=0||N>=0||C>=0) ) {
        s=(1.0+N*C)*L;
        l=0;
        r=2.0*s/(L*L);
        while(r-l>=EPS){
            a=(l+r)/2;
            if(Romberg(-L/2,L/2,f)<s) l=a;
            else r=a;
        }
        s=a*L*L/4;
        printf("%.3lf\n",s);
    }
}
*/


//以后来个XX曲线~

// 2012-09-07 14:10:15 | Accepted | 2370 | C++ | 0 | 180 | watashi | Source

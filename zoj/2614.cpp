//y=a(x-d/2)(x+d/2) :: <length> :: ?? S_sqrt((2*a*x)^2+1)_{-d/2,d/2} a单调~
//x=H-a*d*d/4;
#include <cmath>
#include <cstdio>
#include <vector>
#define EPS 1e-8
using namespace std;
double x,a,l,r;
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
    int ri,re,D,H,B,L;
    int c;
    double d,s;

    for(scanf("%d",&re),ri=1;ri<=re;ri++){
        scanf("%d%d%d%d",&D,&H,&B,&L);
        c=(B+D-1)/D;
        d=(double)B/(double)c;
        s=(double)L/(double)c;
        l=0;
        r=2.0*s/(d*d);
        while(r-l>=EPS){
            a=(l+r)/2;
            if(Romberg(-d/2,d/2,f)<s) l=a;
            else r=a;
        }
        x=(double)H-a*d*d/4;
        printf("Case %d:\n%.2lf\n",ri,x);
        if(ri<re) putchar('\n');
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2675106 2007-11-13 22:53:30 Accepted 2614 C++ 00:00.12 860K わたし

// 2012-09-07 01:32:24 | Accepted | 2614 | C++ | 30 | 180 | watashi | Source

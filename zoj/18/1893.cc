/*
#include <cstdio> // auto fix CE
#include <stdio.h>
long long n;
int doit(long long x)
{
    int i;
    long long tmp=x;

    if(tmp>=n) return 0;
    for(i=2;i<=9;i++)
        if(doit(tmp+=x)==0) return 1;
    return 0;
}

//int main()
//{
//   while(scanf("%d",&n)!=EOF)
//       printf("%s wins.\n",doit(1)?"Stan":"Ollie");
//}
//TLE

int main()
{
    int a=1,b;

    for(n=2;n<100000;n++){
        b=a;
        a=doit(1);
        if(!a&&b) printf("%d ",n);
        else if(a&&!b) printf("%d\n",n);
    }
    getch();
}
*/
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    long long i,n,x[20]={1};

    for(i=1;i<20;i++)
        if(i&1) x[i]=x[i-1]*9;
        else x[i]=x[i-1]*2;
    while(scanf("%lld",&n)!=EOF){
        i=0;
        while(n>x[i]) i++;
        printf("%s wins.\n",(i&1)?"Stan":"Ollie");
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2613818 2007-09-18 22:52:06 Accepted 1893 C 00:00.00 392K ¤ï¤¿¤·

// 2012-09-07 14:09:23 | Accepted | 1893 | C++ | 0 | 180 | watashi | Source

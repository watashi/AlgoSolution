//sqrt(2^31)=46340.950011841578559133736114903;
#include <cmath> // auto fix CE
#include <cstdio> // auto fix CE
#include <cmath> // auto fix CE
#include <stdio.h>
int doit(int p,int k,int m)
{
    int x;

    x=0;
    while(m){
        x+=(m/=p);
        if(x>=k) return 1;
    }
    return 0;
}
int main()
{
    int np,pl[5000]={2,3};
    int n,m,i,j,k,t,flag;

    k=2;
    for(i=5;i<46340;i+=2){
        for(j=1;pl[j]*pl[j]<=i;j++)
            if(i%pl[j]==0) break;
        if(pl[j]*pl[j]>i) pl[k++]=i;
    }
    np=k;
    while(scanf("%d%d",&m,&n)!=EOF){//maybe~ m=0||n=0
        if(n==0) {printf("%d %s %d!\n",n,"does not divide",m);continue;}
        t=n;
        flag=1;
        for(i=0;i<np&&pl[i]*pl[i]<=t;i++){
            if(t%pl[i]==0){
                k=0;
                while(t%pl[i]==0) {t/=pl[i];k++;}
                if(doit(pl[i],k,m)==0){
                    flag=0;
                    break;
                }
            }
        }
        if(flag&&t>1&&doit(t,1,m)==0) flag=0;
        printf("%d %s %d!\n",n,flag?"divides":"does not divide",m);
    }
}
//without prime list :: TLE
//right wey~
/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2617662 2007-09-22 01:50:05 Accepted 1850 C++ 00:00.01 432K わたし
*/
//素数可用筛法~

// 2012-09-07 14:09:17 | Accepted | 1850 | C++ | 0 | 180 | watashi | Source

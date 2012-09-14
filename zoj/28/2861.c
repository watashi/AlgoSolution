#include <stdio.h>
long price[40];
unsigned long cc(int n,int m)
{
    int i;
    double res=1;

    if(m>n) return 0;
    m=(m<n-m)?m:(n-m);
    for(i=1;i<=m;i++)
        res=res*(n+1-i)/i;
    return (unsigned long)res;
}
double scc(int n,int m)
{
    int i;
    double res=0;

    for(i=0;i<=m;i++)
        res=res+(double)cc(n,i);
    return res;
}
unsigned long which(int n,int l,unsigned long m)
{
    int i;

    if(m==1) return 0;
    if(l==0) return 0;
    for(i=0;i<=n;i++)
        if(m<=scc(i,l))
            return which(i-1,l-1,m-scc(i-1,l))+price[i];
    return which(n-1,l-1,m-scc(n-1,l))+price[n];
}
int main()
{
    int n,l;
    int i;
    unsigned long m;

    price[0]=0;
        price[1]=1;
        for(i=2;i<=31;i++)
            price[i]=price[i-1]*2;
    while(scanf("%d%d%u",&n,&l,&m)!=EOF){
        printf("%u\n",which(n,l,m));
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2493987 2007-06-16 21:11:19 Accepted 2861 C 00:00.00 392K ¤ï¤¿¤· */

// 2012-09-07 03:14:26 | Accepted | 2861 | C | 0 | 160 | watashi | Source

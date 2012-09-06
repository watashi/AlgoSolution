#include <stdio.h>
int main()
{
    int i,j,k,n,p[3];
    long long x[3],t[3],a[10000];

    a[0]=1;
    while(scanf("%lld%lld%lld%d",&x[0],&x[1],&x[2],&n)!=EOF){
        p[0]=p[1]=p[2]=0;
        for(i=1;i<=n;i++){
            for(j=0;j<3;j++)
                t[j]=a[p[j]]*x[j];
            k=0;
            for(j=1;j<3;j++)
                if(t[j]<t[k]) k=j;
            a[i]=t[k];
            for(j=0;j<3;j++)
                if(t[j]==t[k]) p[j]++;
        }
        printf("%lld\n",a[n]);
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2621690 2007-09-26 17:15:38 Accepted 1596 C 00:00.00 468K ¤ï¤¿¤·

// 2012-09-07 00:55:15 | Accepted | 1596 | C++ | 0 | 180 | watashi | Source

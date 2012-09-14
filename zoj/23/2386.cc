#include <cstdio> // auto fix CE
#include <stdio.h>
#include <cstdio> // auto fix CE
#include <string.h>
#define MAXN 500005
typedef long long int64;
int a[MAXN],b[MAXN];
int64 inv(int a[],int b[],int n)
{
    int l=n>>1,r=n-l,i,j;
    int64 res=(r>1)?(inv(a,b,l)+inv(a+l,b,r)):0;

    for(i=j=0;i<=l;b[i+j]=a[i],i++)
        for(res+=j;j<r&&(i==l||a[i]>a[l+j]);b[i+j]=a[l+j],j++)
            ;
    memcpy(a,b,sizeof(int)*n);
    return res;
}
int main()
{
    char c;
    int i,n;

    while(scanf("%d ",&n)!=EOF && n){
        for(i=0;i<n;i++)
        //  scanf("%d",&a[i]);
        {
            a[i]=0;
            while((c=getchar())!='\n'){a[i]*=10;a[i]+=c-'0';}
        }
        printf("%lld\n",inv(a,b,n));
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2624308 2007-09-28 21:56:23 Accepted 2386 C 00:00.71 4300K ¤ï¤¿¤·

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2624312 2007-09-28 21:58:55 Accepted 2386 C 00:00.43 4300K ¤ï¤¿¤·

/*
Rank Submit time Run time Run memory Language User
1 2007-09-28 21:58:55 00:00.43 4300K C ¤ï¤¿¤·
2 2007-04-15 15:04:29 00:00.57 4344K C++ mumuxinfei
3 2007-05-31 09:20:08 00:00.57 4744K C++ sun
4 2006-06-10 04:58:36 00:00.61 4344K C++ Freedom
5 2006-07-19 16:59:10 00:00.61 4348K C++ jeeper
6 2007-08-04 13:35:43 00:00.64 4304K C++ ËÀ°ÙÄÜ
7 2006-11-30 22:39:19 00:00.64 4340K C++ intx
8 2007-08-03 19:56:55 00:00.65 4296K C ÂÞ·½ì¿PO
9 2007-08-03 19:52:42 00:00.65 4300K C++ long1
//ws
*/

// 2012-09-07 14:10:21 | Accepted | 2386 | C++ | 240 | 4084 | watashi | Source

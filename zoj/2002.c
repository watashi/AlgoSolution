#include <stdio.h>
int n,k,a[500];
int isok(int s)
{
    int i,j,t;

    t=0;
    for(i=n-1,j=k;i>=0;){
        t+=a[i];
        if(t>s){t=0;j--;}
        else i--;
        if(j==0) return 0;
    }
    return 1;
}
void output(int s)
{
    int i,j,t,b[500];

    t=0;
    for(i=0;i<n;i++)
        b[i]=0;
    for(i=n-1,j=k;i>=0;){
        t+=a[i];
        if(t>s){t=0;j--;b[i]=1;}
        else i--;
    }
    j--;
    for(i=0;j;i++)
        if(b[i]==0){b[i]=1;j--;}
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(b[i]) printf(" / ");
        else if(i==n-1) printf("\n");
        else printf(" ");
    }
}
int main()
{
    int re,i,l,r,mid;

    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        l=0;r=1000000000;
        while(l<r){
            mid=(l+r)/2;
            if(isok(mid)) r=mid;
            else l=mid+1;
        }
        output(l);
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2595481 2007-09-04 03:47:21 Accepted 2002 C++ 00:00.02 400K わたし */



/*
Rank Submit time Run time Run memory Language User
1 2007-07-23 16:05:03 00:00.02 396K C++ zs_zeng1
2 2007-09-04 03:47:21 00:00.02 400K C++ わたし
3 2007-08-19 12:03:57 00:00.02 404K FPC 无敌小霸王
4 2007-08-19 12:19:29 00:00.02 408K FPC 我微笑代表我快乐
5 2007-08-19 12:21:09 00:00.02 420K FPC oi.hysbz.com
6 2006-11-26 16:20:32 00:00.02 844K C++ 刘若英
7 2007-04-13 20:22:35 00:00.02 844K C++ damajia
8 2007-08-13 12:46:02 00:00.02 2984K C++ lily
9 2007-03-24 11:14:00 00:00.03 392K C++ 野马
10 2007-07-26 21:47:57 00:00.03 392K C++ fzbzchenxi
11 2006-06-21 08:36:43 00:00.03 396K C++ Freedom
12 2007-03-24 11:12:48 00:00.03 396K C++ bea
13 2007-04-13 16:56:45 00:00.03 396K C++ 海蓝星
*/

// 2012-09-07 01:10:02 | Accepted | 2002 | C | 0 | 160 | watashi | Source

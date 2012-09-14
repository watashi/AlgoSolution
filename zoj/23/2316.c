#include <ctype.h>
#include <stdio.h>
#include <string.h>
int a[10001];
int i,j,n,m,ans;
int getint()
{
    char ch;
    int res;

    while((ch=getchar())<'0');
    res=0;
    do{
        res*=10;
        res+=ch-'0';
    }while((ch=getchar())>='0');
    return res;
}
int main()
{
    int re;

    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&n,&m);
        memset(a+1,0,n*sizeof(int));
        m*=2;
        while(m--)
            a[getint()]++;
        ans=0;
        for(i=1;i<=n;i++)
            ans+=a[i]*a[i];
        printf("%d\n",ans);
        if(re) printf("\n");
    }
}
/* //2647106 2007-10-16 21:06:11 Accepted 2316 C++ 00:00.61 436K わたし (isdigit) */

/* //2647113 2007-10-16 21:08:39 Accepted 2316 C 00:00.40 432K わたし (>='0') */

// 2012-09-07 16:59:47 | Accepted | 2316 | C | 190 | 196 | watashi | Source

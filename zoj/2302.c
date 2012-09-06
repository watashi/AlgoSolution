#include <stdio.h>
#define ABS(x) (((x)>=0)?(x):-(x))
#define MAX(a,b) (((a)>(b))?(a):(b))
long long ans,x[6],f[6],t[6];
int n,in[6],out[6];
void dfs(long long pos,long long time)
{
    int i,cc=0;

    if(ans!=-1&&time>=ans) return;
    for(i=0;i<n;i++){
        if(!in[i]){
            in[i]=1;
            dfs(f[i],MAX(time+ABS(f[i]-pos),x[i]));
            in[i]=0;
        }
        else if(!out[i]){
            out[i]=1;
            dfs(t[i],time+ABS(t[i]-pos));
            out[i]=0;
        }
        else cc++;
    }
    if(cc==n&&(ans==-1||time<ans)) ans=time;;
}
int main()
{
    int ri=0;
    int i;

    while(scanf("%d",&n)!=EOF && n>=0){
        /*NO..n==0..*/
        for(i=0;i<n;i++)
            scanf("%lld",&x[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&f[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&t[i]);
        for(i=0;i<n;i++){
/*          if(f[i]==t[i]){i--;n--;continue;}/*..f[i]==t[i]..-_-b*/
            in[i]=out[i]=0;
        }
        ans=-1;
        dfs(1,0);
        printf("Test %d:\n%lld\n",++ri,ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2639090 2007-10-10 15:10:41 Accepted 2302 C 00:00.01 384K わたし */
/*
Rank Submit time Run time Run memory Language User
1 2005-11-24 23:35:03 00:00.00 432K C++ ant
2 2005-09-14 21:35:17 00:00.00 436K C++ qinlu
3 2007-03-27 11:23:44 00:00.00 668K FPC 无双月
4 2007-04-26 20:13:22 00:00.00 716K FPC lch
5 2006-02-02 12:37:08 00:00.00 836K C++ wcm
6 2007-10-10 15:10:41 00:00.01 384K C わたし
7 2005-09-25 11:55:45 00:00.01 400K FPC cqf
8 2006-10-09 14:52:24 00:00.01 432K C++ lzj0me
9 2005-10-13 00:21:24 00:00.01 436K C++ 十年之后
10 2006-10-09 14:55:17 00:00.01 436K C++ scau_fun
11 2007-04-26 23:29:45 00:00.02 2288K FPC Cheryl
12 2005-09-15 00:14:34 00:00.05 832K C++ Leave me alone
END
*/

// 2012-09-07 03:09:57 | Accepted | 2302 | C | 0 | 160 | watashi | Source

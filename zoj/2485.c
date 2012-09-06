#include <stdio.h>
int tone(long long pos)
{
    long long bin;
    int res;

    bin=1;
    res=0;
    while(bin>0){
        if(bin&pos) res++;
        bin<<=1;
    }
    return res;
}
int main()
{
    int ri,re;
    long long i,total,cant,pos;

    scanf("%d",&re);
    for(ri=1;ri<=re;ri++){
        scanf("%lld%lld%lld",&total,&cant,&pos);
        printf("Case %d:",ri);
        if(pos+cant-1>total){
            printf(" It cannot be solved.\n");
            continue;
        }
        for(i=0;i<cant;i++)
            printf(" %d",tone(pos++));
        printf("\n");
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2600996 2007-09-08 14:22:41 Accepted 2485 C 00:00.00 392K わたし */
/* //2600995 2007-09-08 14:22:31 Accepted 2485 C++ 00:00.00 388K わたし */

/*
Rank Submit time Run time Run memory Language User
1 2006-04-20 18:36:13 00:00.00 388K C++ estac
2 2007-09-08 14:22:31 00:00.00 388K C++ わたし
3 2005-09-15 12:47:40 00:00.00 392K C++ ant
4 2005-09-15 23:03:34 00:00.00 832K C++ Leave me alone
5 2005-12-05 23:22:59 00:00.00 832K C++ 装飛哂
6 2006-12-28 01:03:32 00:00.00 832K C++ cytmike
7 2005-09-27 22:45:41 00:00.00 836K C++ linyuazh
8 2005-09-18 11:14:13 00:00.00 3360K GPC Lite.Xavier
9 2007-08-02 21:53:37 00:00.01 392K C++ zhushuai
10 2006-02-02 14:44:17 00:00.01 900K C++ wcm
*/

// 2012-09-07 03:10:58 | Accepted | 2485 | C | 0 | 160 | watashi | Source

#include <stdio.h>
char str[20][40];
int index[20],mark[20];
int main()
{
    int re,n,m,i,j;

    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
            mark[i]=index[i]=-1;
        }
        while(m--){
            scanf("%d%d",&i,&j);
            index[--j]=--i;
            mark[i]=0;
        }
        for(i=j=0;i<n;i++){
            if(index[i]==-1){
                while(!mark[j]) j++;
                index[i]=j;
                mark[j]=0;
            }
            printf("%s",str[index[i]]);
            if(i<n-1) printf(" ");
            else printf("\n");
        }
    }
}
/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2624278 2007-09-28 21:34:46 Accepted 2782 C 00:00.00 388K わたし
*/
/*
Rank Submit time Run time Run memory Language User
1 2007-02-06 17:17:54 00:00.00 388K C mj
2 2007-02-08 03:10:57 00:00.00 388K C++ Elevent Hour
3 2007-03-04 19:34:39 00:00.00 388K C++ WAC
4 2007-03-10 11:23:31 00:00.00 388K C acgf
5 2007-03-24 20:52:13 00:00.00 388K C++ 8600
6 2007-03-25 10:39:30 00:00.00 388K C morningyq
7 2007-04-21 17:24:19 00:00.00 388K C zjjyjsj
8 2007-04-26 15:42:50 00:00.00 388K C++ Crane
9 2007-05-29 02:50:05 00:00.00 388K C++ 9911
10 2007-08-03 09:56:03 00:00.00 388K C 听雨轩士
11 2007-09-09 22:24:07 00:00.00 388K C++ fzbzchenxi
12 2007-09-28 12:02:28 00:00.00 388K C++ Fire
13 2007-09-28 21:34:46 00:00.00 388K C わたし
14 2007-02-08 03:11:14 00:00.00 392K C++ 杭之翼
15 2007-02-11 18:22:36 00:00.00 392K C++ hazy
16 2007-03-04 21:39:29 00:00.00 392K C++ Week@ZSU
17 2007-03-10 11:23:40 00:00.00 392K C 105021022
18 2007-03-17 02:19:10 00:00.00 392K C++ skycaption
19 2007-03-21 18:24:17 00:00.00 392K C++ 我是一个马甲
20 2007-03-21 18:25:21 00:00.00 392K C++ 氢氧化铜
*/

// 2012-09-07 01:39:38 | Accepted | 2782 | C | 0 | 160 | watashi | Source

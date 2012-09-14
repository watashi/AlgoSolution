/* //枚举法 by zr （Orz） */
#include <stdio.h>
#include <stdio.h>
#define inf 10241024
int n,panic,mp[22][22];
int bin[22]={1},it;
int main()
{
    int i,j,k,tmp,ans,re;
    char str[5];

    for(k=1;k<22;k++)
        bin[k]=bin[k-1]+bin[k-1];
    scanf("%d",&re);
    while(re--){
        scanf("%d%d",&n,&panic);
        it=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                mp[i][j]=0;
        for(i=0;i<n;i++){
            scanf("%s%d",str,&k);
            if(*str=='I') it|=bin[i];
            while(k--){
                scanf("%d",&j);
                mp[i][j]++;
            }
        }
        ans=inf;
        for(k=0;k<bin[n];k++){
            if((k&bin[panic])||((k&it)!=it)) continue;
            else{
                tmp=0;
                for(i=0;i<n;i++){
                    if(k&bin[i]) continue;
                    for(j=0;j<n;j++){
                        if(!(k&bin[j])) continue;
                        if(mp[j][i]) break;
                        if(mp[i][j]) tmp+=mp[i][j];
                    }
                    if(j<n) break;
                }
                if(i==n&&tmp<ans) ans=tmp;
            }
        }
        if(ans==inf) printf("PANIC ROOM BREACH\n");
        else printf("%d\n",ans);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2646017 2007-10-15 20:34:22 Accepted 2788 C 00:00.01 396K わたし */

/*
Rank Submit time Run time Run memory Language User
1 2007-09-28 00:01:53 00:00.00 388K C++ Fire
2 2007-02-06 23:39:12 00:00.00 392K C++ 11
3 2007-10-15 20:33:52 00:00.00 392K C わたし
4 2007-05-22 16:37:22 00:00.00 396K C++ KG
5 2007-02-06 17:23:06 00:00.00 424K C mj
6 2007-03-22 19:54:32 00:00.00 444K C++ pencil
7 2007-03-22 19:54:51 00:00.00 444K C++ 8600
8 2007-08-22 14:47:19 00:00.00 444K C++ Lite.Xavier
9 2007-02-16 15:40:05 00:00.00 448K C++ ÅÆÇ
10 2007-02-06 23:32:43 00:00.00 524K C++ 对！当时就是这样！！
11 2007-05-25 21:42:53 00:00.00 848K C++ Sidky
12 2007-04-26 15:40:57 00:00.00 864K C++ Crane
13 2007-07-25 20:50:18 00:00.00 2984K C++ lolli
14 2007-07-16 12:16:01 00:00.01 396K C++ nameispassword
15 2007-03-22 09:58:18 00:00.01 400K C++ SHOIT
16 2007-02-16 15:40:14 00:00.01 448K C++ SHiVa
17 2007-10-11 23:34:42 00:00.01 468K C 杭之翼
18 2007-06-14 00:53:15 00:00.01 860K C++ angel2008
*/

// 2012-09-07 05:07:42 | Accepted | 2788 | C | 0 | 160 | watashi | Source

/*
#include <cstdio> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    char name[100][3][30],tmp[30];
    int map[20][20];
    int i,j,k,n,p,t1,t2,tail,queue[20],mind[20],count[100][20];

    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                map[i][j]=0;
        for(i=0;i<n;i++){
            while(scanf("%d",&j),j){j--;map[i][j]=1;}
        }
        k=0;
        while(scanf("%d",&queue[0]),queue[0]){
            queue[0]--;
            scanf("%d%d",&t1,&t2);
            scanf("%s%s%s",name[k][0],name[k][1],name[k][2]);
            for(i=0;i<n;i++){
                mind[i]=-1;
                count[k][i]=0;
            }
            mind[queue[0]]=0;
            p=0;
            tail=1;
            while(p<tail){
                i=queue[p++];
                for(j=0;j<n;j++){
                    if(map[i][j]==0) continue;
                    count[k][i]++;
                    if(mind[j]==-1){
                        queue[tail++]=j;
                        mind[j]=mind[i]+1;
                        //count[k][j]--;
                    }
                    //else if(mind[j]==mind[i]+1) count[k][j]--;
                }
            }
            for(i=0;i<n;i++){
                if(count[k][i]<t1) count[k][i]=0;
                else if(count[k][i]<t2) count[k][i]=1;
                else count[k][i]=2;
            }
            k++;
        }
        for(i=0;i<n;i++){
            scanf("%s",tmp);
            printf("%s: ",tmp);
            for(j=0;j<k;j++)
                printf("%s ",name[j][count[j][i]]);
            printf("\n");
        }
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2600498 2007-09-08 00:37:22 Accepted 1522 C++ 00:00.01 412K ¤ï¤¿¤·
//2600497 2007-09-08 00:36:35 Presentation Error 1522 C++ 00:00.01 412K ¤ï¤¿¤·
*/
#include <cstdio> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdio> // auto fix CE
#include <stdio.h>
int main()
{
    char name[100][3][30],tmp[30];
    int map[20][20];
    int i,j,k,n,p,t1,t2,tail,queue[20],count[20],reach[100][20];

    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            count[i]=0;
            for(j=0;j<n;j++)
                map[i][j]=0;
        }
        for(i=0;i<n;i++)
            while(scanf("%d",&j),j){j--;count[i]++;map[i][j]=1;}
        k=0;
        while(scanf("%d",&queue[0]),queue[0]){
            queue[0]--;
            scanf("%d%d",&t1,&t2);
            scanf("%s%s%s",name[k][0],name[k][1],name[k][2]);
            for(i=0;i<n;i++)
                reach[k][i]=0;
            reach[k][queue[0]]=1;
            p=0;
            tail=1;
            while(p<tail){
                i=queue[p++];
                for(j=0;j<n;j++){
                    if(map[i][j]==0||reach[k][j]) continue;
                    reach[k][j]=1;
                    queue[tail++]=j;
                }
            }
            for(i=0;i<n;i++){
                if(reach[k][i]==0||count[i]<t1) reach[k][i]=0;
                else if(count[i]<t2) reach[k][i]=1;
                else reach[k][i]=2;
            }
            k++;
        }
        for(i=0;i<n;i++){
            scanf("%s",tmp);
            printf("%s: ",tmp);
            for(j=0;j<k;j++)
                printf("%s ",name[j][reach[j][i]]);
            printf("\n");
        }
    }

    return 0;   /* NZEC */
}


//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2600507 2007-09-08 00:44:45 Accepted 1522 C 00:00.00 408K ¤ï¤¿¤·



/*
Rank Submit time Run time Run memory Language User
1 2005-09-13 15:52:34 00:00.00 404K C Leave me alone
2 2007-09-08 00:44:45 00:00.00 408K C ¤ï¤¿¤·
3 2006-05-01 08:46:51 00:00.00 920K C++ ±ù»ðÃÎ»Ã
4 2005-09-14 10:39:19 00:00.01 424K C++ qinlu
5 2006-02-03 06:20:11 00:00.01 444K C++ navy
6 2006-04-14 15:14:16 00:00.01 444K C WonD
7 2006-02-01 21:19:21 00:00.01 460K C++ wcm
8 2006-04-14 14:05:29 00:00.01 920K C++ ÈË¹¤ÖÇÄÜ
9 2005-12-26 18:09:40 00:00.02 412K C SunShine
10 2005-09-24 21:37:14 00:00.04 436K FPC cqf
11 2006-02-23 18:45:45 00:00.04 876K C++ liuchang
12 2006-01-01 23:33:37 00:00.04 900K C++ zyj
13 2006-04-14 14:31:39 00:00.04 924K C++ WoodcaT
14 2005-09-25 22:52:49 00:00.05 868K C++ Robert_Tank2001
15 2005-09-14 11:21:33 00:00.05 872K C++ XXXXXX
16 2005-09-22 23:49:18 00:00.05 872K C++ mast_whu
17 2006-07-21 22:28:46 00:00.05 884K C++ Murphy
18 2006-01-25 23:54:18 00:00.05 1204K C++ Hasti
19 2005-09-13 16:38:15 00:00.11 448K FPC wanghang
20 2005-09-13 16:38:24 00:00.11 448K FPC GameMaster
*/

// 2012-09-07 14:42:53 | Accepted | 1522 | C++ | 0 | 180 | watashi | Source

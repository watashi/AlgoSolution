#include <stdio.h>
char mp[3][4];
int isstopped()
{
    int i;

    for(i=0;i<3;i++)
        if(mp[i][0]!='.'&&mp[i][0]==mp[i][1]&&mp[i][0]==mp[i][2]||mp[0][i]!='.'&&mp[0][i]==mp[1][i]&&mp[0][i]==mp[2][i]) return 1;
    if(mp[1][1]!='.'&&(mp[0][0]==mp[1][1]&&mp[1][1]==mp[2][2]||mp[0][2]==mp[1][1]&&mp[1][1]==mp[2][0])) return 1;
    return 0;
}
int main()
{
    int i,j,a,b,re;

    scanf("%d",&re);
    while(re--){
        for(i=0;i<3;i++)
            scanf("%s",mp[i]);
        a=b=0;
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                switch(mp[i][j]){
                case 'X':a++;break;
                case 'O':b++;break;
                }
        if(a==0&&b==0) goto A;/**/
        else if(a==b){
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    if(mp[i][j]=='O'){
                        mp[i][j]='.';
                        if(!isstopped()) goto A;
                        mp[i][j]='O';
                    }
        }
        else if(a==b+1){
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    if(mp[i][j]=='X'){
                        mp[i][j]='.';
                        if(!isstopped()) goto A;
                        mp[i][j]='X';
                    }
        }
        printf("no\n");
        continue;
A:
        printf("yes\n");
        continue;
    }
}
/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2632285 2007-10-04 23:04:39 Accepted 1908 C 00:00.00 384K わたし */

/*
Rank Submit time Run time Run memory Language User
1 2005-09-19 16:14:53 00:00.00 384K C++ reject
2 2006-09-20 22:23:15 00:00.00 384K C++ CIM->A.I
3 2007-03-24 18:34:05 00:00.00 384K C++ 大家一起来AC
4 2007-10-04 23:04:39 00:00.00 384K C わたし
5 2005-09-14 20:56:58 00:00.00 388K C++ qinlu
6 2005-09-19 16:15:33 00:00.00 388K C++ asymmatrix
7 2005-09-30 16:42:17 00:00.00 388K C++ SHOIT
8 2005-11-26 22:45:59 00:00.00 388K C Ivan
9 2005-12-03 21:04:52 00:00.00 388K C++ Crane
*/

// 2012-09-07 01:05:43 | Accepted | 1908 | C | 0 | 160 | watashi | Source

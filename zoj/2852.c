#include <stdio.h>
#include <string.h>
char str[22];
int dp[2][22][22][22];
int flag;
int main()
{
    int i, j, k, p, pp, n;

    while(scanf("%d", &n) != EOF && n) {
        memset(dp[0], 0xff, sizeof(dp[0]));
        dp[0][0][0][0] = 0;
        flag = 0;
        while(n--) {
            scanf("%s", str);
            memset(dp[!flag], 0xff, sizeof(dp[0]));
            if(str[0] == 'F') {
                for (i = 0; i < 21; i++)
                    for (j = 0; j <= 21; j++)
                        for (k = 0; k <= 21; k++) {
                            if(dp[flag][i][j][k] != -1 && dp[flag][i][j][k] + 150 > dp[!flag][0][j][k])
                                dp[!flag][0][j][k] = dp[flag][i][j][k] + 150;
                            if(dp[flag][j][i][k] != -1 && dp[flag][j][i][k] + 250 > dp[!flag][j][0][k])
                                dp[!flag][j][0][k] = dp[flag][j][i][k] + 250;
                            if(dp[flag][j][k][i] != -1 && dp[flag][j][k][i] + 350 > dp[!flag][j][k][0])
                                dp[!flag][j][k][0] = dp[flag][j][k][i] + 350;
                        }
            } else {
                if(str[0] == 'A') p = 1;
                else if(str[0] >= '2' && str[0] <= '9') p = str[0] - '0';
                else p = 10;
                for (i = 0; i < 21; i++) {
                    pp = i + p;
                    if(pp == 21) {
                        for (j = 0; j <= 21; j++)
                            for (k = 0; k <= 21; k++) {
                                if(dp[flag][i][j][k] != -1 && dp[flag][i][j][k] + 150 > dp[!flag][0][j][k])
                                    dp[!flag][0][j][k] = dp[flag][i][j][k] + 150;
                                if(dp[flag][j][i][k] != -1 && dp[flag][j][i][k] + 250 > dp[!flag][j][0][k])
                                    dp[!flag][j][0][k] = dp[flag][j][i][k] + 250;
                                if(dp[flag][j][k][i] != -1 && dp[flag][j][k][i] + 350 > dp[!flag][j][k][0])
                                    dp[!flag][j][k][0] = dp[flag][j][k][i] + 350;
                            }
                    } else {
                        if(pp > 21) pp = 21;
                        for (j = 0; j <= 21; j++)
                            for (k = 0; k <= 21; k++) {
                                if(dp[flag][i][j][k] != -1 && dp[flag][i][j][k] + 50 > dp[!flag][pp][j][k])
                                    dp[!flag][pp][j][k] = dp[flag][i][j][k] + 50;
                                if(dp[flag][j][i][k] != -1 && dp[flag][j][i][k] + 50 > dp[!flag][j][pp][k])
                                    dp[!flag][j][pp][k] = dp[flag][j][i][k] + 50;
                                if(dp[flag][j][k][i] != -1 && dp[flag][j][k][i] + 50 > dp[!flag][j][k][pp])
                                    dp[!flag][j][k][pp] = dp[flag][j][k][i] + 50;
                            }
                    }
                }
            }
            if(dp[flag][21][21][21] > dp[!flag][21][21][21]) dp[!flag][21][21][21] = dp[flag][21][21][21];
            flag = !flag;
        }
        pp = -1;
        for (i = 0; i <= 21; i++)
            for (j = 0; j <= 21; j++)
                for (k = 0; k <= 21; k++)
                    if(dp[flag][i][j][k] > pp) pp = dp[flag][i][j][k];
        printf("%d\n", pp);
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2719545 2008-01-04 22:39:20 Accepted 2852 C 00:00.38 480K ¤ï¤¿¤· */

/*
ORZ them
Rank Submit time Run time Run memory Language User
1 2007-05-27 03:15:17 00:00.19 480K C++ SmallBaby
2 2007-05-27 03:15:41 00:00.19 480K C++ ACRabbit
3 2007-05-31 14:15:23 00:00.20 948K C++ m_m
4 2007-06-09 23:28:14 00:00.20 948K C++ zhang
5 2007-06-13 02:30:59 00:00.21 480K C++ 9911
6 2007-05-31 14:15:35 00:00.21 952K C++ ·¹·¹µÄ½Ç
7 2007-05-31 17:00:41 00:00.23 652K C++ mumuxinfei
8 2007-05-31 22:42:13 00:00.24 480K C++ killIs
9 2007-05-28 20:13:56 00:00.24 652K C++ singlelove
10 2007-06-02 16:46:18 00:00.25 480K C++ Leave me alone
11 2007-05-29 09:09:50 00:00.25 488K C++ SHiVa
12 2007-05-29 09:09:40 00:00.25 492K C++ ???
13 2007-05-27 19:30:57 00:00.26 924K C++ Åè¾°ÄÐ ^_^
14 2007-05-29 01:14:27 00:00.27 948K C++ IS
15 2007-06-12 21:58:16 00:00.28 480K C++ Fire
16 2007-05-27 14:12:37 00:00.29 904K C renew
17 2007-06-02 16:37:01 00:00.34 492K C++ + 0 1
18 2007-05-27 12:24:34 00:00.35 476K C++ AC²»Rush
19 2007-05-27 13:11:26 00:00.35 492K C++ xwbsw
20 2007-06-01 18:49:32 00:00.36 1348K C++ rxw

*/

// 2012-09-07 03:14:07 | Accepted | 2852 | C | 140 | 244 | watashi | Source

#include <cstring> // auto fix CE
#include <cstdio>
#include <algorithm>
using namespace std;

const int bin[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

const int dir[5][2] = {
    {0, 0},
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

int s[8][12][12];
int r, c, mp[12][12], mk[12][12];
int m, p[8];
int v, l, sum, ans;

void gao(int i)
{
    if (i == -1) {
        if(sum > ans && sum <= v)
            ans = sum;
    }
    else {
        gao(i - 1);
        sum += p[i];
        gao(i - 1);
        sum -= p[i];
    }
}

void dfs(int x, int y, int t)
{
    int xx, yy;
    int flag = mk[x][y];

    if (!flag) {
        mk[x][y] = 1;
        p[m++] = mp[x][y];
    }
    if (t == l) {
        sum = 0;
        gao(m - 1);
    }
    else {
        ++t;
        for (int k = 0; k < 5; k++) {
            xx = x + dir[k][0];
            yy = y + dir[k][1];
            if (xx >= 0 && yy >= 0 && xx < r && yy < c && s[t][xx][yy] == 0)
                dfs(xx, yy, t);
        }
    }
    if(!flag) {
        mk[x][y] = 0;
        --m;
    }
}

int main(void)
{
    int k, x[50], y[50], t[50];
    int x0, y0;

    while(scanf("%d%d", &r, &c) != EOF) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                scanf("%d", &mp[i][j]);
                mk[i][j] = 0;
            }
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d%d%d", &x[i], &y[i], &t[i]);
            --x[i];
            --y[i];
        }
        scanf("%d%d%d%d", &x0, &y0, &v, &l);
        memset(s, 0, sizeof(s));
        for (int i = 0; i < k; i++)
            for (int j = 0; j <= l; j+=t[i])
                s[j][x[i]][y[i]] = 1;
        ans = 0;
        m = 0;
        dfs(x0 - 1, y0 - 1, 0);
        printf("%d\n", ans);
    }

    return 0;   /* NZEC */
}


//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2948250   2008-06-12 15:03:38     Accepted    2033    C++     00:00.02    444K    Re:ReJudge

/*
Rank    Submit time     Run time    Run memory      Language    User
1   2006-02-12 11:35:55     00:00.01    436K    C++     SHOIT
2   2006-02-13 23:56:34     00:00.02    440K    C++     windbreaker@zsu
3   2006-02-02 11:21:18     00:00.02    444K    C++     wcm
4   2008-06-12 15:03:38     00:00.02    444K    C++     Re:ReJudge
5   2007-09-11 19:08:41     00:00.06    444K    C++     saltfish
6   2008-02-12 23:35:09     00:00.06    448K    C++     Tiaotiao
7   2007-03-30 10:26:52     00:00.17    444K    C++     ÅÆÇ
8   2007-04-01 17:14:10     00:00.17    444K    C++     SHiVa
9   2006-10-19 10:17:41     00:00.18    448K    C++     AlPacino
10  2005-09-14 00:17:32     00:00.18    840K    C++     Leave me alone
11  2006-10-19 10:12:43     00:00.19    444K    C++     CIM->A.I
12  2006-09-21 22:59:16     00:00.32    844K    C++     fisad
*/

// 2012-09-07 04:44:38 | Compilation Error | 2033 | C++ | 0 | 0 | watashi | Source

// 2012-09-07 05:03:46 | Accepted | 2033 | C++ | 0 | 184 | watashi | Source

#include <cstdio>
#include <algorithm>
using namespace std;

const int Dir[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

char mp[55][55];

void gao(const int x, const int y)
{
    if(mp[x][y] != 'X')
        return;
    mp[x][y] = '*'; // '@' WA
    for (int i = 0; i < 4; i++)
        gao(x + Dir[i][0], y + Dir[i][1]);
}

void doit(const int x, const int y, int& ans)
{
    if(mp[x][y] == 'X') {
        ++ans;
        gao(x, y);
        doit(x, y, ans); // or WA
    }
    else if(mp[x][y] == '*') {
        mp[x][y] = '.';
        for (int i = 0; i < 4; i++)
            doit(x + Dir[i][0], y + Dir[i][1], ans);
    }
}

int ans[1024];

int main(void)
{
    int ri = 0, w, h, c;

    while(scanf("%d%d", &w, &h) != EOF && w > 0 && h > 0) {
        for (int j = 0; j <= w + 1; j++)
            mp[0][j] = mp[h + 1][j] = '.';
        for (int i = 1; i <= h; i++) {
            scanf("%s", mp[i] + 1);
            mp[i][0] = mp[i][w + 1] = '.';
        }
        c = 0;
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                if(mp[i][j] != '.')
                    doit(i, j, ans[c++] = 0);
        sort(ans, ans + c);
        printf("Throw %d\n", ++ri);
        if(c == 0)
            putchar('\n');
        for (int i = 0; i < c; i++) {
            printf("%d", ans[i]);
            putchar(i == c - 1 ? '\n' : ' ');
        }
        putchar('\n');
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2840328   2008-04-12 17:21:49     Accepted    1191    C++     00:00.01    556K    Re:ReJudge

// 2012-09-07 00:40:55 | Accepted | 1191 | C++ | 0 | 188 | watashi | Source

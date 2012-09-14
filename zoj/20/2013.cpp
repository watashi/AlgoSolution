// tree
#include <cstdio>

const int dir[][2] = {
    1, 0, 0, 1, -1, 0, 0, -1
};

char s, t, mp[1024][1024];
int r, c, l, xx, yy, len;

void gao(int x, int y)
{
    if (mp[x][y] == s) {
        mp[x][y] = t;
        if (l > len) { len = l; xx = x; yy = y; }
        ++l;
        for (int i = 0; i < 4; i++) {
            gao(x + dir[i][0], y + dir[i][1]);
        }
        --l;
    }
}

int main()
{
    int re;

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d", &c, &r);
        for (int j = 1; j <= c; j++) {
            mp[0][j] = mp[r + 1][j] = '#';
        }
        xx = yy = 0;
        for (int i = 1; i <= r; i++) {
            scanf("%s", &mp[i][1]);
            for (int j = 1; j <= c && mp[xx][yy] != '.'; j++) {
                if (mp[i][j] == '.') {
                    xx = i;
                    yy = j;
                }
            }
            mp[i][0] = mp[i][c + 1] = '#';
        }
        len = 0;
        l = 0;
        s = '.';
        t = '?';
        gao(xx, yy);
        l = 0;
        s = '?';
        t = '#';
        gao(xx, yy);
        printf("Maximum rope length is %d.\n", len);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1689768   2008-11-05 08:18:10     Accepted    2013    C++     220     1200    watashi@Zodiac

// 2012-09-07 01:10:14 | Accepted | 2013 | C++ | 210 | 1204 | watashi | Source

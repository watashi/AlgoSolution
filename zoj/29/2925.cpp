//不要一堆if,美化你的程序

#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

const int dir[8][2] = {
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
};
const char* DIR = "WVNYEQSJ";
const int diff[3] = {-1, 0, 1};

inline int mod(const int a, const int b)
{
    if(a == -1) return b - 1;
    else if(a == b) return 0;
    return a;
}

char mp[505][505];

int main(void)
{
    bool blank = false;
    int x, y, z, xx, yy, n, m;
    char ch;

    while(scanf("%d%d", &n, &m) != EOF) {
        fill(mp[0], mp[0] + m + 2, '.');
        for (int i = 1; i <= n; i++) {
            mp[i][0] = '.';
            scanf("%s", mp[i] + 1);
        }
        fill(mp[n + 1], mp[n + 1] + m + 2, '\0');
        scanf("%d%d %c", &x, &y, &ch);
        for (int i = 0; i < 8; i++)
            if(ch == DIR[i]) {
                mp[x][y] = i;
                break;
            }

        queue <pair<int, int> > bfs;
        bfs.push(make_pair(x, y));
        while(!bfs.empty()) {
            x = bfs.front().first;
            y = bfs.front().second;
            bfs.pop();
            for (int i = 0; i < 3; i++) {
                z = mod(mp[x][y] + diff[i], 8);
                xx = x + dir[z][0];
                yy = y + dir[z][1];
                if(mp[xx][yy] == 'X') {
                    mp[xx][yy] = z;
                    bfs.push(make_pair(xx, yy));
                }
            }
        }
        if(blank) putchar('\n');
        else blank = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                if(mp[i][j] < 8) mp[i][j] = DIR[mp[i][j]];
            puts(mp[i] + 1);
        }
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2762812 2008-02-27 16:44:06 Accepted 2925 C++ 00:00.04 1096K わたし

// 2012-09-07 01:47:47 | Accepted | 2925 | C++ | 20 | 428 | watashi | Source

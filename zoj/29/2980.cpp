// solution by whatashya @ zju

#include <cstring> // auto fix CE
#include <cmath>
#include <cstring> // auto fix CE
#include <cstdio>
#include <cstring> // auto fix CE
#include <cstdlib>
#include <cstring> // auto fix CE
#include <map>
#include <cstring> // auto fix CE
#include <set>
#include <cstring> // auto fix CE
#include <list>
#include <cstring> // auto fix CE
#include <deque>
#include <cstring> // auto fix CE
#include <queue>
#include <cstring> // auto fix CE
#include <stack>
#include <cstring> // auto fix CE
#include <bitset>
#include <cstring> // auto fix CE
#include <vector>
#include <cstring> // auto fix CE
#include <string>
#include <cstring> // auto fix CE
#include <limits>
#include <cstring> // auto fix CE
#include <algorithm>
#include <cstring> // auto fix CE
#include <functional>

using namespace std;

const int dir[4][2] = {
    {1, 0},
    {0, -1},
    {-1, 0},
    {0, 1}
};

struct Status
{
    char x, y, z;
};

inline int c2i(char c)
{
    switch(c)
    {
    case 'b': return 1;
    case 'y': return 2;
    case 'r': return 4;
    case 'g': return 8;
    }
    return 0;
}

inline int C2i(char C)
{
    switch(C)
    {
    case 'B': return 1;
    case 'Y': return 2;
    case 'R': return 4;
    case 'G': return 8;
    }
    return 0;
}

char mp[102][102];
int mind[102][102][16];
Status q[100 * 100 * 16];
int p, t;

int main(void)
{
    static int r, c, ans;
    static int x, y, z, xx, yy, zz;

    memset(mp[0], '#', sizeof(mp[0]));
    while(scanf("%d%d", &r, &c) != EOF && r + c > 0) {
        p = t = 0;
        for (int i = 1; i <= r; i++) {
            mp[i][0] = '#';
            scanf("%s", mp[i] + 1);
            for (int j = 1; j <= c; j++) {
                for (int k = 0; k < 16; k++)
                    mind[i][j][k] = -1;
                if(mp[i][j] == '*') {
                    q[t].x = i;
                    q[t].y = j;
                    q[t].z = 0;
                    mind[i][j][0] = 0;
                    ++t;
                    mp[i][j] = '.';
                }
            }
            mp[i][c + 1] = '#';
        }
        memset(mp[r + 1], '#', (c + 1) * sizeof(char));
        ans = -1;
        while(p < t) {
            x = q[p].x;
            y = q[p].y;
            z = q[p].z;
            for (int d = 0; d < 4; d++) {
                xx = x + dir[d][0];
                yy = y + dir[d][1];
                if(mp[xx][yy] == '#')
                    continue;
                else if(mp[xx][yy] == 'X') {
                    ans = mind[x][y][z] + 1;
                    p = t;
                    break;
                }
                else if(mp[xx][yy] == '.') {
                    zz = z;
                    if(mind[xx][yy][zz] != -1)
                        continue;
                }
                else if(islower(mp[xx][yy])) {
                    zz = (z | c2i(mp[xx][yy]));
                    if(mind[xx][yy][zz] != -1)
                        continue;
                }
                else if(isupper(mp[xx][yy])) {
                    zz = z;
                    if((zz & C2i(mp[xx][yy])) == 0 || mind[xx][yy][zz] != -1)
                        continue;
                }
                else
                    continue;
                //printf("%d %d %d\n", xx, yy, zz);
                q[t].x = xx;
                q[t].y = yy;
                q[t].z = zz;
                mind[xx][yy][zz] = mind[x][y][z] + 1;
                ++t;
            }
            ++p;
        }
        if(ans == -1)
            puts("The poor student is trapped!");
        else
            printf("Escape possible in %d steps.\n", ans);
    }

    return 0;
}

/*
real    0m0.156s
user    0m0.155s
sys     0m0.015s
*/

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2948285   2008-06-12 15:42:09     Accepted    2980    C++     00:00.25    1532K   Re:ReJudge

// 2012-09-07 14:05:46 | Accepted | 2980 | C++ | 120 | 1308 | watashi | Source

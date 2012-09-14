// ljl ws-_-b
// 最小生成树
// 好题
// (0, 0)起点是无用的
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1 << 20;
const int Dir[8][2] = {
    {1, 2},
    {1, -2},
    {-1, -2},
    {-1, 2},
    {2, 1},
    {2, -1},
    {-2, -1},
    {-2, 1}
};

bool m[8][8];
int d[8][8];
int mp[8][8];

int main(void)
{
    int re;
    int x, y, xx, yy, mind, ans;

    scanf("%d", &re);
    while(re--) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                scanf("%d", &mp[i][j]);
        ans = 0;
        fill(m[0], m[8], false);
        fill(d[0], d[8], INF - 1);
        d[0][0] = 0;
        for (int k = 0; k < 64; k++) {
            x = y = -1;
            mind = INF;
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    if(!m[i][j] && d[i][j] < mind) {
                        mind = d[i][j];
                        x = i;
                        y = j;
                    }
            m[x][y] = true;
            ans += mind;
            for (int i = 0; i < 8; i++) {
                xx = x + Dir[i][0];
                yy = y + Dir[i][1];
                if(xx < 0 || xx >= 8 || yy < 0 || yy >= 8)
                    continue;
                d[xx][yy] = min(d[xx][yy], mp[x][y] + mp[xx][yy]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2873134   2008-04-27 08:16:46     Accepted    2080    C++     00:00.00    436K    Re:ReJudge

// 2012-09-07 01:12:17 | Accepted | 2080 | C++ | 0 | 180 | watashi | Source

#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

const int dir[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

char mp[10][11];
int dp[10][10][3];
// 0->dist, 1->all, 2->save

int main(void)
{
    int ri, re, n, m;
    int x, y, xx, yy;

    scanf("%d", &re);
    for (ri = 1; ri <= re; ri++) {
        queue <pair <int, int> > bfs;

        scanf("%d%d ", &n, &m);
        for (int i = 0; i < n; i++) {
            gets(mp[i]);
            for (int j = 0; j < m; j++) {
                if(mp[i][j] == 'S') {
                    bfs.push(make_pair(i, j));
                    dp[i][j][0] = 0;
                    dp[i][j][1] = dp[i][j][2] = 1;
                }
                else dp[i][j][0] = -1;
            }
        }
        x = y = 0;
        while(!bfs.empty()) {
            x = bfs.front().first;
            y = bfs.front().second;
            bfs.pop();
            if(mp[x][y] == 'T') break;
            for (int i = 0; i < 4; i++) {
                xx = x + dir[i][0];
                yy = y + dir[i][1];
                if(mp[xx][yy] != '#') {
                    if(dp[xx][yy][0] == -1) {
                        dp[xx][yy][0] = dp[x][y][0] + 1;
                        dp[xx][yy][1] = dp[x][y][1];
                        dp[xx][yy][2] = (mp[xx][yy] == 'M') ? 0 : dp[x][y][2];
                        bfs.push(make_pair(xx, yy));
                    }
                    else if(dp[xx][yy][0] = dp[x][y][0] + 1) {
                        dp[xx][yy][1] += dp[x][y][1];
                        if(mp[xx][yy] != 'M') dp[xx][yy][2] += dp[x][y][2];
                    }
                }
            }
        }
        printf("Mission #%d:\n", ri);
        if(mp[x][y] != 'T' || dp[x][y][0] == -1 || dp[x][y][2] == 0)
            printf("Mission Impossible.\n");
        else
            printf("The probability for the spy to get to the telegraph transmitter is %.2lf%%.\n",
                100.0 * (double)dp[x][y][2] / (double)dp[x][y][1]);
        printf("\n");
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2772074 2008-03-06 10:19:45 Accepted 2081 C++ 00:00.00 844K ¤ï¤¿¤·

// 2012-09-07 01:12:23 | Accepted | 2081 | C++ | 0 | 180 | watashi | Source

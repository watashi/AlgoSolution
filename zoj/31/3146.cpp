#include <queue>
#include <cstdio>
#include <limits>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, pair<int, int> > Pdv;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int mp[33][33], d[33][33];

int main()
{
    int n, m, r, c;

    while (scanf("%d%d", &n, &m) != EOF) {
        scanf("%d%d", &r, &c);
        --r;
        --c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &mp[i][j]);
                d[i][j] = numeric_limits<int>::max();
            }
        }

        priority_queue<Pdv, vector<Pdv>, greater<Pdv> > pq;
        Pdv p;
        int x, y, xx, yy;
        bool flag = false;

        pq.push(make_pair(0, make_pair(r, c)));
        d[r][c] = 0;
        while (!pq.empty()) {
            p = pq.top();
            pq.pop();
            x = p.second.first;
            y = p.second.second;
            if (mp[x][y] == 0) {
                printf("%d\n", p.first);
                flag = true;
                break;
            }
            if (p.first != d[x][y]) {
                continue;
            }
            for (int t = 0; t < 4; t++) {
                xx = x + dx[t] * mp[x][y];
                yy = y + dy[t] * mp[x][y];
                /*
                xx >?= 0;
                xx <?= n - 1;
                yy >?= 0;
                yy <?= m - 1;
                */
                xx = max(xx, 0);
                xx = min(xx, n - 1);
                yy = max(yy, 0);
                yy = min(yy, m - 1);
                if (d[xx][yy] > p.first + mp[x][y]) {
                    d[xx][yy] = p.first + mp[x][y];
                    pq.push(make_pair(d[xx][yy], make_pair(xx, yy)));
                }
            }
        }

        if (!flag) {
            puts("No solution");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750192   2009-01-28 15:26:42     Accepted    3146    C++     0   184     watashi@Zodiac

// 2012-09-07 02:03:28 | Accepted | 3146 | C++ | 0 | 188 | watashi | Source

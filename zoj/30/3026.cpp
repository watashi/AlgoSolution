#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

const int dir[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

int a[33][33], d[33][33][4];
int c[10];

struct S
{
    int i, j, k;
    S() { }
    S(int i, int j, int k)
        : i(i), j(j), k(k)
    {
    }
    bool operator<(const S& s) const
    {
        if (i != s.i) {
            return i < s.i;
        }
        else if (j != s.j) {
            return j < s.j;
        }
        else {
            return k < s.k;
        }
    }
};

int main(void)
{
    int h, w;

    while (scanf("%d%d", &w, &h) != EOF && h > 0 && w > 0) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &a[i][j]);
                for (int k = 0; k < 4; k++) {
                    d[i][j][k] = 1000000000;
                }
            }
        }
        for (int k = 0; k < 4; k++) {
            scanf("%d", &c[k]);
        }

        set<pair<int, S> > s;
        pair<int, S> p;
        int x, y, z, t;

        d[0][0][0] = 0;
        s.insert(make_pair(0, S(0, 0, 0)));
        while (!s.empty()) {
            p = *s.begin();
            s.erase(s.begin());
            if (p.first != d[p.second.i][p.second.j][p.second.k]) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                z = (p.second.k + k) % 4;
                x = p.second.i + dir[z][0];
                y = p.second.j + dir[z][1];
                t = ((a[p.second.i][p.second.j] == k) ? 0 : c[k]);
                if (x >= 0 && x < h && y >= 0 && y < w && d[x][y][z] > p.first + t) {
                    d[x][y][z] = p.first + t;
                    s.insert(make_pair(d[x][y][z], S(x, y, z)));
                }
            }
        }

        int ans = 1000000000;

        for (int k = 0; k < 4; k++) {
            ans = min(ans, d[h - 1][w - 1][k]);
        }

        printf("%d\n", ans);
    }

    return 0;
}



//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3040793   2008-08-18 16:53:20     Accepted    3026    C++     00:00.38    948K    Re:ReJudge
//

// 2012-09-07 01:56:18 | Accepted | 3026 | C++ | 210 | 200 | watashi | Source

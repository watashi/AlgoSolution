// Fire想到了回到同一点可以当作延时2s减少两次效果出发的办法

#include <queue>
#include <limits>
#include <cstdio>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

inline int encode(int x, int y, int m, int n)
{
    return (x) | (y << 10) | (m << 20) | (n << 26);
}

inline void decode(int code, int& x, int& y, int& m, int& n)
{
    x = (code & 0x3ff);
    code >>= 10;
    y = (code & 0x3ff);
    code >>= 10;
    m = (code & 0x3f);
    code >>= 6;
    n = (code);
}

int m[303][303], n[303][303];
hash_map<int, int> d;

inline int& mind(int code)
{
    return (d.count(code) == 0) ? (d[code] = numeric_limits<int>::max()) : d[code];
}

int main()
{
    int re, r, c, mn, code;
    int xx, yy, mm, nn, sx, sy, ex, ey, dist;

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &mn);
                m[i][j] = mn / 10;
                n[i][j] = mn % 10;
            }
        }
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

        d.clear();
        code = encode(sx, sy, m[sx][sy], n[sx][sy]);
        d[code] = 0;
        q.push(make_pair(0, code));
        while (!q.empty()) {
            if (d[q.top().second] > (dist = q.top().first)) {
                q.pop();
                continue;
            }
            decode(q.top().second, sx, sy, mm, nn);
            //printf("%d %d %d %d %d\n", sx, sy, mm, nn, dist);
            if (sx == ex && sy == ey) {
                printf("%d\n", dist);
                break;
            }
            q.pop();
            for (int t = 0; t < 4; t++) {
                xx = sx + nn * dx[t];
                yy = sy + nn * dy[t];
                if (xx < 0 || xx >= r || yy < 0 || yy >= c || n[xx][yy] == 0) {
                    continue;
                }
                else if (n[xx][yy] == 1) {
                    if (mm == 1 || nn == 1) {
                        code = encode(xx, yy, 0, 1);
                    }
                    else {
                        code = encode(xx, yy, mm - 1, nn);
                    }
                    int& dd = mind(code);
                    if (dd > dist + 1) {
                        dd = dist + 1;
                        q.push(make_pair(dd, code));
                    }
                }
                else {
                    for (int i = 0; i < m[xx][yy]; i += 2) {
                        code = encode(xx, yy, m[xx][yy] - i, n[xx][yy]);
                        int& dd = mind(code);
                        if (dd > dist + 1 + i) {
                            dd = dist + 1 + i;
                            q.push(make_pair(dd, code));
                        }
                    }
                }
            }
        }

        if (q.empty()) {
            puts("IMPOSSIBLE");
        }
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3049893   2008-08-25 14:33:14     Accepted    3032    C++     00:01.00    6488K   watashi@Zodiac

// 2012-09-07 01:56:49 | Accepted | 3032 | C++ | 430 | 6184 | watashi | Source

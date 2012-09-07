#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

struct Status {
    int gx: 8;
    int gy: 8;
    int mx: 8;
    int my: 8;
};

bool operator<(const Status& lhs, const Status& rhs) {
    return *(int*)&lhs < *(int*)&rhs;
}

const int INF = 0x3f3f3f3f;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int rx[] = {1, 0, -1, 0};
const int ry[] = {0, -1, 0, 1};

char maze[12][17];
int d[11][16][11][16];

void gao(int gx, int gy, int mx, int my) {
    int ds, dt;
    Status s, t;
    priority_queue<pair<int, Status> > heap;

    s.gx = gx;
    s.gy = gy;
    s.mx = mx;
    s.my = my;
    memset(d, 0x3f, sizeof(d));
    d[s.gx][s.gy][s.mx][s.my] = 0;

    heap.push(make_pair(0, s));
    while (!heap.empty()) {
        ds = -heap.top().first;
        s = heap.top().second;
        heap.pop();
        if (d[s.gx][s.gy][s.mx][s.my] != ds) {
            continue;
        }
        // printf("%d %d %d %d %d\n", s.gx, s.gy, s.mx, s.my, ds);

        for (int k = 0; k < 4; ++k) {
            t = s;
            dt = ds;
            if (maze[t.gx][t.gy] != 'O') {
                t.gx += dx[k];
                t.gy += dy[k];
                dt += 2;
                if (maze[t.gx][t.gy] == 'X') {
                    t.gx = s.gx;
                    t.gy = s.gy;
                }
            }
            if (maze[t.mx][t.my] != 'O') {
                t.mx += rx[k];
                t.my += ry[k];
                dt += 3;
                if (maze[t.mx][t.my] == 'X') {
                    t.mx = s.mx;
                    t.my = s.my;
                }
            }
            if (d[t.gx][t.gy][t.mx][t.my] > dt) {
                d[t.gx][t.gy][t.mx][t.my] = dt;
                heap.push(make_pair(-dt, t));
            }
        }

        if (abs(s.gx - s.mx) + abs(s.gy - s.my) == 1
                && ((maze[s.gx][s.gy] == 'O') ^ (maze[s.mx][s.my] == 'O'))) {
            if (maze[s.gx][s.gy] == 'O') {
                s.gx = s.mx;
                s.gy = s.my;
            } else {
                s.mx = s.gx;
                s.my = s.gy;
            }
            ds += 11;
            if (d[s.gx][s.gy][s.mx][s.my] > ds) {
                d[s.gx][s.gy][s.mx][s.my] = ds;
                heap.push(make_pair(-ds, s));
            }
        }
    }
}

int main() {
    int re;
    int gx, gy, mx, my, hx, hy, ans;

    scanf("%d ", &re);
    for (int ri = 1; ri <= re; ++ri) {
        memset(maze, 'X', sizeof(maze));
        hx = hy = -1;
        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 15; ++j) {
                maze[i][j] = getchar();
                if (maze[i][j] == 'H') {
                    assert(hx == -1 && hy == -1);
                    hx = i;
                    hy = j;
                } else {
                    assert(maze[i][j] == 'O' || maze[i][j] == 'X' || maze[i][j] == '.');
                }
            }
            assert(getchar() == '\n');
        }
        assert(scanf("%d%d", &gx, &gy) == 2);
        assert(getchar() == '\n');
        assert(scanf("%d%d", &mx, &my) == 2);
        assert(getchar() == '\n');
        assert(getchar() == '\n');
        assert(1 <= gx && gx <= 10 && 1 <= gy && gy <= 15 && maze[gx][gy] != 'X');
        assert(1 <= mx && mx <= 10 && 1 <= my && my <= 15 && maze[mx][my] != 'X');
        assert(hx != -1 && hy != -1);

        ans = INF;
        gao(gx, gy, mx, my);
        ans = min(ans, d[hx][hy][hx][hy]);
        fprintf(stderr, "Gurin = %d\n", d[hx][hy][hx][hy]);
        gao(mx, my, gx, gy);
        ans = min(ans, d[hx][hy][hx][hy]);
        fprintf(stderr, "Malon = %d\n", d[hx][hy][hx][hy]);
        printf("%d\n", ans < INF ? ans : -1);
    }
    assert(getchar() == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//211   2011-04-03 01:07:00     Accepted    B   C++     380     300     watashi     Source

// 2012-09-07 16:00:09 | Accepted | 3478 | C++ | 300 | 300 | watashi | Source

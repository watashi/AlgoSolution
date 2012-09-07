#include <queue>
#include <cstdio>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

int d[1024][1024];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int floor(int a, int b) {
    if (a < 0) return -((-a + b - 1) / b);
    else return a / b;
}

int w, h;
bool rx, ry, rxy;

void mark(int x, int y) {
    // printf("(%d, %d) -> ", x, y);
    if (rxy) swap(x, y);
    if (ry) y = -y;
    if (rx) x = -x;
    // printf("(%d, %d)\n", x, y);
    if (0 <= x && x < w && 0 <= y && y < h) d[x][y] = 0;
}

void gao(int w, int h, int x, int y, int dx, int dy) {
    if ((rx = (dx < 0))) { w = -w; x = -x; dx = -dx; }
    if ((ry = (dy < 0))) { h = -h; y = -y; dy = -dy; }
    if ((rxy = (dx < dy))) { swap(w, h); swap(x, y); swap(dx, dy); }
    // printf("_ %d %d %d %d %d %d _\n", w, h, x, y, dx, dy);

    { int g = gcd(dx, dy); dx /= g; dy /= g; }

    for (int i = x; i < w || i <= 0; ++i) {
        int j = floor(y * dx + (i - x) * dy, dx);
        mark(i, j);
        if ((i - x) % dx != 0) mark(i, j + 1);
    }
}

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

int main() {
    int n, x, y, dx, dy;

    while (scanf("%d%d%d", &w, &h, &n) != EOF) {
        assert(3 <= w && w <= 1000);
        assert(3 <= h && h <= 1000);
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                d[i][j] = -1;
            }
        }
        for (int k = 0; k < n; ++k) {
            scanf("%d%d%d%d", &x, &y, &dx, &dy);
            assert(0 <= x && x < w);
            assert(0 <= y && y < h);
            assert(dx != 0 || dy != 0);
            gao(w, h, x, y, dx, dy);
        }

        int maxd = 0;
        queue<pair<int, int> > q;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                if (d[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            // printf("d[%d][%d] = %d\n", x, y, d[x][y]);
            for (int k = 0; k < 4; ++k) {
                dx = x + xx[k];
                dy = y + yy[k];
                if (0 <= dx && dx < w && 0 <= dy && y < h && d[dx][dy] == -1) {
                    maxd = d[dx][dy] = d[x][y] + 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }

        fprintf(stderr, "maxd = %d\n", maxd);
        if (maxd == 0) {
            puts("MISS!");
        } else {
            bool blank = false;
            for (int i = 0; i < w; ++i) {
                for (int j = 0; j < h; ++j) {
                    if (d[i][j] == maxd) {
                        if (blank) {
                            putchar(' ');
                        } else {
                            blank = true;
                        }
                        printf("(%d, %d)", i, j);
                    }
                }
            }
            puts("");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//315   2010-06-27 07:45:25     Accepted    1058    C++     1150    10108   anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//217   2010-08-12 15:08:33     Accepted    hatate  C++     540     10104   watashi@Zodiac  Source

// 2012-09-07 15:50:18 | Accepted | 3376 | C++ | 570 | 10108 | watashi | Source

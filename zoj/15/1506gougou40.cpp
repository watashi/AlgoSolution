#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cstring>

const int MAXN = 128;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

char buf[MAXN][MAXN];
int sx, sy;
bool ans;

bool isyard(int x, int y) {
    return (buf[x - 1][y - 1] != '#' && buf[x - 1][y] != '#' && buf[x][y - 1] != '#')
        || (buf[x - 1][y + 1] != '#' && buf[x - 1][y] != '#' && buf[x][y + 1] != '#')
        || (buf[x + 1][y - 1] != '#' && buf[x + 1][y] != '#' && buf[x][y - 1] != '#')
        || (buf[x + 1][y + 1] != '#' && buf[x + 1][y] != '#' && buf[x][y + 1] != '#');
}

void finddoor(int x, int y) {
    if (buf[x][y] == '.') {
        if ((buf[x - 1][y] == '#' && buf[x + 1][y] == '#') || (buf[x][y - 1] == '#' && buf[x][y + 1] == '#')) {
            sx = x;
            sy = y;
        } else {
            buf[x][y] = '*';
            for (int i = 0; i < 4; ++i) {
                finddoor(x + dx[i], y + dy[i]);
            }
        }
    }
}

void gao(int x, int y, int z) {
    if (buf[x][y] == ' ') {
        ans = true;
    } else if ((buf[x][y] & (1 << z)) == 0) {
        buf[x][y] |= 1 << z;
        // left, forwark, right, back
        z = (z + 2) & 3;
        for (int i = 0; i < 4; ++i) {
            z = (z + 3) & 3;
            if (buf[x + dx[z]][y + dy[z]] != '#') {
                gao(x + dx[z], y + dy[z], z);
                break;
            }
        }
    }
}

int main() {
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF) {
        memset(buf, '#', sizeof(buf));
        for (int i = 1; i <= n; ++i) {
            scanf("%s", buf[i] + 1);
        }
        finddoor(1, 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (buf[i][j] == '*') {
                    buf[i][j] = '#';
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (buf[i][j] == '.') {
                    if (isyard(i, j)) {
                        buf[i][j] = ' ';
                    } else {
                        buf[i][j] = '\0';
                    }
                }
            }
        }
        ans = false;
        gao(sx, sy, 0);
        puts(ans ? "YES" : "NO");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//347   2010-06-29 05:07:49     Accepted    1038    C++     10  196     anotherpeg  Source

// 2012-09-30 23:41:13 | Accepted | 1506 | C++ | 0 | 196 | watashi | Source

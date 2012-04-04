#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 64;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int bpx, bpy, dp, cp, cpz;

int main() {
    int r, c, x, y, z, n;
    char buf[MAXN];
    int a[MAXN][MAXN];
    int b[MAXN][MAXN][4];

    scanf("%d%d", &r, &n);
    for (int i = 1; i <= r; ++i) {
        scanf("%s", buf + 1);
        c = strlen(buf + 1);
        for (int j = 1; j <= c; ++j) {
            a[i][j] = buf[j] - '0';
        }
    }

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            for (int k = 0; k < 4; ++k) {
                x = i;
                y = j;
                b[i][j][k] = -1;
                while (1 <= x && x <= r && 1 <= y && y <= c && a[x][y] == a[i][j]) {
                    x += dx[k];
                    y += dy[k];
                    ++b[i][j][k];
                }
            }
        }
    }

    bpx = 1;
    bpy = 1;
    dp = 0;
    cp = -1;
    while (n-- > 0) {
        x = bpx;
        y = bpy;
        z = b[x][y][dp];
        x += dx[dp] * z;
        y += dy[dp] * z;
        cpz = (dp + cp + 4) & 3;
        z = b[x][y][cpz];
        x += dx[cpz] * z;
        y += dy[cpz] * z;
        x += dx[dp];
        y += dy[dp];
        if (a[x][y] != 0) {
            bpx = x;
            bpy = y;
        } else if (cp == -1) {
            cp = 1;
        } else {
            dp = (dp + 1) & 3;
            cp = -1;
        }
    }
    printf("%d\n", a[bpx][bpy]);

    return 0;
}


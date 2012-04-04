#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

static int id = 2;

int ans;
bool cell[MAXN][MAXN];
int color[MAXN][MAXN][4], mark[MAXN][MAXN];

int dir(int d, int t) {
    return (d + t + 4) % 4;
}

bool floodfill(int x, int y) {
    if (cell[x][y]) {
        if (mark[x][y] != id) {
            return false;
        }
    } else if (mark[x][y] == 0) {
        mark[x][y] = -1;
        for (int i = 0; i < 4; ++i) {
            if (!floodfill(x + dx[i], y + dy[i])) {
                return false;
            }
        }
    }
    return true;
}

void gao(int x, int y, int z) {
    int xx, yy, zz, pos;
    vector<int> vx, vy, vz, arg(1, 0);
    while (color[x][y][z] == 0) {
        vx.push_back(x);
        vy.push_back(y);
        vz.push_back(z);
        color[x][y][z] = (int)vz.size();
        for (int t = -1; t <= 1; ++t) {
            zz = dir(z, t);
            xx = x + dx[zz];
            yy = y + dy[zz];
            if (cell[xx][yy]) {
                arg.push_back(arg.back() + 2 + t);
                break;
            }
        }
        if (cell[xx][yy]) {
            x = xx;
            y = yy;
            z = zz;
        }
    }

    pos = color[x][y][z] - 1;
    for (int i = 0; i < (int)vx.size(); ++i) {
        color[vx[i]][vy[i]][vz[i]] = -1;
    }
    if (pos < 0 || pos == (int)vz.size() - 1) {
        return;
    }

//    printf("(%d,%d,%d) %d => %d\n", x, y, z, pos, (int)vz.size());
//    printf("arg: %d - %d = %d\n", arg[(int)vz.size()], arg[pos], arg[(int)vz.size()] - arg[pos]);
    if (arg[(int)vz.size()] - arg[pos] != 2 * ((int)vz.size() - pos) - 4) {
        return;
    }

    ++id;
    for (int i = pos; i < (int)vz.size(); ++i) {
        mark[vx[i]][vy[i]] = id;
    }
//    puts("u");
    for (int i = pos; i < (int)vz.size(); ++i) {
        x = vx[i];
        y = vy[i];
        z = vz[i];
        for (int t = -1; t <= 1; ++t) {
            zz = dir(z, t);
            xx = x + dx[zz];
            yy = y + dy[zz];
            if (cell[xx][yy]) {
                break;
            } else if (!floodfill(xx, yy)) {
                return;
            }
        }
    }

    ans = max(ans, (int)vz.size() - pos);
}

int main() {
    int r, c;
    char buf[MAXN];

    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; ++i) {
        scanf("%s", buf + 1);
        for (int j = 1; j <= c; ++j) {
            if (buf[j] == '1') {
                cell[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (cell[i][j] && color[i][j][k] == 0) {
                    gao(i, j, k);
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}


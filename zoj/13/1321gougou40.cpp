#include <cstdio>
#include <algorithm>

using namespace std;

int ans;

inline int sqr(int x) {
    return x * x;
}

void gao(int dx, int dy, int x0, int y0, int xx, int yy, int zz, int x, int y, int z) {
    if (zz == 0) {
        ans = min(ans, sqr(xx - x0) + sqr(yy - y0));
    } else {
        if (-2 < dx && dx <= 0) {
            gao(dx - 1, dy, x0 + z, y0, z - zz, yy, xx, z, y, x);
        }
        if (0 <= dx && dx < 2) {
            gao(dx + 1, dy, x0 - x, y0, zz, yy, x - xx, z, y, x);
        }
        if (-2 < dy && dy <= 0) {
            gao(dx, dy - 1, x0, y0 + z, xx, z - zz, yy, x, z, y);
        }
        if (0 <= dy && dy < 2) {
            gao(dx, dy + 1, x0, y0 - y, xx, zz, y - yy, x, z, y);
        }
    }
}

int main() {
    int x, y, z, x0, y0, z0, xx, yy, zz;

    while (scanf("%d%d%d%d%d%d%d%d%d", &x, &y, &z, &x0, &y0, &z0, &xx, &yy, &zz) != EOF) {
        ans = 0x77777777;
        if (z0 != 0 && z0 != z) {
            if (x0 == 0 || x0 == x) {
                swap(x, z);
                swap(x0, z0);
                swap(xx, zz);
            } else {
                swap(y, z);
                swap(y0, z0);
                swap(yy, zz);
            }
        }
        if (z0 != 0) {
            z0 = z - z0;
            zz = z - zz;
        }
        gao(0, 0, x0, y0, xx, yy, zz, x, y, z);
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//365   2010-07-05 23:17:26     Accepted    1025    C++     0   180     anotherpeg  Source

// 2012-09-30 23:39:49 | Accepted | 1321 | C++ | 0 | 180 | watashi | Source

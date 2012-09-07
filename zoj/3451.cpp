#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cassert>

const int WIDTH = 68;
const int LENGTH = 105;
const double GW = 7.32;
const double GH = 2.44;
const double GLEFT = (WIDTH - GW) / 2;
const double GRIGHT = (WIDTH + GW) / 2;
const double EPS = 1e-8;
const double GRAVITY = 9.80665;
const double LIMIT = 4.0 / 3.0;

// x > 0
// y > 0
// v > 0
// dz > 0
bool gao(double x, double y, double v, double dx, double dy, double dz) {
    // 方向错误
    if (dy >= 0) {
        return false;
    }

    v /= sqrt(dx * dx + dy * dy + dz * dz);
    dx *= v;
    dy *= v;
    dz *= v;

    double t = -y / dy;
    double xx = x + dx * t;

    // 角度错误
    assert(fabs(xx - GLEFT) > EPS && fabs(xx - GRIGHT) > EPS);
    if (xx <= GLEFT || xx >= GRIGHT) {
        return false;
    }

    // 地滚球
    if (dz == 0) {
        return true;
    }

    // 力量不足
    assert(fabs(t - LIMIT * (2 * dz / GRAVITY)) > EPS);
    if (t > LIMIT * (2 * dz / GRAVITY)) {
        return false;
    }

    double tt, zz;
    while (true) {
        // 最高高度足够低(optional)
        if (0.5 * dz * dz / GRAVITY < GH) {
            return true;
        }
        tt = dz / GRAVITY;

        // 上升阶段
        t = -y / dy;
        if (t <= tt) {
            zz = dz * t - 0.5 * GRAVITY * t * t;
            break;
        }
        y += tt * dy;

        // 下降阶段
        t = -y / dy;
        if (t <= tt) {
            zz = 0.5 * dz * dz / GRAVITY - 0.5 * GRAVITY * t * t;
            break;
        }
        y += tt * dy;

        // 下一次弹起
        dy /= 2;
        dz /= 2;
    }
    assert(fabs(zz - GH) > EPS);
    return zz < GH;
}

int main() {
    int ri = 0, n;
    double x, y, v, dx, dy, dz;

    while (scanf("%lf%lf", &x, &y) != EOF) {
        scanf("%d", &n);
        printf("Case #%d:\n", ++ri);
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf%lf", &v, &dx, &dy, &dz);
            printf("Shot %d: ", i + 1);
            puts(gao(x, y, v, dx, dy, dz) ? "yes" : "no");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//604   2010-12-23 19:14:25     Accepted    G   C++     170     180     watashi@Zodiac  Source

// 2012-09-07 15:57:24 | Accepted | 3451 | C++ | 150 | 180 | watashi | Source

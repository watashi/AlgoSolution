#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int sx, sy, ex, ey;
int minx, maxx, miny, maxy, h;

/**/

inline int sign(int x)
{
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

inline int xmult(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - y1 * x2;
}

inline bool sameside(int x1, int y1, int x2, int y2, int xa, int ya, int xb, int yb)
{
    int x = xa - xb, y = ya - yb;
    return sign(xmult(x1 - xb, y1 - yb, x, y)) * sign(xmult(x2 - xb, y2 - yb, x, y)) > 0;
}

inline bool diffside(int x1, int y1, int x2, int y2, int xa, int ya, int xb, int yb)
{
    int x = xa - xb, y = ya - yb;
    return sign(xmult(x1 - xb, y1 - yb, x, y)) * sign(xmult(x2 - xb, y2 - yb, x, y)) < 0;
}

inline bool intersect(int x1, int y1, int x2, int y2, int xa, int ya, int xb, int yb)
{
    return diffside(x1, y1, x2, y2, xa, ya, xb, yb) &&
            diffside(xa, ya, xb, yb, x1, y1, x2, y2);
}

/**/

inline double dis(int x1, int y1, int x2, int y2)
{
    return hypot(x1 - x2, y1 - y2);
}

double distoseg(int xx, int yy, int x1, int y1, int x2, int y2)
{
    int x = xx + y1 - y2, y = yy + x2 - x1;

    if (sameside(x1, y1, x2, y2, x, y, xx, yy)) {
        return min(dis(x1, y1, xx, yy), dis(x2, y2, xx, yy));
    }
    else {
        return fabs(xmult(xx - x2, yy - y2, x1 - x2, y1 - y2) / dis(x1, y1, x2, y2));
    }
}

/**/

inline bool inRect(int x, int y)
{
    return minx <= x && x <= maxx && miny <= y && y <= maxy;
}

inline double getR(int h, double d)
{
    if (d <= h) {
        return d;
    }
    else {
        return (h * h + d * d) / (2 * h);
    }
}

double gao()
{
    static const int n[4] = {1, 2, 3, 0};
    static int p[4][2];
    double ret = 1024.0;

    if (inRect(sx, sy) || inRect(ex, ey)) {
        return 0.0;
    }
    p[0][0] = minx, p[0][1] = miny;
    p[1][0] = minx, p[1][1] = maxy;
    p[2][0] = maxx, p[2][1] = maxy;
    p[3][0] = maxx, p[3][1] = miny;
    for (int i = 0; i < 4; i++) {
        if (intersect(sx, sy, ex, ey, p[i][0], p[i][1], p[n[i]][0], p[n[i]][1])) {
            return 0.0;
        }
    }
    for (int i = 0; i < 4; i++) {
        /* ret <?= getR(h, distoseg(sx, sy, p[i][0], p[i][1], p[n[i]][0], p[n[i]][1])); */ /* auto fix <?= */
        ret = ret < getR(h, distoseg(sx, sy, p[i][0], p[i][1], p[n[i]][0], p[n[i]][1])) ? ret : getR(h, distoseg(sx, sy, p[i][0], p[i][1], p[n[i]][0], p[n[i]][1]));
        /* ret <?= getR(h, distoseg(ex, ey, p[i][0], p[i][1], p[n[i]][0], p[n[i]][1])); */ /* auto fix <?= */
        ret = ret < getR(h, distoseg(ex, ey, p[i][0], p[i][1], p[n[i]][0], p[n[i]][1])) ? ret : getR(h, distoseg(ex, ey, p[i][0], p[i][1], p[n[i]][0], p[n[i]][1]));
    }
    if (sx != ex || sy != ey) {
        for (int i = 0; i < 4; i++) {
            /* ret <?= getR(h, distoseg(p[i][0], p[i][1], sx, sy, ex, ey)); */ /* auto fix <?= */
            ret = ret < getR(h, distoseg(p[i][0], p[i][1], sx, sy, ex, ey)) ? ret : getR(h, distoseg(p[i][0], p[i][1], sx, sy, ex, ey));
        }
    }

    return ret;
}

int main()
{
    int n;
    double ans;

    while (scanf("%d", &n) != EOF && n > 0) {
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        ans = 1024.0;   // according to description
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d%d", &minx, &miny, &maxx, &maxy, &h);
            /* ans <?= gao(); */ /* auto fix <?= */
            ans = ans < gao() ? ans : gao();
            //printf("%.6lf\n", ans);
        }
        printf("%.6lf\n", ans);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3041407   2008-08-19 00:19:35     Accepted    3027    C++     00:00.10    448K    Re:ReJudge

/*
Rank    Submit time     Run time    Run memory      Language    User
1   2008-08-17 13:34:17     00:00.10    408K    C++     ecust001
2   2008-08-19 00:19:35     00:00.10    448K    C++     Re:ReJudge
3   2008-08-18 15:08:32     00:00.11    416K    C++     BUPT-[yicou]
4   2008-08-18 10:01:33     00:00.11    848K    C++     ACRabbit
5   2008-08-17 19:54:24     00:00.12    852K    C++     xay
6   2008-08-17 14:18:46     00:00.12    856K    C++     Zodiac
7   2008-08-17 15:03:03     00:00.12    856K    C++     dzs
8   2008-08-17 22:01:07     00:00.13    412K    C++     longpo?
9   2008-08-17 21:34:08     00:00.14    408K    C++     long1
10  2008-08-17 14:01:01     00:00.18    864K    C++     UESTC08P09
11  2008-08-18 14:13:50     00:00.78    452K    C++     ChaeYeon
12  2008-08-18 16:13:41     00:00.80    896K    C++     KISS_fish
*/

// 2012-09-07 13:54:54 | Accepted | 3027 | C++ | 50 | 180 | watashi | Source

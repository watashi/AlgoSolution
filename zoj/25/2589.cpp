/*
Euler characteristic
http://en.wikipedia.org/wiki/Euler_characteristic
χ=V-E+F
*/

#include <cstdlib> // auto fix CE
#include <set>
#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

const double eps = 1e-8;

struct Point {
    double x, y;
};

inline bool operator<(const Point& lhs, const Point& rhs) {
    if (fabs(lhs.x - rhs.x) > 1e-8) {
        return lhs.x < rhs.x;
    } else if (fabs(lhs.y - rhs.y) > 1e-8) {
        return lhs.y < rhs.y;
    } else {
        return false;
    }
}

inline double sqr(double x) {
    return x * x;
}

inline double dis(const Point& lhs, const Point& rhs) {
    return hypot(lhs.x - rhs.x, lhs.y - rhs.y);
}

// |dx'|   |dx|   |cosa -sina|
// |   | = |  | * |          |
// |dy'|   |dy|   |sina  cosa|

bool intersection(const Point& o1, double r1, const Point& o2, double r2, Point& p1, Point& p2) {
    double d = dis(o1, o2);
    if (d < fabs(r1 - r2) - eps || d > r1 + r2 + eps) {
        return false;
    }
    double cosa = (sqr(r1) + sqr(d) - sqr(r2)) / (2 * r1 * d);
    double sina = sqrt(max(0., 1. - sqr(cosa)));
    p1 = p2 = o1;
    p1.x += r1 / d * ((o2.x - o1.x) * cosa + (o2.y - o1.y) * -sina);
    p1.y += r1 / d * ((o2.x - o1.x) * sina + (o2.y - o1.y) * cosa);
    p2.x += r1 / d * ((o2.x - o1.x) * cosa + (o2.y - o1.y) * sina);
    p2.y += r1 / d * ((o2.x - o1.x) * -sina + (o2.y - o1.y) * cosa);
    return true;
}

int main() {
    int re, n, f;
    bool w[64][64], v[64];
    double r[64];
    Point a, b, o[64];
    set<Point> pp, p[64];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        pp.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf", &o[i].x, &o[i].y, &r[i]);
            p[i].clear();
            v[i] = false;
            w[i][i] = true;
            for (int j = 0; j < i; ++j) {
                if (intersection(o[i], r[i], o[j], r[j], a, b)) {
                    pp.insert(a); p[i].insert(a); p[j].insert(a);
                    pp.insert(b); p[i].insert(b); p[j].insert(b);
                    w[i][j] = w[j][i] = true;
                } else {
                    w[i][j] = w[j][i] = false;
                }
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    w[i][j] |= w[i][k] & w[k][j];
                }
            }
        }
        f = 1;
        for (int i = 0; i < n; ++i) {
            f += p[i].size();
            if (!v[i]) {
                ++f;
                for (int j = 0; j < n; ++j) {
                    v[j] |= w[i][j];
                }
            }
        }
        f -= pp.size();
        printf("%d\n", f);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1832251   2009-04-13 16:42:17     Accepted    2589    C++     20  440     watashi@Zodiac

// 2012-09-07 15:41:17 | Accepted | 2589 | C++ | 20 | 444 | watashi | Source

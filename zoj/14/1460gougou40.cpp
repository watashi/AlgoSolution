#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <set>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cstdio>

using namespace std;

const double WH = 1000;
const double EPS = 1e-6;

struct Point {
    double x, y;
};

bool operator<(const Point& lhs, const Point& rhs) {
    return (lhs.x < rhs.x - EPS) || (lhs.x < rhs.x + EPS && lhs.y < rhs.y - EPS);
}

bool intersect(const Point& a, const Point& b, const Point& c, const Point& d) {
    return fabs((b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x)) >= EPS;
}

Point intersection(const Point& a, const Point& b, const Point& c, const Point& d) {
    double s1 = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
    double s2 = (d.x - a.x) * (d.y - c.y) - (d.y - a.y) * (d.x - c.x);
    double r = s2 / s1;
    Point p = a;
    p.x += r * (b.x - a.x);
    p.y += r * (b.y - a.y);
    return p;
}

int main() {
    int n;
    Point a[32], b[32], p;

    while (scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
            for (int j = 0; j < i; ++j) {
                if (!intersect(a[i], b[i], a[j], b[j]) && !intersect(a[i], b[i], a[i], b[j])) { // so evil
                    // throw 1; => RUNTIME ERROR
                    --i;
                    --n;
                    break;
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < n; ++i) {
            set<Point> sp;
            for (int j = 0; j < i; ++j) {
                if (intersect(a[i], b[i], a[j], b[j])) {
                    p = intersection(a[i], b[i], a[j], b[j]);
                    // printf("%d&%d @(%lf, %lf)\n", i, j, p.x, p.y);
                    if (EPS < p.x && p.x < WH - EPS && EPS < p.y && p.y < WH - EPS) {
                        sp.insert(p);
                    }
                }
            }
            ans += sp.size() + 1;
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//328   2010-06-27 20:36:21     Accepted    1034    C++     40  180     anotherpeg  Source

// 2012-09-30 23:40:47 | Accepted | 1460 | C++ | 20 | 180 | watashi | Source

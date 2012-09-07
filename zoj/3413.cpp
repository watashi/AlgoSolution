#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

//?????
//???????
const int MAXN = 100;
const double EPS = 1e-8;

struct Point {
    double x, y;
    Point() { }
    Point(double x, double y) : x(x), y(y) { }
};

inline bool zero(double x) {
    return ((x > 0 ? x : -x) < EPS);
}

inline double xmult(const Point & p1, const Point & p2, const Point & p0) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool sameSide(const Point & p1, const Point & p2, const Point & l1, const Point & l2) {
    return xmult(l1, p1, l2) * xmult(l1, p2, l2) > EPS;
}

Point intersection(const Point & u1, const Point & u2, const Point & v1, const Point & v2) {
    Point ret = u1;
    double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) / ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
    ret.x += (u2.x - u1.x) * t;
    ret.y += (u2.y - u1.y) * t;
    return ret;
}

//?????l1, l2????????side???, ??l1, l2, side???
void polygonCut(int & n, Point * p, const Point & l1, const Point & l2, const Point & side) {
    Point pp[MAXN];
    int m = 0, i;
    for (i = 0; i < n; i++) {
        if (sameSide(p[i], side, l1, l2)) {
            pp[m++] = p[i];
        }
        if (!sameSide(p[i], p[(i + 1) % n], l1, l2) && !(zero(xmult(p[i], l1, l2)) && zero(xmult(p[(i + 1) %n ], l1, l2)))) {
            pp[m++] = intersection(p[i], p[(i + 1) % n], l1, l2);
        }
    }
    for (n = i = 0; i < m; i++) {
        if (!i || !zero(pp[i].x - pp[i - 1].x) || !zero(pp[i].y - pp[i-1].y)) {
            p[n++] = pp[i];
        }
    }
    if (zero(p[n - 1].x - p[0].x) && zero(p[n - 1].y - p[0].y)) {
        n--;
    }
    if (n < 3) {
        n = 0;
    }
}

double areaPolygon(int n, const Point* p) {
    double s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        s1 += p[(i + 1) % n].y * p[i].x;
        s2 += p[(i + 1) % n].y * p[(i + 2) % n].x;
    }
    return fabs(s1 - s2)/2;
}

int main() {
    double x, y, a, b, k, l, r, ans;
    Point p[100], u, v;
    int n;

    while (scanf("%lf%lf%lf%lf%lf", &x, &y, &a, &b, &k) != EOF) {
        if (a == 0 && b == 0) {
            ans = (x + y <= k + 1e-8 ? 1 : 0);
        } else if (a == 0) {
            l = max(0.0, x + y - k);
            r = min(b, x + y + k);
            ans = (l < r ? r - l : 0.0);
            ans /= b;
        } else if (b == 0) {
            l = max(0.0, x + y - k);
            r = min(a, x + y + k);
            ans = (l < r ? r - l : 0.0);
            ans /= a;
        } else {
            n = 4;
            p[0] = Point(0, 0);
            p[1] = Point(a, 0);
            p[2] = Point(a, b);
            p[3] = Point(0, b);
            polygonCut(n, p, Point(x + y - k, 0), Point(x + y - k + 100, -100), Point(2000, 2000));
            polygonCut(n, p, Point(x + y + k, 0), Point(x + y + k + 100, -100), Point(-2000, -2000));
            ans = areaPolygon(n, p) / a / b;
        }
        printf("%.6lf\n", fabs(max(0.0, min(1.0, ans))));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//321   2010-10-05 22:27:44     Accepted    H   C++     70  180     watashi@Zodiac  Source

// 2012-09-07 15:53:20 | Accepted | 3413 | C++ | 50 | 180 | watashi | Source

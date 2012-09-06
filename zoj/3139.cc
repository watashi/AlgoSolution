#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

// °ëÆœÃæœ»
const double eps = 1e-8;

template<class T>
struct Point
{
    T x, y;
    Point() { }
    Point(T x, T y) : x(x), y(y) { }
};

template<class T>
Point<T> operator -(const Point<T>& lhs, const Point<T>& rhs)
{
    return Point<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template<class T>
T xmult(const Point<T>& lhs, const Point<T>& rhs)
{
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

template<class T>
bool left_side(const Point<T>& p, const Point<T>& f, const Point<T>& t)
{
    return xmult(t - f, p - f) > eps;
}

template<class T>
bool on_line(const Point<T>& p, const Point<T>& f, const Point<T>& t)
{
    return fabs(xmult(p - f, t - f)) < eps;
}

template<class T>
bool same_side(const Point<T>& p1, const Point<T>& p2, const Point<T>& f, const Point<T>& t)
{
    return xmult(p1 - f, t - f) * xmult(p2 - f, t - f) > eps;
}

template<class T>
Point<T> intersection(const Point<T>& a, const Point<T>& b, const Point<T>& c, const Point<T>& d)
{
    Point<T> ret = a;
    double r = xmult(a - c, c - d) / xmult(a - b, c - d);

    ret.x += (b.x - a.x) * r;
    ret.y += (b.y - a.y) * r;

    return ret;
}

// œ«¶à±ßÐÎÇÐÔÚÖ±ÏßftµÄ×ó²à£¬¶à±ßÐÎ±»žÄ±ä
// 半平面交
template<class T>
void polygonCut(int& n, Point<T> p[], const Point<T>& f, const Point<T>& t)
{
    static Point<T> pp[10240];
    int m;

    m = 0;
    for (int i = 0; i < n; i++) {
        if (left_side(p[i], f, t)) {
            pp[m++] = p[i];
        }
        if (!same_side(p[i], p[(i + 1) % n], f, t) && !(on_line(p[i], f, t) && on_line(p[(i + 1) % n], f, t))) {
            pp[m++] = intersection(p[i], p[(i + 1) % n], f, t);
        }
    }
    n = 0;
    p[n++] = pp[0];
    for (int i = 1; i < m; i++) {
        if (fabs(pp[i].x - pp[i - 1].x) > eps || fabs(pp[i].y - pp[i - 1].y) > eps) {
            p[n++] = pp[i];
        }
    }
    if (fabs(pp[0].x - pp[n - 1].x) < eps && fabs(pp[0].y - pp[n - 1].y) < eps) {
        --n;
    }
    if (n < 3) {
        n = 0;
    }
}

// end

int na, nb;
Point<double> pa[1024], pb[10240];

void getCore()
{
    nb = na;
    for (int i = 0; i < nb; i++) {
        pb[i] = pa[i];
    }
    for (int i = 1; i < na - 2; i++) {
        polygonCut(nb, pb, pa[i - 1], pa[i]);
        /*printf("%d\n", nb);
        for (int i = 0; i < nb; i++) {
            printf("%lf %lf\n", pb[i].x, pb[i].y);
        }*/
    }
}

double dist(const Point<double>& p, const Point<double>& l1, const Point<double>& l2)
{
    if (fabs(l1.x - p.x) < eps && fabs(l2.x - p.x) < eps) {
        return min(fabs(l1.y - p.y), fabs(l2.y - p.y));
    }
    else if ((l1.x - p.x) * (l2.x - p.x) > eps) {
        return 1024.0;
    }
    else {
        return fabs((l2.y - l1.y) / (l2.x - l1.x) * (p.x - l1.x) + l1.y - p.y);
    }
}

int main()
{
    int re;
    double ymax, ans;

    scanf("%d", &re);
    while (re--) {
        scanf("%d", &na);
        ymax = 0;
        for (int i = 0; i < na; i++) {
            scanf("%lf%lf", &pa[i].x, &pa[i].y);
            // ymax >?= pa[i].y;
            ymax = max(ymax, pa[i].y);
        }
        ymax += 1024.0;
        pa[na] = Point<double>(pa[na - 1].x, ymax);
        pa[na + 1] = Point<double>(pa[0].x, ymax);
        na += 2;
        getCore();


        ans = 1024.0;
        for (int i = 0; i < na - 2; i++) {
            for (int j = 0; j < nb; j++) {
                // ans <?= dist(pa[i], pb[j], pb[(j + 1) % nb]);
                ans = min(ans, dist(pa[i], pb[j], pb[(j + 1) % nb]));
            }
        }
        for (int i = 0; i < nb; i++) {
            for (int j = 1; j < na - 2; j++) {
                // ans <?= dist(pb[i], pa[j - 1], pa[j]);
                ans = min(ans, dist(pb[i], pa[j - 1], pa[j]));
            }
        }
        if (ans > 1000.0) {
            puts("IMPOSSIBLE");
        }
        else {
            printf("%.1lf\n", ans);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750163   2009-01-28 15:00:22     Accepted    3139    C++     10  512     watashi@Zodiac

// 2012-09-07 02:02:57 | Accepted | 3139 | C++ | 0 | 516 | watashi | Source

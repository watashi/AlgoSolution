#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
// Convex Hull

const double eps = 1e-8;

template<class T>
struct Point
{
    T x, y;
    Point() { }
    Point(T x, T y) : x(x), y(y) { }
};

template<class T>
bool operator <(const Point<T>& lhs, const Point<T>& rhs)
{
    return (lhs.y != rhs.y) ? lhs.y < rhs.y : lhs.x < rhs.x;
}


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

// p顺序被改变
// 由于没有mark，如果部分退化为线段时点会重复出现
// if all = true then 包含所有共线点
template<class T>
int GrahamScan(int n, Point<T> p[], Point<T> ret[], bool all = false)
{
    const double eps = all ? ::eps : -::eps;
    int sp, tmp;

    if (n < 3) {
        for (int i = 0; i < n; i++) {
            ret[i] = p[i];
        }
        return n;
    }
    sort(p, p + n);
    ret[0] = p[0];
    ret[1] = p[1];
    sp = 2;
    for (int i = 2; i < n; i++) {
        while (sp > 1 && xmult(ret[sp - 1] - ret[sp - 2], p[i] - ret[sp - 2]) > eps) {
            --sp;
        }
        ret[sp++] = p[i];
    }
    tmp = sp;
    ret[sp++] = p[n - 2];
    for (int i = n - 3; i >= 0; i--) {
        while (sp > tmp && xmult(ret[sp - 1] - ret[sp - 2], p[i] - ret[sp - 2]) > eps) {
            --sp;
        }
        ret[sp++] = p[i];
    }

    return sp - 1;
}

inline double sqr(const double& x)
{
    return x * x;
}

inline double dd(const Point<double>& a, const Point<double>& b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

double getDD(const Point<double>& a, const Point<double>& b, const Point<double>& c)
{
    double da = dd(b, c), db = dd(a, c), dc = dd(a, b);

    if (da + 1e-8 >= db + dc) return da;
    if (db + 1e-8 >= da + dc) return db;
    if (dc + 1e-8 >= da + db) return dc;

    return dc / (1.0 - sqr(da + db - dc) / (4 * da * db));
}

Point<double> pp[1024], p[1024];

int main()
{
    int n;
    double d2, tmp, ans;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &pp[i].x, &pp[i].y);
        }
        n = GrahamScan(n, pp, p);
        if (n <= 1) {
            ans = 0;
        }
        else if (n == 2) {
            ans = dd(p[0], p[1]);
        }
        else {
            ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        // ans >?= getDD(p[i], p[j], p[k]);
                        ans = max(ans, getDD(p[i], p[j], p[k]));
                    }
                }
            }
        }
        printf("%.0lf\n", ceil(sqrt(ans) / 2.0 - 1e-8) + 1e-8);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750196   2009-01-28 15:28:48     Accepted    3147    C++     0   208     watashi@Zodiac


/*
//不求凸包
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//565   2008-08-20 03:47:06     Accepted    1025    C++     120     272     watashi     Source

//求凸包
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//566   2008-08-20 03:51:21     Accepted    1025    C++     0   288     watashi     Source*/

// 2012-09-07 02:03:34 | Accepted | 3147 | C++ | 0 | 212 | watashi | Source

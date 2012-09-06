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
    Point(int x, int y) : x(x), y(y) { }
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


template<class T>
double dist(Point<T>& lhs, Point<T>& rhs)
{
    return hypot((double)(lhs.x - rhs.x), (double)(lhs.y - rhs.y));
}

Point<int> p[30003], ch[30003];

inline int increase(int i, int n)
{
    return ++i == n ? 0 : i;
}

int main(void)
{
    int n;
    double prev, next, ans;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        n = GrahamScan(n, p, ch);
        ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            prev = dist(ch[i], ch[j]);
            while ((next = dist(ch[i], ch[increase(j, n)])) > prev) {
                prev = next;
                j = increase(j, n);
            }
            if (prev > ans) {
                ans = prev;
            }
        }
        printf("%.2lf\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3028564 2008-08-09 15:18:27 Accepted 2074 C++ 00:00.14 920K Re:ReJudge
//

// 2012-09-07 01:12:11 | Accepted | 2074 | C++ | 40 | 648 | watashi | Source

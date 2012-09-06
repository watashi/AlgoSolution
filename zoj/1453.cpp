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

Point<int> p[128], ch[128];

int main(void)
{
    int n;
    double ans;

    while (scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        n = GrahamScan(n, p, ch);
        ans = hypot((double)(ch[0].x - ch[n - 1].x), (double)(ch[0].y - ch[n - 1].y));
        for (int i = 1; i < n; i++) {
            ans += hypot((double)(ch[i].x - ch[i - 1].x), (double)(ch[i].y - ch[i - 1].y));
        }
        printf("%.2lf\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3028361 2008-08-09 11:11:03 Accepted 1453 C++ 00:00.05 452K Re:ReJudge
//

// 2012-09-07 00:49:51 | Accepted | 1453 | C++ | 10 | 180 | watashi | Source

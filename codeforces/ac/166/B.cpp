#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const double EPS = 1e-8;

template<class T>
struct Point {
    T x, y;
    Point() { }
    Point(T x, T y) : x(x), y(y) { }
};

template<class T>
bool operator<(const Point<T>& lhs, const Point<T>& rhs) {
    return (lhs.y != rhs.y) ? lhs.y < rhs.y : lhs.x < rhs.x;
}

template<class T>
Point<T> operator+(const Point<T>& lhs, const Point<T>& rhs) {
    return Point<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template<class T>
Point<T> operator-(const Point<T>& lhs, const Point<T>& rhs) {
    return Point<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template<class T>
T xmult(const Point<T>& lhs, const Point<T>& rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

template<class T>
int grahamScan(int n, Point<T> p[], Point<T> ret[], bool all = false) {
    const double eps = all ? EPS : -EPS;
    int sp, tmp;

    if (n < 3) {
        for (int i = 0; i < n; i++) {
            ret[i] = p[i];
        }
        return n;
    }
    //	sort(p, p + n);
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

Point<double> p[MAXN], q[MAXN], r[MAXN], o;
pair<double, Point<double> > pp[MAXN];

int main() {
    int n, m;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &r[i].x, &r[i].y);
    }
    n = grahamScan(n, r, p);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%lf%lf", &r[i].x, &r[i].y);
    }
    m = grahamScan(m, r, q);

    o = {0, 0};
    for (int i = 0; i < n; ++i) {
        o = o + p[i];
    }
    o.x /= n;
    o.y /= n;
    for (int i = 0; i < n; ++i) {
        p[i] = p[i] - o;
        pp[i] = {atan2(p[i].y, p[i].x), p[i]};
    }
    for (int i = 0; i < m; ++i) {
        q[i] = q[i] - o;
    }
    sort(pp, pp + n);

    for (int i = 0; i < m; ++i) {
        if (fabs(q[i].x) < EPS && fabs(q[i].y) < EPS) {
            continue;
        }
        double a = atan2(q[i].y, q[i].x);
        int j = lower_bound(pp, pp + n, a,[](const pair<double, Point<double> >& lhs, double rhs){ return lhs.first < rhs; }) - pp;
        int k = j - 1;
        j = (j + n) % n;
        k = (k + n) % n;
        if (xmult(pp[j].second - pp[k].second, q[i] - pp[k].second) < EPS) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}


#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <bitset>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

inline int signum(double x) {
    if (x > EPS) {
        return 1;
    } else if (x < -EPS) {
        return -1;
    } else {
        return 0;
    }
}

struct Point{
    double x, y;
    Point() {}
    Point(double x, double y):x(x), y(y) {}
    double length() const { return hypot(x, y); }
};

Point operator+(const Point& lhs, const Point& rhs) {
    return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

Point operator-(const Point& lhs, const Point& rhs) {
    return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

Point operator*(double lhs, const Point& rhs) {
    return Point(lhs * rhs.x, lhs * rhs.y);
}

double operator/(const Point& lhs, const Point& rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

bool dotsInline(const Point& p1, const Point& p2, const Point& p3){
    return fabs((p1 - p3) / (p2 - p3)) < 0;
}

int decideSide(const Point& p1, const Point& p2, const Point& l1, const Point& l2){
    return signum((l1 - l2) / (p1 - l2)) * signum((l1 - l2) / (p2 - l2));
}

bool dotOnlineIn(const Point& p, const Point& l1, const Point& l2){
    return fabs((p - l2) / (l1 - l2)) < EPS && (l1.x - p.x) / (l2.x - p.x) < EPS && (l1.y - p.y) / (l2.y - p.y) < EPS;
}

bool intersectIn(const Point& u1, const Point& u2, const Point& v1, const Point& v2){
    if(!dotsInline(u1, u2, v1) || !dotsInline(u1, u2, v2))
        return decideSide(u1, u2, v1, v2) != 1 && decideSide(v1, v2, u1, u2) != 1;
    else
        return dotOnlineIn(u1, v1, v2) || dotOnlineIn(u2, v1, v2) || dotOnlineIn(v1, u1, u2) || dotOnlineIn(v2, u1, u2);
}

double disptoline(const Point& p, const Point& l1, const Point& l2){
    return fabs((p - l2) / (l1 - l2)) / (l1 - l2).length();
}

double disptoseg(const Point& p, const Point& l1, const Point& l2){
    Point t = Point(l1.y - l2.y, l2.x - l1.x);
    if(signum((l1 - p) / t) * signum((l2 - p) / t) > 0)
        return min((p - l1).length(), (p - l2).length());
    else
        return disptoline(p, l1, l2);
}

const int MAXN = 256;
Point a[MAXN], b[MAXN], c[MAXN];
double r[MAXN];
bitset<MAXN> lft[MAXN], rt[MAXN];

int main() {
    int re, n, m;
    Point p;
    bitset<MAXN> pre, cur;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf", &c[i].x, &c[i].y, &r[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
        }

        for (int i = 0; i < m; ++i) {
            p = .5 * (a[i] + b[i]);
            lft[i].reset();
            rt[i].reset();
            for (int j = 0; j < m; ++j) {
                lft[i].set(j, intersectIn(a[i], p, a[j], b[j]));
                rt[i].set(j, intersectIn(b[i], p, a[j], b[j]));
            }
            for (int j = 0; j < n; ++j) {
                lft[i].set(m + j, disptoseg(c[j], a[i], p) <= r[j] + EPS);
                rt[i].set(m + j, disptoseg(c[j], b[i], p) <= r[j] + EPS);
            }
        }

        cur.reset();
        for (int i = 0; i < n; ++i) {
            cur.set(m + i);
        }
        do {
            pre = cur;
            for (int i = 0; i < m; ++i) {
                if (cur.test(i)) {
                    continue;
                }
                if ((lft[i] & cur).any() && (rt[i] & cur).any()) {
                    cur.set(i);
                }
            }
        } while (cur != pre);

        puts((int)cur.count() == n + m ? "YES" : "NO");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//476   2011-04-15 01:52:29     Accepted    I   C++     170     208     watashi     Source

// 2012-09-07 16:01:59 | Accepted | 3495 | C++ | 120 | 208 | watashi | Source

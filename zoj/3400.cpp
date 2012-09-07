#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
    Point() { }
    Point(long long x, long long y) : x(x), y(y) { }
    void print(const char* p = "") {
        printf("(%lld, %lld)%s", x, y, p);
    }
};

struct Line {
    Point a, b;
    Line() { }
    Line(const Point& a, const Point& b) : a(a), b(b) { }
};

Point operator+(const Point& lhs, const Point& rhs) {
    return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

Point operator-(const Point& lhs, const Point& rhs) {
    return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

long long operator%(const Point& lhs, const Point& rhs) {
    return lhs.x * rhs.y - rhs.x * lhs.y;
}

bool operator<(const Point& lhs, const Point& rhs) {
    return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
}

bool operator<=(const Point& lhs, const Point& rhs) {
    return !(rhs < lhs);
}

bool operator<(const Line& lhs, const Line& rhs) {
    return lhs.a < rhs.a;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool isoverlap(const Line& u, const Line& v) {
    long long d;
    d = (u.a - u.b) % (v.a - v.b);
    if (d != 0) {
        return false;
    }
    d = (u.a - u.b) % (v.a - u.b);
    if (d != 0) {
        return false;
    }
    return
        (u.a <= v.a && v.a <= u.b) ||
        (u.a <= v.b && v.b <= u.b) ||
        (v.a <= u.a && u.a <= v.b) ||
        (v.a <= u.b && u.b <= v.b);
}

Line overlap(const Line& u, const Line& v) {
    return Line(min(u.a, v.a), max(u.b, v.b));
}

// u is segment & v is line
bool isintersect(const Line& u, const Line& v) {
    long long d = (u.a - u.b) % (v.a - v.b);
    if (d == 0) {
        return false;
    }
    long long t = (u.a - v.a) % (v.a - v.b);
    if (d < 0) {
        d = -d;
        t = -t;
    }
    if (t < 0 || t > d) {
        return false;
    }
    Point w = u.b - u.a;
    return w.x * t % d == 0 && w.y * t % d == 0;
}

Point intersect(const Line& u, const Line& v) {
    long long d = (u.a - u.b) % (v.a - v.b);
    long long t = (u.a - v.a) % (v.a - v.b);
    Point w = u.b - u.a;
    return u.a + Point(w.x * t / d, w.y * t / d);
}

int main() {
    int n;
    long long ans;
    Point p;
    set<Point> s;
    vector<Line> v, w;

    while (scanf("%d", &n) != EOF) {
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld%lld%lld", &v[i].a.x, &v[i].a.y, &v[i].b.x, &v[i].b.y);
            if (v[i].b < v[i].a) {
                swap(v[i].a, v[i].b);
            }
        }
        sort(v.begin(), v.end());

        w.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= (int)w.size(); ++j) {
                if (j == (int)w.size()) {
                    w.push_back(v[i]);
                    break;
                } else if (isoverlap(w[j], v[i])) {
                    w[j] = overlap(w[j], v[i]);
                    break;
                }
            }
        }
        v = w;

        ans = 0;
        for (int i = 0; i < (int)v.size(); ++i) {
//          printf("+%lld\n", gcd(llabs(v[i].b.x - v[i].a.x), llabs(v[i].b.y - v[i].a.y)) + 1);
            ans += gcd(llabs(v[i].b.x - v[i].a.x), llabs(v[i].b.y - v[i].a.y)) + 1;
            s.clear();
            for (int j = 0; j < i; ++j) {
                if (isoverlap(v[i], v[j]) || isoverlap(v[j], v[i])) {
                    throw 1;
                }
                if (isintersect(v[i], v[j]) && isintersect(v[j], v[i])) {
                    p = intersect(v[i], v[j]);
//                  p.print("\n");
                    s.insert(p);
                }
            }
            ans -= s.size();
        }

        printf("%lld\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1090  2010-07-27 15:43:31     Accepted    1133    C++     580     180     anotherpeg  Source

// 2012-09-07 15:51:52 | Accepted | 3400 | C++ | 480 | 180 | watashi | Source

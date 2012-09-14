#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cassert>
#include <cstdlib> // auto fix CE
#include <algorithm> // auto fix CE
#include <cstdlib> // auto fix CE
#include <utility>

using namespace std;

const double EPS = 1e-8;

struct Vec {
    double x, y, z;
    Vec() { }
    Vec(double x, double y, double z) : x(x), y(y), z(z) { }
    double length() const {
        return sqrt(x * x + y * y + z * z);
    }
};

Vec operator+(const Vec& lhs, const Vec& rhs) {
    return Vec(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vec operator-(const Vec& lhs, const Vec& rhs) {
    return Vec(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vec operator*(double lhs, const Vec& rhs) {
    return Vec(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

double operator*(const Vec& lhs, const Vec& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

void dump(const Vec& v) {
    printf("(%lf, %lf, %lf)", v.x, v.y, v.z);
}
/*
void assert0(const Vec& lhs, const Vec& rhs) {
    if (lhs.length() < EPS || rhs.length() < EPS) {
        return;
    }
    assert(fabs(lhs * rhs / lhs.length() / rhs.length() - 1) < EPS);
}

void assert90(const Vec& lhs, const Vec& rhs) {
    if (lhs.length() < EPS || rhs.length() < EPS) {
        return;
    }
    assert(fabs(lhs * rhs / lhs.length() / rhs.length()) < EPS);
}
*/
void vpvn(const Vec& lhs, const Vec& rhs, Vec& vp, Vec& vn) {
    if (lhs.length() < EPS) {
        vp = vn = Vec(0, 0, 0);
    } else {
        double r = lhs * rhs / lhs.length() / rhs.length();
        vp = r * lhs.length() / rhs.length() * rhs;
        vn = lhs - vp;
    }
//  assert0(vp, rhs);
//  assert90(vn, rhs);
}

int main() {
    int n;
    double m, mm, m0, v0, v0p, v0n, t;
    Vec p[64], v, vp, vn, w;

    while (scanf("%d%lf%*d%lf%lf", &n, &m, &m0, &v0) != EOF) {
        p[0] = Vec(0, 0, 0);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
        }
        v = Vec(0, 0, 0);
        t = 0;
        for (int i = 0; i < n; ++i) {
            mm = m;
            m -= m0;
            w = p[i + 1] - p[i];
            vpvn(v, w, vp, vn);
//          printf("v=");dump(v);printf(" w=");dump(v);
//          printf(" vp=");dump(vp);printf(" vn=");dump(vn);puts("");
            v0n = mm * vn.length() / m0;
            if (v0n > v0 + EPS) {
                puts("Another kind of KKV.");
                goto NEXT;
            }
            v0p = sqrt(fabs(v0 * v0 - v0n * v0n));
//          printf("v0p = %lf; =", v0p);
//          dump(m0 * v0p / w.length() * w);
//          puts("");
            v = (1 / m) * (mm * vp + m0 * v0p / w.length() * w);
            if (v * w < EPS) {
                puts("Another kind of KKV.");
                goto NEXT;
            }
//          assert0(v, w);
//          printf("v=");dump(v);
//          printf(" %lf / %lf = %lf\n", w.length(), v.length(), w.length() / v.length());
            t += w.length() / v.length();
        }
        printf("%.2lf\n", t);
NEXT:
        continue;
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1177  2010-07-30 14:59:36     Accepted    1143    C++     110     180     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//317   2010-10-05 22:25:53     Accepted    D   C++     50  180     watashi@Zodiac  Source

// 2012-09-07 15:52:48 | Accepted | 3409 | C++ | 50 | 180 | watashi | Source

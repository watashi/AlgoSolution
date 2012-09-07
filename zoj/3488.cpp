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

using namespace std;

const double EPS = 1e-4;

int main() {
    int re;
    double a, b, c, d, e, f;
    double delta, Delta;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f) == 6);
        assert(fabs(a) <= 10000);
        assert(b == 0);
        assert(fabs(c) <= 10000);
        assert(fabs(d) <= 10000);
        assert(fabs(e) <= 10000);
        assert(fabs(f) <= 10000);
        assert(fabs(a) + fabs(c) > EPS);
        assert(a == c || fabs(a - c) > EPS);
        assert(a == 0 || c == 0 || fabs(a * c) > EPS);
        delta = b * b - 4 * a * c;
        Delta = (a * c - b * b / 4) * f + b * e * d / 4 - c * d * d / 4 - a * e * e / 4;
        assert(fabs(Delta) > EPS);
        if (a == c) {
            assert(c * Delta < -EPS);
            puts("circle");
        } else if (a * c > 0) {
            assert(c * Delta < -EPS);
            puts("ellipse");
        } else if (a * c < 0) {
            puts("hyperbola");
        } else {
            puts("parabola");
        }
    }
    assert(scanf("%d", &re) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//467   2011-04-15 01:41:49     Accepted    B   C++     60  180     watashi     Source

// 2012-09-07 16:01:16 | Accepted | 3488 | C++ | 30 | 180 | watashi | Source

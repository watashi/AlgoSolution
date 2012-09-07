#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <limits>
#include <cstdlib> // auto fix CE
#include <vector>
#include <cstdlib> // auto fix CE
#include <utility>
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

// a in range [-2Pi, 2Pi] !!
// to [0, 2Pi]
inline double tostd(double a) {
    if (a < 0) {
        a += 2 * M_PI;
    }
    return a;
}

inline double diff(double a, double b) {
    double d = fabs(a - b); // [0, 2Pi]
    if (d > M_PI) {
        d = 2 * M_PI - d;
    }
    return d;
}

double gao(const vector<pair<double, int> >& a, const vector<pair<double, int> >& b,
        vector<int>& ab, double h) {
    int n = a.size(), k = -1;
    double ret = numeric_limits<double>::max();
    for (int i = 0; i < n; ++i) {
        double tmp = 0;
        for (int j = 0; j < n; ++j) {
            tmp += hypot(diff(a[j].first, b[(j + i) % n].first), h);
        }
        if (ret > tmp) {
            ret = tmp;
            k = i;
        }
    }
    for (int j = 0; j < n; ++j) {
        ab[a[j].second] = b[(j + k) % n].second;
    }
    return ret;
}

int main() {
    int n;
    double r, h, ans;
    vector<pair<double, int> > a, b;
    vector<int> ab, ba;

    while (scanf("%d%lf%lf", &n, &r, &h) != EOF) {
        a.resize(n);
        b.resize(n);
        ab.resize(n);
        ba.resize(n);
        ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &a[i].first);
            a[i].first = tostd(a[i].first);
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &b[i].first);
            b[i].first = tostd(b[i].first);
            b[i].second = i;
        }
        sort(b.begin(), b.end());
        ans += gao(a, b, ab, h / 2 / r);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &a[i].first);
            a[i].first = tostd(a[i].first);
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        ans += gao(b, a, ba, h / 2 / r);
        ans *= r;
        printf("%.4lf\n", ans);
        for (int i = 0; i < n; ++i) {
            printf("%d %d %d\n", i + 1, ab[i] + 1, ba[ab[i]] + 1);
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1816301   2009-04-03 09:52:37     Accepted    2564    C++     1800    176     watashi@Zodiac

// 2012-09-07 15:40:27 | Accepted | 2564 | C++ | 1680 | 180 | watashi | Source

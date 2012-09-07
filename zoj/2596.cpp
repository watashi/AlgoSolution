#include <cmath>
#include <cstdio>
using namespace std;

const long double PI = M_PI;
const long double EPS = 1e-8;
const int MAXN = 128;

int main() {
    bool blank = false;
    int n;
    long double s, a, ca, sa;
    long double x[MAXN], y[MAXN];

    while (scanf("%d", &n) != EOF && n > 0) {
        if (blank) {
            puts("");
        } else {
            blank = true;
        }
        s = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%Lf%Lf", &x[i], &y[i]);
            if (i > 0) {
                s = fmod(s + atan2(y[i] - y[i - 1], x[i] - x[i - 1]), 2 * PI);
            }
        }
        while (s < 0) {
            s += 2 * PI;    // !!WA!!
        }
        a = s < EPS ? 0 : (2 * PI - s) / (n - 1);
        printf("%.16Lf\n%.16Lf\n", 0.0L, a);
        ca = cos(a);
        sa = sin(a);
        for (int i = 0; i < n; ++i) {
            printf("%.16Lf %.16Lf\n", ca * x[i] - sa * y[i], sa * x[i] + ca * y[i]);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2175118   2010-04-24 14:18:32     Accepted    2596    C++     1050    176     watashi@Zodiac

// 2012-09-07 15:42:00 | Accepted | 2596 | C++ | 1200 | 180 | watashi | Source

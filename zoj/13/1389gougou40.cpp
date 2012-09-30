#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 65536;
const double EPS = 1e-4;

// can be improved to O(nlg(n)), not O(nlg((r-l)/eps))

int main() {
    int re, n;
    double l, r, v, w, d, b[MAXN], h[MAXN], s[MAXN];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        l = 1e100;
        r = 0;
        v = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf%lf", &b[i], &h[i], &w, &d);
            s[i] = w * d;
            v += s[i] * h[i];
            l = min(l, b[i]);
            r = max(r, b[i] + h[i]);
        }
        scanf("%lf", &w);
        if (w > v) {
            puts("OVERFLOW");
            continue;
        }

        while (r - l > EPS) {
            v = 0;
            d = (l + r) / 2;
            for (int i = 0; i < n && v < w; ++i) {
                if (b[i] < d) {
                    v += s[i] * min(h[i], d - b[i]);
                }
            }
            if (v < w) {
                l = d;
            } else {
                r = d;
            }
        }
        printf("%.2lf\n", (l + r) / 2);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//348   2010-06-29 05:20:41     Accepted    1027    C++     1370    180     anotherpeg  Source

// 2012-09-30 23:40:02 | Accepted | 1389 | C++ | 850 | 180 | watashi | Source

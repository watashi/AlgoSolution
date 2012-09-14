#include <cstdio>
#include <utility>

using namespace std;

int main() {
    int re, n, m, k1, k2, k3, a, b, c;
    double p[20];
    pair<double, double> y[512];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d%d%d%d%d", &n, &k1, &k2, &k3, &a, &b, &c);
        m = k1 + k2 + k3;
        for (int i = 0; i <= m; ++i) {
            p[i] = 0;
        }
        p[0] = 1.0 / k1 / k2 / k3;
        for (int i = 1; i <= k1; ++i) {
            for (int j = 1; j <= k2; ++j) {
                for (int k = 1; k <= k3; ++k) {
                    p[i + j + k] += 1;
                }
            }
        }
        p[a + b + c] -= 1;
        for (int i = 3; i <= m; ++i) {
            p[i] *= p[0];
        }

        for (int i = n; i >= 0; --i) {
            y[i] = make_pair(p[0], 1);
            for (int j = 3; j <= m && i + j <= n; ++j) {
                y[i].first += p[j] * y[i + j].first;
                y[i].second += p[j] * y[i + j].second;
            }
        }
        printf("%.20lf\n", y[0].second / (1 - y[0].first));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2172514   2010-04-21 23:47:58     Accepted    3329    C++     0   184     watashi@Zodiac

// 2012-09-07 02:08:27 | Accepted | 3329 | C++ | 0 | 180 | watashi | Source

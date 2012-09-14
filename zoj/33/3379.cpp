#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 32768;
const double M_TAU = 2 * M_PI;

double x[MAXN], y[MAXN];

int main() {
    int n, ans;
    double a, aa, x, y, z, t, d;

    while (scanf("%d%lf", &n, &a) != EOF) {
        vector<pair<double, double> > rng;
        priority_queue<double, vector<double>, greater<double> > pq;

        assert(0 <= n && n <= 30000);
        assert(0.1 <= a && a <= 10);
        aa = a * a;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", ::x + i);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%lf", ::y + i);
        }
        for (int i = 0; i < n; ++i) {
            x = ::x[i];
            y = ::y[i];
            z = x * x + y * y;
            assert(z > 0);
            t = atan2(y, x);
            d = sqrt((sqrt(1 + 4 * aa * z) - 1) / (2 * aa));
            d = atan2(1, a * d);
            rng.push_back(make_pair(remainder(t - d, M_TAU), remainder(t + d, M_TAU)));
            if (rng.back().first > rng.back().second) {
                pq.push(rng.back().second);
                rng.back().second += M_TAU;
            }
        }

        ans = (int)pq.size();
        sort(rng.begin(), rng.end());
        for (vector<pair<double, double> >::const_iterator it = rng.begin(); it != rng.end(); ++it) {
            pq.push(it->second);
            while (!pq.empty() && pq.top() < it->first) {
                pq.pop();
            }
            ans = max(ans, (int)pq.size());
        }
        printf("%d daze\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1245  2010-07-31 20:31:23     Accepted    1146    C++     460     1720    anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//220   2010-08-12 15:13:32     Accepted    marisa  C++     280     1716    watashi@Zodiac  Source

// 2012-09-07 15:50:36 | Accepted | 3379 | C++ | 270 | 1720 | watashi | Source

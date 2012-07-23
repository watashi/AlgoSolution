#include <cmath>
#include <cctype>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const double EPS = 1e-8;

struct Point {
    int x, y;
    Point() { }
    Point(int x, int y): x(x), y(y) { }
    double arg() const { return atan2(y, x); }
    int abs2() const { return x * x + y * y; }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
} p[MAXN], q;

pair<double, int> v[MAXN + MAXN];

int main() {
    int re, n;
    int ans = 0.0;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        ans = 0;
        if (n > 4) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    ans = max(ans, (p[i] - p[j]).abs2());
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                int m = 0;
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        q = p[j] - p[i];
                        v[m++] = make_pair(q.arg(), q.abs2());
                    }
                }
                sort(v, v + m);
                for (int j = 0; j < m; ++j) {
                    v[m + j] = v[j];
                    v[m + j].first += 2 * M_PI;
                }
                for (int j = 1; j < m + m - 1; ++j) {
                    if (v[j].first < v[j - 1].first + M_PI && v[j].first > v[j + 1].first - M_PI) {
                        ans = max(ans, max(v[j - 1].second, v[j + 1].second));
                    }
                }
            }
        }
        printf("%.10lf\n", sqrt(ans));
    }

    return 0;
}


#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXX = 64;
const int MAXY = 64 * 64;

struct Hungray {
    int nx, ny, mx[MAXX], my[MAXY];
    vector<int> e[MAXX];

    bool mark[MAXX];

    void init(int nx, int ny) {
        this->nx = nx;
        this->ny = ny;
        for (int i = 0; i < nx; ++i) {
            e[i].clear();
        }
    }

    void add(int a, int b) {
        e[a].push_back(b);
    }

    bool augment(int i) {
        if (!mark[i]) {
            mark[i] = true;
            for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
                if (my[*j] == -1 || augment(my[*j])) {
                    mx[i] = *j;
                    my[*j] = i;
                    return true;
                }
            }
        }
        return false;
    }

    int gao() {
        int ret = 0;
        fill(mx, mx + nx, -1);
        fill(my, my + ny, -1);
        for (int i = 0; i < nx; ++i) {
            fill(mark, mark + nx, false);
            if (augment(i)) {
                ++ret;
            }
        }
        return ret;
    }
};

Hungray h;

#define X(i) (i)
#define Y(i, j) (m + i * m + j)
#define S() (m + n * m)
#define T() (m + n * m + 1)

int main() {
    int n, m;
    double t0, t1, t2, v, l, r;
    double sx[64], sy[64], tx[64], ty[64], d[64][64];

    while (scanf("%d%d%lf%lf%lf", &n, &m, &t1, &t2, &v) != EOF) {
        t1 /= 60;
        for (int i = 0; i < m; ++i) {
            scanf("%lf%lf", &sx[i], &sy[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &tx[i], &ty[i]);
        }
        l = r = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = hypot(sx[i] - tx[j], sy[i] - ty[j]) / v;
                r = max(r, d[i][j]);
            }
        }

        l = 0;
        r += m * (t1 + t2) + 100;
        const double rr = r;
        while (r - l > 1e-8) {
            const double t = (l + r) / 2;
            h.init(m, n * m);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    t0 = 0;
                    for (int k = 0; k < m; ++k) {
                        t0 += t1;
                        if (t0 + d[i][j] > t) {
                            break;
                        } else {
                            h.add(i, j * m + k);
                        }
                        t0 += t2;
                    }
                }
            }
            if (h.gao() == m) {
                r = t;
            } else {
                l = t;
            }
        }
        if (r == rr) {
            throw 1;
        }
        printf("%.6lf\n", (l + r) / 2);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//591   2010-07-16 19:54:40     Accepted    1079    C++     40  596     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//689   2011-01-30 14:21:59     Accepted    D   C++     20  596     watashi@ArcOfDream  Source

// 2012-09-07 15:58:19 | Accepted | 3460 | C++ | 20 | 596 | watashi | Source

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

struct Lemming {
    int m, i;
    double v;
    bool operator<(const Lemming& o) const {
        return m < o.m || (m == o.m && v > o.v);
    }
} a[MAXN];

vector<int> v, w;

int main() {
    int n, m, h;
    double l, r, t;

    scanf("%d%d%d", &n, &m, &h);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].m);
        a[i].i = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &a[i].v);
        a[i].v = 1 / a[i].v;
    }
    sort(a, a + n);

    l = 0;
    r = 1e9;
    for (int k = 0; k < 100; ++k) {
        t = (l + r) / 2;
        v.clear();
        for (int i = 0; i < n && (int)v.size() < m; ++i) {
            if (((int)v.size() + 1) * a[i].v <= t) {
                v.push_back(i);
            }
        }
        if ((int)v.size() < m) {
            l = t;
        } else {
            r = t;
            w.swap(v);
        }
    }

    for (int i: w) {
        printf("%d ", a[i].i + 1);
    }

    return 0;
}


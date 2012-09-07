#include <map>
#include <cstdio>
#include <utility>
#include <cassert>
#include <algorithm>

using namespace std;

#define L(p) ((p) << 1)
#define R(p) (((p) << 1) ^ 1)

const int inf = 1000000000;

struct SegmentTree {
    int m;
    int a[65536];

    void init(int n, int d) {
        m = 1;
        while (m < n) {
            m <<= 1;
        }
        for (int i = 0; i < n; ++i) {
            a[m + i] = i * d;
        }
        for (int i = n; i < m; ++i) {
            a[m + i] = -inf;
        }
        for (int i = m - 1; i > 0; --i) {
            a[i] = max(a[L(i)], a[R(i)]);
        }
    }

    void set(int i, int v) {
        i += m;
        do {
            a[i] = v;
            v = max(v, a[i ^ 1]);
            i >>= 1;
        } while (i > 0);
    }

    int get(int p, int pl, int pr, int l, int r) {
        if (pl == l && pr == r) {
            return a[p];
        } else {
            int pm = (pl + pr) / 2;
            if (r <= pm) {
                return get(L(p), pl, pm, l, r);
            } else if (pm <= l) {
                return get(R(p), pm, pr, l, r);
            } else {
                return max(
                        get(L(p), pl, pm, l, pm),
                        get(R(p), pm, pr, pm, r));
            }
        }
    }

    int get(int l, int r) {
        // l = max(0, l);
        // r = min(m, r);
        return get(1, 0, m, l, r);
    }
};

SegmentTree lst, rst;
pair<pair<int, int>, int> v[65536];

int main() {
    int w, s, n, a, b, c;

    while (scanf("%d%d%d%d%d%d", &w, &s, &n, &a, &b, &c) != EOF) {
        assert(1 <= w && w <= 30000);   // 1 <= w <= 30000
        assert(1 <= s && s <= 900000000);   // 1 <= s <= 900000000
        assert(0 <= n && n <= 60000);   // 0 <= n <= 60000
        assert(0 <= a && a <= 10);  // 0 <= a <= 10
        assert(0 <= b && b <= 100000000);   // 0 <= b <= 100000000
        assert(0 <= c && c <= 1000000000);  // 0 <= c <= 1000000000
        for (int i = 0; i < n; ++i) {
            assert(scanf("%d%d%d", &v[i].first.second, &v[i].first.first, &v[i].second) == 3);
            assert(0 <= v[i].first.second && v[i].first.second < w);// 0 <= x < w
            assert(0 <= v[i].first.first && v[i].first.first < s);  // 0 <= y < s
            assert(-10000 < v[i].second && v[i].second < 10000 && v[i].second != 0);    // 0 < |z| < 10000
        }
        sort(v, v + n);
        for (int i = 1; i < n; ++i) {
            assert(v[i].first != v[i - 1].first);   // if i != j, then (x_i, y_i) != (x_j, y_j)
        }
        lst.init(w, +a);
        rst.init(w, -a);

        int p = 0;
        while (p < n) {
            map<int, int> mp;
            int y = v[p].first.first;
            while (p < n && v[p].first.first == y) {
                int x = v[p].first.second;
                int z = v[p].second;
                if (z != 0) {
                    mp[x] = z;
                    if (z < 0) {
                        if (x - 1 >= 0) {
                            mp[x - 1];
                        }
                        if (x + 1 < w) {
                            mp[x + 1];
                        }
                    }
                }
                ++p;
            }
            for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
                it->second += max(
                        lst.get(0, it->first + 1) - a * it->first,
                        rst.get(it->first, w) + a * it->first);
            }
            for (map<int, int>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
                lst.set(it->first, it->second + a * it->first);
                rst.set(it->first, it->second - a * it->first);
            }
        }

        int ans = -inf;
        for (int i = 0; i < w; ++i) {
            ans = max(ans, lst.a[lst.m + i] - a * i);
            ans = max(ans, rst.a[rst.m + i] + a * i);
        }
        ans += b + c;
        printf("%d\n", ans);
    }

    return 0;
}

// 2012-09-07 15:45:48 | Accepted | 3227 | C++ | 1190 | 1460 | watashi | Source

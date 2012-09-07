#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;

#define L(p) ((p) << 1)
#define R(p) (L(p) ^ 1)

struct SegTree {
    int m;
    int a[2 * MAXN];

    void init(int n) {
        m = 1;
        while (m < n) {
            m <<= 1;
        }
        fill(a, a + 2 * m, 0);
    }

    int get(int i) {
        return a[i + m];
    }

    void update(int i, int v) {
        i += m;
        while (i > 0) {
            a[i] = v;
            v = max(v, a[i ^ 1]);
            i >>= 1;
        }
    }

    int query(int p, int pl, int pr, int l, int r) {
        if (l == pl && r == pr) {
            return a[p];
        } else {
            int pm = (pl + pr) / 2;
            if (r <= pm) {
                return query(L(p), pl, pm, l, r);
            } else if (pm <= l) {
                return query(R(p), pm, pr, l, r);
            } else {
                return max(
                        query(L(p), pl, pm, l, pm),
                        query(R(p), pm, pr, pm, r));
            }
        }
    }

    int query(int l, int r) {
        return query(1, 0, m, l, r);
    }
};

SegTree st;
int a[1 << 17], mp[1 << 17];

int main() {
    int n, d, m, x;

    while (scanf("%d%d", &n, &d) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        copy(a, a + n, mp);
        sort(mp, mp + n);
        m = unique(mp, mp + n) - mp;
        st.init(m);
        for (int i = 0; i < n; ++i) {
            x = st.query(
                    lower_bound(mp, mp + m, a[i] - d) - mp,
                    upper_bound(mp, mp + m, a[i] + d) - mp);
            st.update(lower_bound(mp, mp + m, a[i]) - mp, x + 1);
        }
        printf("%d\n", st.query(0, m));
    }

    return 0;
}

// 2012-09-07 15:47:32 | Accepted | 3349 | C++ | 640 | 2228 | watashi | Source

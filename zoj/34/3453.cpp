#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;

inline int L(int i) { return i << 1; }
inline int R(int i) { return L(i) ^ 1; }

struct SegTree {
    int m;
    int x[MAXN << 1], y[MAXN << 1];

    void init(int n) {
        m = 1;
        while (m < n) {
            m <<= 1;
        }
        fill(x, x + m + m, 0);
        fill(y, y + m + m, 0);
    }

    void build() {
        for (int i = m - 1; i > 0; --i) {
            x[i] = max(x[L(i)], x[R(i)]) + y[i];
        }
    }

    void _add(int p, int pl, int pr, int l, int r) {
        if (pl == l && pr == r) {
            ++x[p];
            ++y[p];
        } else {
            int pm = (pl + pr) / 2;
            if (r <= pm) {
                _add(L(p), pl, pm, l, r);
            } else if (pm <= l) {
                _add(R(p), pm, pr, l, r);
            } else {
                _add(L(p), pl, pm, l, pm);
                _add(R(p), pm, pr, pm, r);
            }
            x[p] = max(x[L(p)], x[R(p)]) + y[p];
        }
    }

    void add(int l, int r) {
        _add(1, 0, m, l, r);
    }

    void set(int l) {
        int p = 1, pl = 0, pr = m, yy = 0;
        while (pr - pl > 1) {
            int pm = (pl + pr) / 2;
            yy += y[p];
            if (l < pm) {
                pr = pm;
                p = L(p);
            } else {
                pl = pm;
                p = R(p);
            }
        }
        x[p] = 1 - yy;
        y[p] = 0;
        while ((p >>= 1) > 0) {
            x[p] = max(x[L(p)], x[R(p)]) + y[p];
        }
    }

    int gao(int v) {
        int p = 1, pl = 0, pr = m, yy = 0;
        while (pr - pl > 1) {
            int pm = (pl + pr) / 2;
            yy += y[p];
            if (x[R(p)] + yy < v) {
                pr = pm;
                p = L(p);
            } else {
                pl = pm;
                p = R(p);
            }
        }
        return p - m;
    }
} st;

int a[MAXN], b[MAXN];

int main() {
    int n, m, x, y;

    while (scanf("%d", &n) != EOF) {
        st.init(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &st.x[st.m + i], &a[i], &b[i]);
            --a[i];
        }
        st.build();
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &x);
            if (st.x[1] < x) {
                st.add(0, n);
                continue;
            }
            y = st.gao(x);
            st.set(y);
            st.add(a[y], b[y]);
        }
        printf("%d\n", st.x[1]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//606   2010-12-23 19:22:11     Accepted    I   C++     310     3252    watashi@Zodiac  Source

// 2012-09-07 15:57:36 | Accepted | 3453 | C++ | 300 | 3252 | watashi | Source

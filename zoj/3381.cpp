#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN = 65536;

struct SegTree {
    int m;
    long long a[MAXN << 2];

    inline int L(int p) { return p << 1; }
    inline int R(int p) { return L(p) ^ 1; }

    void init(int n) {
        m = 1;
        while (m < n) {
            m <<= 1;
        }
        fill(a, a + m + m, 0);
    }

    void update(int i, long long v) {
        i += m;
        while (i > 0) {
            v = max(a[i], v);
            a[i] = v;
            i >>= 1;
        }
    }

    long long query(int p, int pl, int pr, int l, int r) {
        if (pl == l && pr == r) {
            return a[p];
        } else {
            int pm = (pl + pr) >> 1;
            if (r <= pm) {
                return query(L(p), pl, pm, l, r);
            } else if (pm <= l) {
                return query(R(p), pm, pr, l, r);
            } else {
                return max(query(L(p), pl, pm, l, pm), query(R(p), pm, pr, pm, r));
            }
        }
    }

    long long query(int i, int l, int r) {
        l += i;
        r += i;
        if (l >= m) {
            return 0;
        } else {
            return query(1, 0, m, l, min(m, r));
        }
    }
} st;

int s[MAXN], x[MAXN], y[MAXN];

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        assert(0 < n && n < 50000);
        for (int i = 0; i < n; ++i) {
            assert(scanf("%d%d%d", &s[i], &x[i], &y[i]) == 3);
            assert(s[i] > 0 && x[i] > 0 && y[i] > 0);
            assert(x[i] < y[i]);
        }
        st.init(n);
        for (int i = n - 1; i >= 0; --i) {
            st.update(i, st.query(i, x[i], y[i]) + s[i]);
        }
        assert(st.query(0, 0, 1) == (int)st.query(0, 0, 1));
        printf("%lld\n", st.query(0, 0, 1));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//317   2010-06-27 07:51:12     Accepted    1059    C++     400     2996    anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//223   2010-08-12 15:16:51     Accepted    reimu   C++     310     2992    watashi@Zodiac  Source

// 2012-09-07 15:50:58 | Accepted | 3381 | C++ | 220 | 2996 | watashi | Source

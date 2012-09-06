#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 65536;

struct SegTree {
    int m, c[MAXN << 1], d[MAXN << 1];
    bool l[MAXN << 1], r[MAXN << 1];
    inline int L(int i) { return i << 1; }
    inline int R(int i) { return (i << 1) ^ 1; }

    void init(int n) {
        m = 1;
        while (m < n) {
            m <<= 1;
        }
        fill(c, c + m + m, 1);
        fill(d, d + m + m, 0);
        fill(l, l + m + m, true);
        fill(r, r + m + m, true);
        if (n < m) {
            add(n, m, 1);   // !!WA!!
        }
    }

    void add(int p, int pl, int pr, int tl, int tr, int td) {
        if (pl == tl && pr == tr) {
            d[p] += td;
        } else {
            int pm = (pl + pr) / 2;
            if (tr <= pm) {
                add(L(p), pl, pm, tl, tr, td);
            } else if (pm <= tl) {
                add(R(p), pm, pr, tl, tr, td);
            } else {
                add(L(p), pl, pm, tl, pm, td);
                add(R(p), pm, pr, pm, tr, td);
            }
        }
        if (d[p] > 0) {
            c[p] = 0;
            l[p] = r[p] = false;
        } else if (p >= m) {
            c[p] = 1;
            l[p] = r[p] = true;
        } else {
            c[p] = c[L(p)] + c[R(p)];
            if (r[L(p)] && l[R(p)]) {
                --c[p];
            }
            l[p] = l[L(p)];
            r[p] = r[R(p)];
        }
    }

    void add(int l, int r, int v) {
        add(1, 0, m, l, r, v);
    }
} st;

char op[MAXN];
int l[MAXN], r[MAXN];

int main() {
    int re, n, m;
    map<int, int> mp;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        mp.clear();
        mp[0];
        mp[n];
        for (int i = 0; i < m; ++i) {
            scanf(" %c%d%d", &op[i], &l[i], &r[i]);
            mp[l[i]];
            mp[++r[i]];
        }
        n = -1;
        for (map<int, int>::iterator i = mp.begin(); i != mp.end(); ++i) {
            i->second = ++n;
        }

        printf("Case #%d:\n", ri);
        st.init(n);
        for (int i = 0; i < m; ++i) {
            st.add(mp[l[i]], mp[r[i]], op[i] == 'p' ? 1 : -1);
            printf("%d\n", st.c[1]);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2172539   2010-04-22 00:33:23     Accepted    3324    C++     330     2560    watashi@Zodiac

// 2012-09-07 02:08:03 | Accepted | 3324 | C++ | 290 | 2564 | watashi | Source

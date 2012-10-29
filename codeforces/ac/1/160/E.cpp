#include <set>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;
const int INF = 1000000007;

struct Bus {
    int s, f, t;
    bool operator<(const Bus& o) const { return s < o.s; }
} b[MAXN];

struct Citizen {
    int l, r, b, i;
    bool operator<(const Citizen& o) const { return l < o.l; }
} c[MAXN];

struct SegTree {
    int n;
    set<int> st[MAXN + MAXN];

    static int L(int i) { return i << 1; }
    static int R(int i) { return L(i) ^ 1; }

    void init(int m) {
        n = 1;
        while (n < m) {
            n <<= 1;
        }
        fill(st, st + n + n, set<int>({INF}));
    }

    void add(int i, int t) {
        // printf("A %d %d\n", i, t);
        i += n;
        while (i > 0) {
            st[i].insert(t);
            i >>= 1;
        }
    }

    int query(int p, int pl, int pr, int l, int r, int t) {
        if (pl == l && pr == r) {
            return *st[p].lower_bound(t);
        } else {
            int pm = (pl + pr) / 2;
            if (r <= pm) {
                return query(L(p), pl, pm, l, r, t);
            } else if (pm <= l) {
                return query(R(p), pm, pr, l, r, t);
            } else {
                return min(query(L(p), pl, pm, l, pm, t), query(R(p), pm, pr, pm, r, t));
            }
        }
    }

    int query(int i, int t) {
        // printf("Q %d %d\n", i, t);
        return query(1, 0, n, i, n, t);
    }
} st;

int ans[MAXN];

int main() {
    int n, m, z;
    map<int, int> mpf, mpt;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &b[i].s, &b[i].f, &b[i].t);
        mpf[b[i].f];
        mpt[b[i].t] = i;
    }
    mpf[INF];
    z = 0;
    for (auto& p: mpf) {
        p.second = z++;
    }
    for (int i = 0; i < n; ++i) {
        b[i].f = mpf[b[i].f];
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &c[i].l, &c[i].r, &c[i].b);
        c[i].i = i;
    }
    sort(b, b + n);
    sort(c, c + m);
    z = (int)mpf.size();
    st.init(z);

    for (int i = 0, j = 0; i < m; ++i) {
        while (j < n && b[j].s <= c[i].l) {
            st.add(b[j].f, b[j].t);
            ++j;
        }
        ans[c[i].i] = st.query(mpf.lower_bound(c[i].r)->second, c[i].b);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d ", ans[i] == INF ? -1 : mpt[ans[i]] + 1);
    }

    return 0;
}


#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;

int a[MAXN];
vector<int> b[MAXN];

struct Query {
    int l, r, i, j;
} q[MAXN];

struct SegTree {
    int n, a[MAXN + MAXN];

    static int L(int i) { return i << 1; }
    static int R(int i) { return L(i) ^ 1; }

    void init(int m) {
        n = 1;
        while (n < m) {
            n <<= 1;
        }
        fill(a, a + n + n, 0);
    }

    void add(int p, int pl, int pr, int l, int r, int x) {
        if (l == pl && r == pr) {
            a[p] += x;
        } else {
            int pm = (pl + pr) / 2;
            if (r <= pm) {
                add(L(p), pl, pm, l, r, x);
            } else if (pm <= l) {
                add(R(p), pm, pr, l, r, x);
            } else {
                add(L(p), pl, pm, l, pm, x);
                add(R(p), pm, pr, pm, r, x);
            }
        }
    }

    int get(int i) {
        int ret = 0;
        i += n;
        while (i > 0) {
            ret += a[i];
            i >>= 1;
        }
        return ret;
    }
} st;

int main() {
    int n, m;
    vector<Query> op;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        b[i].push_back(-1);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] <= n) {
            b[a[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        b[i].push_back(n);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j + i < (int)b[i].size(); ++j) {
            op.push_back({b[i][j + i - 1] + 1, b[i][j + i] + 1, b[i][j - 1] + 1, 1});
            op.push_back({b[i][j + i - 1] + 1, b[i][j + i] + 1, b[i][j] + 1, -1});
        }
    }
    sort(op.begin(), op.end(), [](const Query& lhs, const Query& rhs) { return lhs.i > rhs.i; });
    /*
    for (auto i: op) {
        printf("@%d: [%d, %d) %+d\n", i.i, i.l, i.r, i.j);
    }
    */

    for (int i = 0; i < m; ++i) {
        q[i].i = i;
        scanf("%d%d", &q[i].l, &q[i].r);
        --q[i].l;
    }
    sort(q, q + m, [](const Query& lhs, const Query& rhs) { return lhs.l < rhs.l; });

    st.init(n + 5);
    for (int i = 0; i < m; ++i) {
        while (!op.empty() && op.back().i <= q[i].l) {
            st.add(1, 0, st.n, op.back().l, op.back().r, op.back().j);
            op.pop_back();
        }
        q[i].j = st.get(q[i].r);
    }
    sort(q, q + m, [](const Query& lhs, const Query& rhs) { return lhs.i < rhs.i; });
    for (int i = 0; i < m; ++i) {
        printf("%d\n", q[i].j);
    }

    return 0;
}


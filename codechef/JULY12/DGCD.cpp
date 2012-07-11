#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int MAXM = 16;
const int MAXN = 1 << MAXM;

// Segment Tree
struct SegTree {
    int n, *g, *a, *b;

    static int L(int i) {
        return i << 1;
    }

    static int R(int i) {
        return L(i) ^ 1;
    }

    void init(int m) {
        n = 1;
        while (n < m) {
            n <<= 1;
        }
        g = new int[n + n];
        a = new int[n + n];
        b = new int[n + n];
        fill(g + 1, g + n + n, 0);
        fill(a + 1, a + n + n, 0);
        fill(b + 1, b + n + n, 0);
    }

    void dump_(int p) {
        a[L(p)] += a[p];
        b[L(p)] += a[p];
        a[R(p)] += a[p];
        b[R(p)] += a[p];
        a[p] = 0;
    }

    void upd_(int p) {
        b[p] = min(b[L(p)], b[R(p)]) + a[p];
        g[p] = ::gcd(abs(b[L(p)] - b[R(p)]), ::gcd(g[L(p)], g[R(p)]));
    }

    void add(int p, int pl, int pr, int l, int r, int d) {
        if (pl == l && pr == r) {
            a[p] += d;
            b[p] += d;
        } else {
            int pm = (pl + pr) / 2;
            dump_(p);
            if (r <= pm) {
                add(L(p), pl, pm, l, r, d);
            } else if (pm <= l) {
                add(R(p), pm, pr, l, r, d);
            } else {
                add(L(p), pl, pm, l, pm, d);
                add(R(p), pm, pr, pm, r, d);
            }
            upd_(p);
        }
    }

    void add(int l, int r, int d) {
        // printf("\tst::add(%d, %d, %d)\n", l, r, d);
        add(1, 0, n, l, r, d);
    }

    int gcd(int p, int pl, int pr, int l, int r) {
        if (pl == l && pr == r) {
            return ::gcd(b[p], g[p]);
        } else {
            int pm = (pl + pr) / 2;
            int ret;
            dump_(p);
            if (r <= pm) {
                ret = gcd(L(p), pl, pm, l, r);
            } else if (pm <= l) {
                ret = gcd(R(p), pm, pr, l, r);
            } else {
                ret = ::gcd(
                    gcd(L(p), pl, pm, l, pm),
                    gcd(R(p), pm, pr, pm, r));
            }
            upd_(p);
            return ret;
        }
    }

    int gcd(int l, int r) {
        // printf("\tst:gcd(%d, %d)\n", l, r);
        return gcd(1, 0, n, l, r);
    }
} st[MAXN];

// Heavy-Light Decomposition
struct TreeDecomposition {
    vector<int> e[MAXN], c[MAXN];
    int s[MAXN];    // subtree size
    int p[MAXN];    // parent id
    int r[MAXN];    // chain root id
    int t[MAXN];    // timestamp, index used in segtree
    int ts;

    void dfs_(int v, int f) {
        p[v] = f;
        s[v] = 1;
        for (int i = 0; i < (int)e[v].size(); ++i) {
            int w = e[v][i];
            if (w != f) {
                dfs_(w, v);
                s[v] += s[w];
            }
        }
    }

    void decomp_(int v, int f, int k) {
        t[v] = ts++;
        c[k].push_back(v);
        r[v] = k;

        int x = 0, y = -1;
        for (int i = 0; i < (int)e[v].size(); ++i) {
            int w = e[v][i];
            if (w != f) {
                if (s[w] > x) {
                    x = s[w];
                    y = w;
                }
            }
        }
        if (y != -1) {
            decomp_(y, v, k);
        }

        for (int i = 0; i < (int)e[v].size(); ++i) {
            int w = e[v][i];
            if (w != f && w != y) {
                decomp_(w, v, w);
            }
        }
    }

    void init(int n, vector<int> e[MAXN]) {
        copy(e, e + n, this->e);
        ts = 0;
        dfs_(0, 0);
        decomp_(0, 0, 0);
    }
} hld;

// LCA
struct LCA {
    vector<int> e[MAXN];
    int d[MAXN], p[MAXN][MAXM];

    void dfs_(int v, int f) {
        p[v][0] = f;
        for (int i = 1; i < MAXM; ++i) {
            p[v][i] = p[p[v][i - 1]][i - 1];
        }
        for (int i = 0; i < (int)e[v].size(); ++i) {
            int w = e[v][i];
            if (w != f) {
                d[w] = d[v] + 1;
                dfs_(w, v);
            }
        }
    }

    void init(int n, vector<int> e[MAXN]) {
        copy(e, e + n, this->e);
        d[0] = 0;
        dfs_(0, 0);
    }

    int up_(int v, int m) {
        for (int i = 0; i < MAXM; ++i) {
            if (m & (1 << i)) {
                v = p[v][i];
            }
        }
        return v;
    }

    int lca(int a, int b) {
        if (d[a] > d[b]) {
            swap(a, b);
        }
        b = up_(b, d[b] - d[a]);
        if (a == b) {
            return a;
        } else {
            for (int i = MAXM - 1; i >= 0; --i) {
                if (p[a][i] != p[b][i]) {
                    a = p[a][i];
                    b = p[b][i];
                }
            }
            return p[a][0];
        }
    }
} lca;

vector<int> e[MAXN];

int stgcd(int a, int b) {
    int r = hld.r[a];
    return st[r].gcd(hld.t[a] - hld.t[r], hld.t[b] - hld.t[r] + 1);
}

void stadd(int a, int b, int d) {
    int r = hld.r[a];
    st[r].add(hld.t[a] - hld.t[r], hld.t[b] - hld.t[r] + 1, d);
}

int gao(int a, int b) {
    int ret = 0;
    // printf("gao(%d, %d)", a, b);
    while (true) {
        int c = hld.r[a] == hld.r[b] ? b : hld.r[a];
        // printf("[%d, %d] ==> [%d, %d]\n", c, a, hld.t[c], hld.t[a]);
        ret = ::gcd(ret, stgcd(c, a));
        if (c == b) {
            break;
        } else {
            a = hld.p[c];
        }
    }
    // printf(" = %d\n", ret);
    return ret;
}

void add(int a, int b, int d) {
    // printf("add(%d, %d, %d)\n", a, b, d);
    while (true) {
        int c = hld.r[a] == hld.r[b] ? b : hld.r[a];
        stadd(c, a, d);
        if (c == b) {
            break;
        } else {
            a = hld.p[c];
        }
    }
}

int main() {
    int n, m, a, b, c, d;
    char op;

    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }

    hld.init(n, e);
    lca.init(n, e);
    /*
    for (int i = 0; i < n; ++i) {
        printf("\t%d\t%d\t%d\n", i, hld.r[i], hld.t[i]);
    }
    */
    for (int i = 0; i < n; ++i) {
        if (i == hld.r[i]) {
            st[i].init(hld.c[i].size());
        }
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &d);
        stadd(i, i, d);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf(" %c%d%d", &op, &a, &b);
        c = lca.lca(a, b);
        // printf("LCA(%d, %d) = %d\n", a, b, c);
        if (op == 'F') {
            if (a == c) {
                printf("%d\n", gao(b, c));
            } else if (b == c) {
                printf("%d\n", gao(a, c));
            } else {
                printf("%d\n", ::gcd(gao(a, c), gao(b, c)));
            }
        } else {
            scanf("%d", &d);
            if (a == c) {
                add(b, c, d);
            } else if (b == c) {
                add(a, c, d);
            } else {
                add(a, c, d);
                add(b, c, d);
                stadd(c, c, -d);
            }
        }
    }

    return 0;
}

//Correct Answer
//Execution Time: 17.80


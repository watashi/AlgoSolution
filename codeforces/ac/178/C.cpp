#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 18;
const int INF = 1000000007;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int ord[MAXN];
map<int, pair<int, int> > mp;

struct SegTree {
    int m, n;
    int* a;

    static int L(int i) { return i << 1; }
    static int R(int i) { return L(i) ^ 1; }

    void init(int m) {
        this->m = m;
        n = 1;
        while (n < m) {
            n <<= 1;
        }
        a = new int[n + n];
        for (int i = 0; i < m; ++i) {
            a[n + i] = i;
        }
        for (int i = m; i < n; ++i) {
            a[n + i] = INF;
        }
        for (int i = n - 1; i > 0; --i) {
            a[i] = min(a[L(i)], a[R(i)]);
        }
    }

    void upd(int i, bool reset) {
        a[n + i] = reset ? i : INF;
        i += n;
        while (i > 1) {
            i >>= 1;
            a[i] = min(a[L(i)], a[R(i)]);
        }
    }

    int find(int p, int pl, int pr, int l, int r) {
        if (pl == l && pr == r) {
            return a[p];
        } else {
            int pm = (pl + pr) / 2;
            if (r <= pm) {
                return find(L(p), pl, pm, l, r);
            } else if (pm <= l) {
                return find(R(p), pm, pr, l, r);
            } else {
                return min(find(L(p), pl, pm, l, pm), find(R(p), pm, pr, pm, r));
            }
        }
    }

    int insert(int& i) {
        int ret = 0;
        int k = find(1, 0, n, i, n);
        if (k < INF) {
            ret += k - i;
        } else {
            ret += m - i;
            k = find(1, 0, n, 0, n);
            ret += k;
        }
        upd(k, false);
        i = k;
        return ret;
    }

    void erase(int i) {
        upd(i, true);
    }
} st[MAXN];

int main() {
    int n, m, g, q, x, y, z;
    char op;
    long long ans = 0;

    scanf("%d%d%d", &n, &m, &q);
    g = gcd(n, m);
    ord[0] = 0;
    for (int i = 1, j = m % n; j != 0; ++i, j = (j + m) % n) {
        // printf("ord[%d] = %d\n", j / g, i);
        ord[j / g] = i;
    }
    for (int i = 0; i < g; ++i) {
        st[i].init(n / g);
    }

    for (int i = 0; i < q; ++i) {
        scanf(" %c%d", &op, &x);
        if (op == '+') {
            scanf("%d", &y);
            z = y / g;
            y = y % g;
            // printf("[%d,%d,%d] %I64d\n", y, z, ord[z], ans);
            z = ord[z];
            ans += st[y].insert(z);
            // printf("\t[%d,%d] %I64d\n", y, z, ans);
            mp[x] = make_pair(y, z);
        } else {
            y = mp[x].first;
            z = mp[x].second;
            st[y].erase(z);
            mp.erase(x);
        }
    }
    printf("%I64d\n", ans);

    return 0;
}


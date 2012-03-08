#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;

vector<int> lucky;

void gen(int n, int m) {
	lucky.push_back(m);
	if (n > 0) {
		gen(n - 1, m * 10 + 4);
		gen(n - 1, m * 10 + 7);
	}
}

void init() {
	lucky.clear();
	gen(6, 0);
	sort(lucky.begin(), lucky.end());
    for (int i = (int)lucky.size() - 1; i > 0; --i) {
        lucky[i] -= lucky[i - 1];
    }
}

struct SegTree {
    const int *d[MAXN];
    int n, a[MAXN << 1], b[MAXN << 1], c[MAXN << 1];

    static int L(int i) { return i << 1; }
    static int R(int i) { return L(i) ^ 1; }

    void init(int m) {
        n = 1;
        while (n < m) {
            n <<= 1;
        }
        fill(a, a + n + n, lucky[0]);
        fill(b, b + n + n, lucky[0]);
        fill(c, c + n + n, 0);
        fill(d, d + n, &lucky[1]);
    }

    void add(int p, int pl, int pr, int l, int r, int x) {
        if (pl == l && pr == r) {
            a[p] -= x;
            b[p] -= x;
            c[p] = 0;
        } else {
            int pm = (pl + pr) / 2;
            if (c[p] == 0) {
                c[L(p)] = c[R(p)] = 0;
            }
            if (r <= pm) {
                add(L(p), pl, pm, l, r, x);
            } else if (pm <= l) {
                add(R(p), pm, pr, l, r, x);
            } else {
                add(L(p), pl, pm, l, pm, x);
                add(R(p), pm, pr, pm, r, x);
            }
            b[p] = a[p] + min(b[L(p)], b[R(p)]);
            c[p] = c[L(p)] + c[R(p)];
        }
    }

    void add(int l, int r, int x) {
        add(1, 0, n, l, r, x);
    }

    void upd(int p, int pl, int pr, int x) {
        if (b[p] + x <= 0) {
            if (pr - pl == 1) {
                while (a[p] + x < 0) {
                    a[p] += *d[pl]++;
                }
                if (a[p] + x == 0) {
                    a[p] += *d[pl]++;
                    c[p] = 1;
                } else {
                    c[p] = 0;
                }
                b[p] = a[p];
            } else {
                int pm = (pl + pr) >> 1;
                if (c[p] == 0) {
                    c[L(p)] = c[R(p)] = 0;
                }
                upd(L(p), pl, pm, x + a[p]);
                upd(R(p), pm, pr, x + a[p]);
                b[p] = a[p] + min(b[L(p)], b[R(p)]);
                c[p] = c[L(p)] + c[R(p)];
            }
        }
    }

    int cnt(int p, int pl, int pr, int l, int r) const {
        if (c[p] == 0 || (pl == l && pr == r)) {
            return c[p];
        } else {
            int pm = (pl + pr) >> 1, ret = 0;
            if (l < pm) {
                ret += cnt(L(p), pl, pm, l, min(r, pm));
            }
            if (pm < r) {
                ret += cnt(R(p), pm, pr, max(l, pm), r);
            }
            return ret;
        }
    }

    int cnt(int l, int r) {
        upd(1, 0, n, 0);
        return cnt(1, 0, n, l, r);
    }
} st;

int main() {
    int n, m, a, b, c;
    char op[80];

    init();
    scanf("%d%d", &n, &m);
    st.init(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c);
        st.add(i, i + 1, c);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s%d%d", op, &a, &b);
        --a;
        if (op[0] == 'a') {
            scanf("%d", &c);
            st.add(a, b, c);
        } else {
            printf("%d\n", st.cnt(a, b));
        }
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1159691 	Feb 9, 2012 5:28:20 PM 	watashi 	121E - Lucky Array 	GNU C++0x 	Accepted 	390 ms 	5000 KB

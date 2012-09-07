#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1 << 14;

inline int L(int i) { return i << 1; }

inline int R(int i) { return L(i) ^ 1; }

struct SegTree {
    int m, a[MAXN << 1];

    void init(int n) {
        m = 1;
        while (m < n) {
            m <<= 1;
        }
        fill(a + m, a + m + m, 1);
        for (int i = m - 1; i > 0; --i) {
            a[i] = a[L(i)] + a[R(i)];
        }
    }

    void del(int p, int pl, int pr, int l, int r) {
        if (pl == l && pr == r) {
            a[p] = 0;
        } else {
            int pm = (pl + pr) / 2;
            if (r <= pm) {
                del(L(p), pl, pm, l, r);
            } else if (pm <= l) {
                del(R(p), pm, pr, l, r);
            } else {
                del(L(p), pl, pm, l, pm);
                del(R(p), pm, pr, pm, r);
            }
            a[p] = a[L(p)] + a[R(p)];
        }
    }

    void del(int l, int r) {
        if (l == r) {
            return;
        }
        del(1, 0, m, l, r);
    }

    int sum(int p, int pl, int pr, int l, int r) {
        if (a[p] == 0 || (pl == l && pr == r)) {
            return a[p];
        } else {
            int pm = (pl + pr) / 2;
            if (r <= pm) {
                return sum(L(p), pl, pm, l, r);
            } else if (pm <= l) {
                return sum(R(p), pm, pr, l, r);
            } else {
                return sum(L(p), pl, pm, l, pm) + sum(R(p), pm, pr, pm, r);
            }
        }
    }

    int sum(int l, int r) {
        return sum(1, 0, m, l, r);
    }
} st;

pair<int, PII> cut[MAXN];

int main() {
    int n, m, ans;

    while (scanf("%d%d", &n, &m) != EOF) {
        st.init(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &cut[i].second.first, &cut[i].second.second);
            --cut[i].second.first;
            --cut[i].second.second;
            if (cut[i].second.first > cut[i].second.second) {
                swap(cut[i].second.first, cut[i].second.second);
            }
            cut[i].first = cut[i].second.second - cut[i].second.first;
            if (cut[i].first + cut[i].first > n) {
                cut[i].first = n - cut[i].first;
                swap(cut[i].second.first, cut[i].second.second);
            }
        }

        ans = 0;
        sort(cut, cut + m);
        for (int i = 0; i < m; ++i) {
            // printf("DO [%d, %d] %d\n", cut[i].second.first, cut[i].second.second, cut[i].first);
            if (cut[i].second.first > cut[i].second.second) {
                ans = max(ans, st.sum(cut[i].second.first, n) + st.sum(0, cut[i].second.second + 1));
                st.del(cut[i].second.first + 1, n);
                st.del(0, cut[i].second.second);
            } else {
                ans = max(ans, st.sum(cut[i].second.first, cut[i].second.second + 1));
                st.del(cut[i].second.first + 1, cut[i].second.second);
            }
        }
        ans = max(ans, st.sum(0, n));
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//753   2010-07-18 20:59:38     Accepted    1093    C++     40  500     anotherpeg  Source

// 2012-09-07 16:03:37 | Accepted | 3511 | C++ | 20 | 500 | watashi | Source

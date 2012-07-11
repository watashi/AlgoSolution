#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 19;

struct SegTree {
    int n, s[MAXN + MAXN];

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
        fill(s + 1, s + n + n, 0);
    }

    void add(int i, int d) {
        i += n;
        while (i > 0) {
            s[i] += d;
            i >>= 1;
        }
    }

    int sum(int p, int pl, int pr, int m) {
        if (m <= pl) {
            return 0;
        } else if (pr <= m) {
            return s[p];
        } else {
            int pm = (pl + pr) / 2;
            return sum(L(p), pl, pm, m) + sum(R(p), pm, pr, m);
        }
    }

    int sum(int m) {
        return sum(1, 0, n, m);
    }
} st;

int a[MAXN], p[MAXN];
long long ans;

int main() {
    int re, n, d, m;
    map<int, int> mp;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &d);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            mp[a[i]];
            mp[a[i] + d];
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
        }

        m = 0;
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            it->second = m++;
        }
        st.init(m);

        ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += st.sum(mp[a[i]]) * (100 - p[i]);
            ans += st.sum(mp[a[i] + d]) * p[i];
            st.add(mp[a[i]], 100 - p[i]);
            st.add(mp[a[i] + d], p[i]);
        }
        printf("%.4lf\n", ans / 10000.0);
    }

    return 0;
}

//Correct Answer
//Execution Time: 17.25


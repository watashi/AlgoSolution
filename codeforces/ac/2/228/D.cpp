#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXZ = 7;

struct SegmentTree {
    int n;
    long long *s;

    static int L(int i) { return i << 1; }
    static int R(int i) { return L(i) ^ 1; }

    void init(int m) {
        n = 1;
        while (n < m) {
            n <<= 1;
        }
        s = new long long[n + n];
        fill(s, s + n + n, 0);
    }

    void set(int p, int v) {
        p += n;
        v -= s[p];
        while (p > 0) {
            s[p] += v;
            p >>= 1;
        }
    }

    long long get(int p, int pl, int pr, int l, int r) {
        l = max(l, pl);
        r = min(r, pr);
        if (l >= r) {
            return 0;
        } else if (pl == l && pr == r) {
            return s[p];
        } else {
            int pm = (pl + pr) / 2;
            return get(L(p), pl, pm, l, r) + get(R(p), pm, pr, l, r);
        }
    }

    long long get(int l, int r) {
        return get(1, 0, n, l, r);
    }
} st[MAXZ][MAXZ * 2];

inline int mz(int z) {
    return 2 * (z - 1);
}

inline int siz(int i, int z) {
    int r = i % mz(z);
    if (r == 0) {
        return 2;
    } else if (r <= z) {
        return r;
    } else {
        return 2 * z - r;
    }
}

inline int idx(int i, int j, int z) {
    return (i - j + mz(z) - 1) / mz(z);
}

int main() {
    int n, m, t, l, r, z;
    long long ans;

    scanf("%d", &n);
    for (int i = 2; i < MAXZ; ++i) {
        for (int j = 0; j < mz(i); ++j) {
            st[i][j].init(n / mz(i) + 2);
        }
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &z);
        for (int j = 2; j < MAXZ; ++j) {
            st[j][i % mz(j)].set(i / mz(j), z);
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1) {
            for (int j = 2; j < MAXZ; ++j) {
                st[j][l % mz(j)].set(l / mz(j), r);
            }
        } else {
            scanf("%d", &z);
            ans = 0;
            ++r;
            for (int j = 0; j < mz(z); ++j) {
                ans += siz((j - l % mz(z) + 1 + mz(z)) % mz(z), z) * st[z][j].get(idx(l, j, z), idx(r, j, z));
            }
            printf("%I64d\n", ans);
        }
    }

    return 0;
}


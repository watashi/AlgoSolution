#include <cstdio>

// |a b|
// |c d|

struct LT {
    int a, b, c, d;
};

const int MAXN = 32768;
const LT e = {1, 0, 0, 1};

int R;
LT a[MAXN << 1];

#define L(i) ((i) << 1)
#define R(i) (L(i) ^ 1)

inline void product(const LT& lhs, const LT& rhs, LT& ret) {
    ret.a = (lhs.a * rhs.a + lhs.b * rhs.c) % R;
    ret.b = (lhs.a * rhs.b + lhs.b * rhs.d) % R;
    ret.c = (lhs.c * rhs.a + lhs.d * rhs.c) % R;
    ret.d = (lhs.c * rhs.b + lhs.d * rhs.d) % R;
}

LT gao(int p, int pl, int pr, int l, int r) {
    if (l == pl && r == pr) {
        return a[p];
    } else {
        int pm = (pl + pr) >> 1;
        if (r <= pm) {
            return gao(L(p), pl, pm, l, r);
        } else if (pm <= l) {
            return gao(R(p), pm, pr, l, r);
        } else {
            LT ret;
            product(gao(L(p), pl, pm, l, pm), gao(R(p), pm, pr, pm, r), ret);
            return ret;
        }
    }
}

int main() {
    int n, m, s, l, r;
    bool blank = false;
    LT ans;

    while (scanf("%d%d%d", &R, &n, &m) != EOF) {
        s = 1;
        while (s < n) {
            s <<= 1;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &a[s + i].a, &a[s + i].b, &a[s + i].c, &a[s + i].d);
        }
        for (int i = s - 1; i >= 1; --i) {
            product(a[L(i)], a[R(i)], a[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &l, &r);
            ans = gao(1, 0, s, l - 1, r);
            if (blank) {
                putchar('\n');
            } else {
                blank = true;
            }
            printf("%d %d\n%d %d\n", ans.a, ans.b, ans.c, ans.d);
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1974083   2009-08-19 00:47:16     Accepted    2671    C++     670     1200    watashi@Zodiac
/*
Submit Time     Language    Run Time(ms)    Run Memory(KB)      User Name
2009-08-19 00:47:16     C++     670     1200    watashi@Zodiac
2009-02-07 15:47:31     C++     720     3928    HyperHexagon
2009-04-03 18:06:50     C++     740     2060    asmn@Runic
2009-07-20 15:19:14     C++     880     4160    pkkj
2009-03-30 22:32:58     C++     900     2060    LZOI_LCLL
2009-08-02 14:50:15     C++     920     4396    joey2005
2009-02-04 22:56:50     C++     1030    8368    davidsun
2009-04-08 13:17:44     C++     1530    7684    macs
2006-03-11 19:50:05     C++     1710    2440    foolman
2006-03-17 19:57:53     FPC     1770    4332    SpeedStar
*/

// 2012-09-07 15:42:55 | Accepted | 2671 | C++ | 640 | 1204 | watashi | Source

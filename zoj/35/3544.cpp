#include <cstdlib> // auto fix CE
#include <cmath> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <cmath> // auto fix CE
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

const int MAXR = 218;
const int MAXC = 100860;
const int MAXQ = 100860;

struct List {
    int n;
    bool t[MAXC];
    int r[MAXC];

    void init(int m) {
        n = m;
        fill(t, t + n + 1, true);
        for (int i = 0; i < n; ++i) {
            r[i] = i + 1;
        }
    }

    int getr(int i) {
        return t[i] ? i : (r[i] = getr(r[i]));
    }

    int erase(int begin, int end) {
        int ret = 0;

        begin = max(begin, 0);
        end = min(end, n);
        begin = getr(begin);
        while (begin < end) {
            ++ret;
            t[begin] = false;
            begin = getr(begin);
        }

        return ret;
    }
} lst[MAXR];

inline int sqr(int x) {
    return x * x;
}

inline int isqrt(long long x) {
    long long l = 0, r = MAXC, m;

    while (l < r) {
        m = (l + r) / 2;
        if (m * m <= x) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return r - 1;
}

struct Op {
    char op;
    int x, y, r, c, t;

    void init() {
        scanf(" %c%*s%d%d%d%d", &op, &x, &y, &r, &t);
        if (op == 'R') {
            scanf("%d", &c);
        }
    }

    void gao(int n, int m, int ans[]) {
        if (op == 'C') {
            for (int i = max(0, x - r); i < min(n, x + r + 1); ++i) {
                c = isqrt(1LL * r * r - sqr(i - x));
                ans[t] += lst[i].erase(y - c, y + c + 1);
            }
        } else if (op == 'D') {
            for (int i = max(0, x - r); i < min(n, x + r + 1); ++i) {
                c = r - abs(i - x);
                ans[t] += lst[i].erase(y - c, y + c + 1);
            }
        } else if (op == 'R') {
            swap(c, t);
            for (int i = max(0, x); i < min(n, x + r); ++i) {
                ans[t] += lst[i].erase(y, y + c);
            }
        } else if (op == 'T') {
            r = (r - 1) / 2;
            for (int i = max(0, x); i < min(n, x + r + 1); ++i) {
                c = r - (i - x);
                ans[t] += lst[i].erase(y - c, y + c + 1);
            }
        }
    }
} op[MAXQ];

int main() {
    int n, m, q, ans[10];

    while (scanf("%d%d%d", &n, &m, &q) != EOF) {
        for (int i = 0; i < n; ++i) {
            lst[i].init(m);
        }
        for (int i = 0; i < q; ++i) {
            op[i].init();
        }

        fill(ans, ans + 10, 0);
        for (int i = q - 1; i >= 0; --i) {
            op[i].gao(n, m, ans);
        }
        for (int i = 1; i <= 9; ++i) {
            printf("%d%c", ans[i], i == 9 ? '\n' : ' ');
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2675329   2011-10-02 20:09:54     Accepted    3544    C++     2190    109904  watashi     Source

// 2012-09-07 16:05:02 | Accepted | 3544 | C++ | 2130 | 109904 | watashi | Source

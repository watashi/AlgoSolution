#include <algorithm> // auto fix CE
#include <queue>
#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cassert>

using namespace std;

int d[128];
int a[128][64];

struct HSN {
    int h, s, n, t;
} init;

inline HSN beigao(HSN hsn) {
    if (hsn.n > 0) {
        hsn.h -= hsn.n;
        if (hsn.h > 0) {
            hsn.s += hsn.n % 3;
            hsn.s = min(hsn.s, init.s);
        }
    }
    return hsn;
}

HSN gao1(HSN hsn) {
    --hsn.n;
    hsn.s = min(hsn.s + 1, init.s);
    return beigao(hsn);
}

HSN gao2(HSN hsn) {
    hsn.h = min(hsn.h + init.h / 5, init.h);
    return beigao(hsn);
}

HSN gao3(HSN hsn) {
    if (hsn.s > 0) {
        hsn.n -= d[hsn.s];
        hsn.s = 0;
    }
    return beigao(hsn);
}

typedef HSN GAO(HSN);

GAO* const gao[] = {gao1, gao2, gao3};

int main() {
    HSN x, y;

    while (scanf("%d%d%d", &init.h, &init.s, &init.n) != EOF) {
        d[0] = 0;
        for (int i = 1; i <= init.s; ++i) {
            scanf("%d", &d[i]);
        }
        for (int i = 0; i <= init.s; ++i) {
            for (int j = 0; j <= init.n; ++j) {
                a[i][j] = 0;
            }
        }

        queue<HSN> q;
        x = init;
        x.s = 0;
        x.t = 0;
        a[x.s][x.n] = x.h;
        q.push(x);
        try {
            while (!q.empty()) {
                x = q.front();
                q.pop();
                for (int i = 0; i < 3; ++i) {
                    y = gao[i](x);
                    if (y.h > 0 && y.n <= 0) {
                        throw x.t + 1;
                    } else if (a[y.s][y.n] < y.h) {
                        y.t = x.t + 1;
                        a[y.s][y.n] = y.h;
                        q.push(y);
                    }
                }
            }
            puts("HELP!");
        } catch (int ans) {
            printf("%d\n", ans);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//642   2010-12-24 21:38:54     Accepted    B   C++     350     8640    watashi@Zodiac  Source

// after optimization
//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//646   2010-12-24 21:57:49     Accepted    B   C++     10  212     watashi@Zodiac  Source

// 2012-09-07 15:56:53 | Accepted | 3446 | C++ | 10 | 212 | watashi | Source

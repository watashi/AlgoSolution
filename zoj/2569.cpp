#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXP = 16;
const int MAXT = 20;

inline int ceil(int a, int b) { return (a + b - 1) / b; }

int main() {
    int m, n, t, l, r, rr;
    int I[MAXP], A[MAXP], L[MAXP], O[MAXP], T[MAXT], Z[MAXT], V[MAXT], C[MAXT];
    bool p[MAXP], q[MAXP];
    pair<int, int> x[MAXT][MAXP];
    pair<pair<int, int>, int> y[MAXT], z;

    while (scanf("%d%d%d%d", &m, &n, &t, &l) != EOF) {
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d%d", &I[i], &A[i], &L[i], &O[i]);
        }
        for (int i = 0; i < t; ++i) {
            scanf("%d%d%d%d", &T[i], &Z[i], &V[i], &C[i]);
        }
        fill(p, p + (m - n), false);
        fill(p + (m - n), p + m, true);
        r = t;
        do {
            for (int i = 0, k = 0; i < m; ++i) {
                if (!p[i]) {
                    continue;
                }
                for (int j = 0; j < t; ++j) {
                    x[j][k].first = ceil(I[i], O[i]) + max(ceil(A[i], C[j]), 5);
                    x[j][k].second = max(I[i] - T[j], 0) + ceil(A[i], Z[j] + C[j]) + ceil(L[i], V[j]);
                }
                ++k;
            }
            // assert(k == n);
            for (int j = 0; j < t; ++j) {
                sort(x[j], x[j] + n);
                y[j].first.first = 0;
                y[j].first.second = 0;
                y[j].second = j;
                for (int i = 0, k = 0; i < n && k + x[j][i].second <= l; ++i) {
                    k += x[j][i].second;
                    ++y[j].first.first;
                    y[j].first.second += k;
                }
            }
            z = y[0];
            sort(y, y + t);
            rr = find(y, y + t, z) - y;
            if (r > rr) {
                r = rr;
                copy(p, p + m, q);
            }
        } while (next_permutation(p, p + m));
        bool blank = false;
        for (int i = 0; i < m; ++i) {
            if (q[i]) {
                if (blank) {
                    putchar(' ');
                } else {
                    blank = true;
                }
                printf("%d", i + 1);
            }
        }
        puts("");
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1821057   2009-04-06 16:54:41     Accepted    2569    C++     650     176     watashi@Zodiac

// 2012-09-07 01:29:24 | Accepted | 2569 | C++ | 580 | 180 | watashi | Source

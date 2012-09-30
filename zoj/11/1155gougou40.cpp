#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

inline int bin(int x) {
    return 1 << x;
}

inline bool isbin(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

#define V2E(i, j, k, a) do {\
    v2e[i][j] = v2e[j][i] = a;\
    v2e[i][k] = v2e[k][i] = a + 1;\
    v2e[j][k] = v2e[k][j] = a + 2;\
} while (false)

const int MAXN = 18;

const int tri[] = {
    7, 7 << 3, 7 << 6, 7 << 9, 7 << 12, 7 << 15,
    bin(2) ^ bin(4) ^ bin(6),
    bin(5) ^ bin(10) ^ bin(12),
    bin(8) ^ bin(13) ^ bin(15),
};

int v2e[MAXN][MAXN];
int gao[1 << MAXN];

int newtri(int mask, int b) {
    int ret = 0;
    b = bin(b);
    for (int i = 0; i < (int)(sizeof(tri) / sizeof(tri[0])); ++i) {
        if ((tri[i] & b) == b && (mask & tri[i]) == (tri[i] ^ b)) {
            ++ret;
        }
    }
    return ret;
}

void init() {
    V2E(0, 1, 2, 0);
    V2E(1, 3, 4, 3);
    V2E(2, 4, 5, 6);
    V2E(3, 6, 7, 9);
    V2E(4, 7, 8, 12);
    V2E(5, 8, 9, 15);
    memset(gao, 0x88, sizeof(gao));
    gao[(1 << MAXN) - 1] = 0;
    for (int i = (1 << MAXN) - 1; i >= 0; --i) {
        for (int j = 0; j < MAXN; ++j) {
            if ((i & bin(j)) == 0) {
                int k = newtri(i, j);
                if (k > 0) {
                    gao[i] = max(gao[i], gao[i ^ bin(j)] + k);
                } else {
                    gao[i] = max(gao[i], -gao[i ^ bin(j)]);
                }
            }
        }
    }
}

int main() {
    bool first;
    int re, n, m, x, y, d, mask;

    init();
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        if (ri > 1) {
            puts("");
        }
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &m);
            first = true;
            d = 0;
            mask = 0;
            for (int j = 1; j <= m; ++j) {
                scanf("%d%d", &x, &y);
                --x;
                --y;
                x = v2e[x][y];
                y = newtri(mask, x);
                // fprintf(stderr, "x = %d; y = %d; mask = %o\n", x, y, mask);
                if (y > 0) {
                    d += first ? y : -y;
                } else {
                    first = !first;
                }
                mask |= bin(x);
            }
            // fprintf(stderr, "(d) = %d\n", d);
            d += first ? gao[mask] : -gao[mask];
            // fprintf(stderr, "[d] = %d\n", d);
            printf("Game %d: %c wins.\n", i, d > 0 ? 'A' : 'B');
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//342   2010-06-28 16:49:48     Accepted    1015    C++     160     1204    anotherpeg  Source

// 2012-09-30 23:38:40 | Accepted | 1155 | C++ | 130 | 1204 | watashi | Source

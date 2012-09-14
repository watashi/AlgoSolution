#include <cstdio>
#include <algorithm>

using namespace std;

bool f[1 << 16];
int g[1 << 16];

// ¸´ÔÓ¶ÈO(3^n)
int gao(int mask) {
        if (g[mask] == -1) {
                g[mask] = 0;
                for (int sub = mask; sub != 0; sub = (sub - 1) & mask) {
                        if (f[sub]) {
                                g[mask] = max(g[mask], gao(mask ^ sub) + 1);
                        }
                }
        }
        return g[mask];
}

int main() {
        int n, m, k, a, b;

        while (scanf("%d%d", &n, &m) != EOF) {
                fill(f, f + (1 << n), false);
                fill(g, g + (1 << n), -1);
                for (int i = 0; i < m; ++i) {
                        scanf("%d", &k);
                        b = 0;
                        for (int j = 0; j < k; ++j) {
                                scanf("%d", &a);
                                b |= 1 << (a - 1);
                        }
                        f[b] = true;
                }
                printf("%d\n", gao((1 << n) - 1));
        }

        return 0;
}
// Run ID       Submit Time     Judge Status    Problem ID      Language  Run Time(ms)          Run Memory(KB)          User Name       Admin
// 1343         2009-07-24 21:18:22     Accepted        1060    C++     1620 500        liehuochongsheng        Source

// 2012-09-07 15:46:06 | Accepted | 3305 | C++ | 1160 | 500 | watashi | Source

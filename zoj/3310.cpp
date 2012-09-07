#include <cstdio>
#include <algorithm>

using namespace std;

int a[1 << 20];

long long gao(int n, int a[]) {
        long long x, y, z;
        x = y = 0;
        for (int i = 0; i < n; ++i) {
                z = x;
                x = y;
                y = max(y, z + a[i]);
        }
        return x;
}

int main() {
        int n;

        while (scanf("%d", &n) != EOF) {
                for (int i = 0; i < n; ++i) {
                        scanf("%d", &a[i]);
                }
                if (n == 1) {
                        printf("%d\n", a[0]);
                        continue;
                }
                copy(a, a + 3, a + n);
                printf("%lld\n", max(gao(n, a), max(gao(n, a + 1), gao(n, a + 2))));
        }

        return 0;
}

// Run ID       Submit Time     Judge Status    Problem ID      Language  Run Time(ms)          Run Memory(KB)          User Name       Admin
// 1185         2009-07-21 23:01:08     Accepted        1112    C++     470 4276        liehuochongsheng        Source
// 1184         2009-07-21 23:00:57     Accepted        1112    C++     410 4276        liehuochongsheng        Source
// 1183         2009-07-21 23:00:18     Accepted        1112    C++     440 4276        liehuochongsheng        Source

// 2012-09-07 15:46:37 | Accepted | 3310 | C++ | 190 | 4276 | watashi | Source

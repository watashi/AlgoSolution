#include <cstdio>

int main() {
    int k, si[128], m, l, hi, nim;
    int b[128], sg[10086];

    while (scanf("%d", &k) != EOF && k > 0) {
        for (int i = 0; i < k; ++i) {
            scanf("%d", &si[i]);
            b[i] = -1;
        }
        b[k] = -1;
        for (int i = 0; i <= 10000; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i - si[j] >= 0) {
                    b[sg[i - si[j]]] = i;
                }
            }
            for (int j = 0; j <= k; ++j) {
                if (b[j] != i) {
                    sg[i] = j;
                    break;
                }
            }
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            nim = 0;
            scanf("%d", &l);
            for (int j = 0; j < l; ++j) {
                scanf("%d", &hi);
                nim ^= sg[hi];
            }
            putchar(nim == 0 ? 'L' : 'W');
        }
        putchar('\n');
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1746041   2009-01-21 00:44:34     Accepted    3084    C++     50  176     watashi@Zodiac

// 2012-09-07 02:01:01 | Accepted | 3084 | C++ | 60 | 180 | watashi | Source

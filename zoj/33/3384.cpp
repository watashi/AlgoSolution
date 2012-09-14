#include <algorithm> // auto fix CE
#include <cstdio>

int main() {
    int n;
    int a[1024], b[1024], c;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }
        c = 0;
        for (int i = n - 1; i >= 0; --i) {
            a[i] += c;
            c = (a[i] < b[i]) ? a[i] : b[i];
            a[i] -= c;
            b[i] = c;
            c = a[i];
        }
        if (c == 0) {
            for (int i = 0; i < n; ++i) {
                printf("%d%c", b[i], (i == n - 1) ? '\n' : ' ');
            }
        } else {
            puts("Myon");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//909   2010-07-21 22:15:38     Accepted    1110    C++     10  180     anotherpeg  Source

// 2012-09-07 16:50:10 | Accepted | 3384 | C++ | 0 | 180 | watashi | Source

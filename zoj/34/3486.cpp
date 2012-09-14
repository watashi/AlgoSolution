#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int re, n, a[1 << 10], b, c, d;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        b = 0;
        for (int i = 0; i < n; ++i) {
            c = 0;
            for (int j = 0; j < n; ++j) {
                if (a[i] == a[j]) {
                    ++c;
                }
            }
            if (c > b || (c == b && a[i] > d)) {
                b = c;
                d = a[i];
            }
        }
        printf("%d\n", d);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//221   2011-04-03 01:12:56     Accepted    J   C++     10  180     watashi     Source

// 2012-09-07 16:01:04 | Accepted | 3486 | C++ | 0 | 180 | watashi | Source

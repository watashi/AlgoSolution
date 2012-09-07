#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    char buf[80];
    long long t, wb[5]; // w, b, bw, wb

    while (scanf("%d", &n) != EOF) {
        wb[0] = wb[1] = wb[2] = wb[3] = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s%lld", buf, &t);
            if (buf[1] == '\0' || buf[1] == buf[0]) {
                wb[buf[0] == 'w' ? 0 : 1] += (buf[1] == '\0' ? t: 2 * t);
            } else if (buf[1] == 'w') {
                wb[2] += t; // bw (bottom is white)
            } else {
                wb[3] += t;
            }
            wb[4] = min(wb[0], wb[1]);
            wb[0] -= wb[4];
            wb[1] -= wb[4];
            wb[4] = min(wb[2], wb[3]);
            wb[2] -= wb[4];
            wb[3] -= wb[4];
        }
//      printf("%lld %lld %lld %lld\n", wb[0], wb[1], wb[2], wb[3]);
        printf("%s %s\n",
            wb[0] + (wb[2] + 1) / 2 > wb[1] + wb[3] / 2 ? "win" : "lose",
            wb[0] + wb[2] / 2 >= wb[1] + (wb[3] + 1) / 2 ? "win" : "lose");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//597   2010-12-23 18:52:25     Accepted    H   C++     140     180     watashi@Zodiac  Source

// 2012-09-07 15:57:30 | Accepted | 3452 | C++ | 80 | 180 | watashi | Source

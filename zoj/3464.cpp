#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int re, n, t, l;
    int v[10086];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d", &n, &t, &l);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
        }
        sort(v, v + n);
        reverse(v, v + n);
        for (int i = 0; i < n; ++i) {
            if (l <= v[i] * t) {
                printf("%.2lf\n", i * t + (double)l / v[i]);
                l = -1;
                break;
            } else {
                l -= v[i] * t;
            }
        }
        if (l > 0) {
            puts("-1");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1002  2010-07-24 21:36:47     Accepted    1117    C++     80  180     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//693   2011-01-30 15:37:32     Accepted    H   C++     50  180     watashi@ArcOfDream  Source

// 2012-09-07 15:58:44 | Accepted | 3464 | C++ | 40 | 180 | watashi | Source

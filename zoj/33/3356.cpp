#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int re;
    long long a, b, s, c[3], d[3], e[3], ans;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%lld", &s);
        for (int i = 0; i < 3; ++i) {
            scanf("%lld.%lld", &a, &b);
            c[i] = a * 100 + b;
        }

        ans = 0;
        d[0] = d[1] = d[2] = 0;
        e[0] = e[1] = e[2] = 0;
        for (int i = 1; i <= s; ++i) {
            int k = min_element(e, e + 3) - e;
            // printf("%d %d ", i, k);
            ++d[k];
            e[k] = d[k] * c[k] / 100;
            ans = max(ans, *min_element(e, e + 3) - i);
            // printf(" %lld\n", *min_element(e, e + 3) - i);
        }
        printf("%lld\n", ans + s);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//598   2010-07-16 20:34:08     Accepted    1070    C++     2460    180     anotherpeg  Source

// 2012-09-07 16:50:00 | Accepted | 3356 | C++ | 2010 | 180 | watashi | Source

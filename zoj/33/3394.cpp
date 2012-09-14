#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10086;
int s[MAXN], t[MAXN];

int main() {
    int n, m, a, b;

    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%*d%*d%d%d", &s[i], &t[i]);
            t[i] += s[i];
        }
        sort(s, s + n);
        sort(t, t + n);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            b += a;
            a = upper_bound(t, t + n, a) - t;
            b = s + n - lower_bound(s, s + n, b);
            printf("%d\n", n - a - b);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2377786   2010-12-25 21:22:07     Accepted    3394    C++     60  260     watashi@Zodiac  Source

// 2012-09-07 02:09:04 | Accepted | 3394 | C++ | 80 | 260 | watashi | Source

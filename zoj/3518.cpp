#include <cmath> // auto fix CE
#include <cstdio>
#include <cmath> // auto fix CE
#include <algorithm>
#include <cmath> // auto fix CE
#include <functional>

using namespace std;

bool bs[10001000];

int main() {
    int l, n1, n2, a, b, ans;

    while (scanf("%d%d%d", &l, &n1, &n2) != EOF) {
        n1 += n2;
        fill(bs, bs + l + 1, false);
        for (int i = 0; i < n1; ++i) {
            scanf("%d%d", &a, &b);
            transform(bs + a, bs + b + 1, bs + a, logical_not<bool>());
        }
        ans = 0;
        for (int i = 0; i <= l; ) {
            if (bs[i]) {
                int j = find(bs + i, bs + l + 1, false) - bs;
                ans = max(ans, j - i);
                i = j;
            } else {
                ++i;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//764   2011-06-20 22:42:57     Accepted    I   C++     180     9948    admin   Source

// 2012-09-07 16:04:32 | Accepted | 3518 | C++ | 170 | 9948 | watashi | Source

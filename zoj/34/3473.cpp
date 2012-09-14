#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <numeric>

using namespace std;

const int MAXN = 500500;
int p[MAXN], s[MAXN];

int main() {
    for (long long i = 2; i < MAXN; ++i) {
        if (p[i] != 0) {
            continue;
        }
        for (long long j = i; j < MAXN; j *= i) {
            for (long long k = j; k < MAXN; k += j) {
                ++p[k];
            }
        }
    }
    partial_sum(p, p + MAXN, s);

    long long x, y, z, ans;

    while (scanf("%lld%lld%lld", &x, &y, &z) != EOF) {
        ans = s[z] + z;
        ans = ans * y + s[y] * z;
        ans = ans * x + s[x] * y * z;
        printf("%lld\n", ans);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//612   2010-07-16 21:51:33     Accepted    1087    C++     290     4088    anotherpeg  Source
//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//720   2011-02-11 12:43:13     Accepted    G   C++     170     4088    watashi@ArcOfDream  Source

// 2012-09-07 15:59:39 | Accepted | 3473 | C++ | 140 | 4088 | watashi | Source

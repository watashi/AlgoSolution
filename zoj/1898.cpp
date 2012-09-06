#include <map>
#include <cmath>
#include <cstdio>

using namespace std;

long long pow(long long x, long long y, long long z) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) {
            ret = (ret * x) % z;
        }
        y >>= 1;
        x = (x * x) % z;
    }
    return ret;
}

int main() {
    long long p, b, n, m, r, s;

    while (scanf("%lld%lld%lld", &p, &b, &n) != EOF) {
        m = (long long)sqrt(p + .5) + 1;
        r = pow(b, p - 1 - m % (p - 1), p);
        fprintf(stderr, "%lld %lld\n", m, r);
        map<long long, int> mp;
        s = 1;
        for (int i = 0; i < m; ++i) {
            if (mp.count(s) == 0) {
                mp[s] = i;
            }
            s = s * b % p;
        }
        s = n;
        for (int i = 0; i <= m; ++i) {
            if (i == m) {
                puts("no solution");
                break;
            } else if (mp.count(s) > 0) {
                printf("%lld\n", i * m + mp[s]);
                break;
            }
            s = s * r % p;
        }
    }

    return 0;
}
/*
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
1831675     2009-04-12 22:03:11     Accepted    1898    C++     190     1364    watashi@Zodiac
*/

// 2012-09-07 01:04:54 | Accepted | 1898 | C++ | 180 | 1368 | watashi | Source

#include <utility> // auto fix CE
#include <algorithm> // auto fix CE
#include <utility> // auto fix CE
#include <cstdio>
#include <utility> // auto fix CE
#include <algorithm> // auto fix CE
#include <utility> // auto fix CE
#include <vector>

using namespace std;

const long long MOD = 1000000007LL;

vector<int> p;

long long gao(int n, int x, long long y) {
    if (n == 0) {
        return x > 0 ? y / x : -((-y) / x);
    } else {
        return gao(n - 1, x, y) + gao(n - 1, x * -p[n - 1], y);
    }
}

// count(gcd(x, i) == 1) | i <= y
long long gao(int x, long long y) {
    p.clear();
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            p.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        p.push_back(x);
    }
//  printf("[%d, %lld]: {", x, y);
//  for (int i = 0; i < (int)p.size(); ++i) {
//      printf("%d, ", p[i]);
//  }
//  printf(" } => %lld\n", gao(p.size(), 1, y));
    return gao(p.size(), 1, y);
}

int main() {
    int n, s, t, a;
    long long x, y;

    while (scanf("%d%d%d%lld%lld", &n, &s, &t, &x, &y) != EOF) {
        vector<long long> dp(t + 1, 0);
        dp[0] = 1LL;
        --x;
        for (int i = 0; i < n; ++i) {
            vector<long long> pre(t + 1, 0);
            vector<pair<int, long long> > cnt;
            pre.swap(dp);
            scanf("%d", &a);
            for (int b = 1; b * b <= a; ++b) {
                if (a % b == 0) {
                    int c = a / b;
                    cnt.push_back(make_pair(b, gao(c, y / b) - gao(c, x / b)));
                    if (a / b > b) {
                        cnt.push_back(make_pair(c, gao(b, y / c) - gao(b, x / c)));
                    }
                }
            }
            for (int j = 0; j <= t; ++j) {
                for (int k = 0; k < (int)cnt.size(); ++k) {
                    if (j + cnt[k].first <= t) {
                        dp[j + cnt[k].first] = (dp[j + cnt[k].first] + pre[j] * cnt[k].second) % MOD;
                    }
                }
            }
        }

        long long ans = 0;
        for (int j = s; j <= t; ++j) {
            ans += dp[j];
        }
        printf("%lld\n", ans % MOD);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1285  2010-08-01 18:51:03     Accepted    1157    C++     70  180     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//320   2010-10-05 22:27:15     Accepted    G   C++     220     180     watashi@Zodiac  Source

// 2012-09-07 15:53:14 | Accepted | 3412 | C++ | 210 | 180 | watashi | Source

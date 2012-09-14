#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <cstdio>
#include <cmath> // auto fix CE
#include <algorithm> // auto fix CE
#include <cmath> // auto fix CE
#include <vector>

using namespace std;

const long long MOD = 1000000007LL;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long pow4(long long n) {
    n = n * n % MOD;
    n = n * n % MOD;
    return n;
}

long long sum(long long n) {
    long long a[] = {n, n + 1, 2 * n + 1, 3 * n * n + 3 * n - 1};
    long long b = 30;
    long long c = 1;
    for (int i = 0; i < 4; ++i) {
        long long g = gcd(a[i], b);
        a[i] /= g;
        b /= g;
        c = a[i] % MOD * c % MOD;
    }
    return c;
}

vector<long long> factor(long long n) {
    vector<long long> ret;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            do {
                n /= i;
            } while (n % i == 0);
        }
    }
    if (n > 1) {
        ret.push_back(n);
    }
    return ret;
}

vector<long long> p;

long long gao(long long n, int m, int f) {
    if (n == 0) {
        return 0;
    } else if (m == 0) {
        return f * sum(n);
    } else {
        return gao(n, m - 1, f) + gao(n / p[m - 1], m - 1, -f) * pow4(p[m - 1]) % MOD;
    }
}

int main() {
    int re;
    long long n;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%lld", &n);
        p = factor(n);
        printf("%lld\n", (gao(n, p.size(), 1) % MOD + MOD) % MOD);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2675333   2011-10-02 20:10:37     Accepted    3547    C++     40  180     watashi     Source

// 2012-09-07 16:05:14 | Accepted | 3547 | C++ | 40 | 180 | watashi | Source

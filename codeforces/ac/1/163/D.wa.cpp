#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;

long long p[MAXN];
int a[MAXN];

long long icbrt(long long n) {
    long long m = (long long)cbrt(n) + 1;
    while (m * m * m > n) {
        --m;
    }
    return m;
}

long long isqrt(long long n) {
    long long m = (long long)sqrt(n) + 1;
    while (m * m > n) {
        --m;
    }
    return m;
}

long long gao(int i, long long m, long long n) {
    long long ret = 0;
    if (n <= m) {
        if (i == 0) {
            ret = n;
        } else {
            --i;
            for (int j = 0; j <= a[i]; ++j) {
                ret = max(ret, gao(i, m, n));
                n *= p[i];
            }
        }
    }
    return ret;
}

int main() {
    int re, n;
    long long x, u, v, w;

    cin >> re;
    for (int ri = 1; ri <= re; ++ri) {
        cin >> n;
        x = 1;
        for (int i = 0; i < n; ++i) {
            cin >> p[i] >> a[i];
            for (int j = 0; j < a[i]; ++j) {
                x *= p[i];
            }
        }
        u = gao(n, icbrt(x), 1);
        v = u;
        for (int i = 0; i < n; ++i) {
            while (v % p[i] == 0) {
                v /= p[i];
                --a[i];
            }
        }
        v = x / u;
        v = gao(n, isqrt(v), 1);
        w = x / u / v;
        cout << 2 * (u * v + u * w + v * w)
            << " " << u
            << " " << v
            << " " << w << endl;
    }

    return 0;
}


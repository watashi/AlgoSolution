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

int n;
long long x;
vector<long long> ans;

long long fsqrt(int i, long long m, long long n) {
    long long ret = 0;
    if (n <= m) {
        if (i == 0) {
            ret = n;
        } else {
            --i;
            for (int j = 0; j <= a[i]; ++j) {
                ret = max(ret, fsqrt(i, m, n));
                n *= p[i];
            }
        }
    }
    return ret;
}

void gao(int i, long long m, long long n) {
    if (n <= m) {
        if (i == 0) {
            long long y = x / n;
            long long z = fsqrt(::n, isqrt(y), 1);
            /*
            cout << "n = " << n << " => " << y << " => " << z << endl;
            for (int i = 0; i < ::n; ++i) {
                cout << "[" << p[i] << "]" << a[i] << endl;
            }
            */
            y /= z;
            ans = min<vector<long long> >(ans, {2 * (n * y + n * z + y * z), n, y, z});
        } else {
            --i;
            int b = a[i];
            for (int j = 0; j <= b; ++j) {
                a[i] = b - j;
                gao(i, m, n);
                n *= p[i];
            }
            a[i] = b;
        }
    }
}

int main() {
    int re;

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
        // cout << "fsqrt = " << fsqrt(n, isqrt(x), 1) << endl;
        ans = {2 * (x + x + 1), x, 1, 1};
        gao(n, icbrt(x), 1);
        for (int i = 0; i < 4; ++i) {
            cout << ans[i] << (i == 3 ? "\n" : " ");
        }
    }

    return 0;
}


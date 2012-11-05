#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;

long long p[MAXN];
int a[MAXN], b[MAXN];

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

vector<long long> fs;

long long calc(long long a, long long b, long long c) {
    return a * (b + c) + b * c;
}

int main() {
    int re, n;
    long long x;
    vector<long long> ans;

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
        fs.clear();
        gao(n, icbrt(x), 1);
        sort(fs.rbegin(), fs.rend());
        // cout << fs.size() << endl;
        copy(a, a + n, b);

        ans = {calc(x, 1, 1), x, 1, 1};
        for (long long u: fs) {
            long long vw = x / u, v = isqrt(vw), w = vw / v;
            if (calc(u, v, w) > ans[0]) {
                continue;
            }
            w = u;
            copy(b, b + n, a);
            for (int i = 0; i < n; ++i) {
                while (w % p[i] == 0) {
                    w /= p[i];
                    --a[i];
                }
            }
            v = fsqrt(n, v, 1);
            // cout << "0?" << vw % v << endl;
            w = vw / v;
            ans = min<vector<long long> >(ans, {calc(u, v, w), u, v, w});
        }

        ans[0] *= 2;
        for (int i = 0; i < 4; ++i) {
            cout << ans[i] << (i == 3 ? "\n" : " ");
        }
    }

    return 0;
}

